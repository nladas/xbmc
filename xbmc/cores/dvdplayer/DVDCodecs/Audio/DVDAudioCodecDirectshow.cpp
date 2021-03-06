/*
 *      Copyright (C) 2005-2008 Team XBMC
 *      http://www.xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */

#include "DVDAudioCodecDirectshow.h"
#include "DVDClock.h"
#include "DVDStreamInfo.h"
#include "utils/log.h"
#include "application.h"
#include "dsnative/DSCodecTag.h"
#include "dsnative/dumpuids.h"
#include "mfapi.h"
#include "settings/Settings.h"
#include "settings/GUISettings.h"
//#include <streams.h>

#include "DllAvFormat.h"
#include "DllAvCodec.h"

CDVDAudioCodecDirectshow::CDVDAudioCodecDirectshow() : CDVDAudioCodec()
{
  codec = NULL;
  m_iBuffered = NULL;
  m_pWaveOut = NULL;
  m_channelMap[0] = PCM_INVALID;
  m_channels = 0;
  m_layout = 0;
}

CDVDAudioCodecDirectshow::~CDVDAudioCodecDirectshow()
{
  Dispose();
}


bool CDVDAudioCodecDirectshow::Open(CDVDStreamInfo &hints, CDVDCodecOptions &options)
{ 
  CStdString ffdshow = CStdString("C:\\Program Files (x86)\\ffdshow\\ffdshow.ax");
 /*audiodev example directshow:{E30629D1-27E5-11CE-875D-00608CB78066}*/
  CStdString audiodev = g_guiSettings.GetString("audiooutput.dshow_renderer");
  CStdStringW strAudioRendererGuid;
  GUID guidAudioRenderer = GUID_NULL;
  if (audiodev.Replace("directshow:","")>0)
  {
    
    g_charsetConverter.toW(audiodev,strAudioRendererGuid,"UTF-8");
    CLSIDFromString((LPCOLESTR)strAudioRendererGuid.c_str(),&guidAudioRenderer);
  }
  
  dsnerror_t err;
  unsigned int codecTag;
  DllAvFormat dllAvFormat;
  dllAvFormat.Load();

  CMediaType mediaType;
  mediaType.InitMediaType();
  mediaType.majortype = MEDIATYPE_Audio;
  codecTag = dllAvFormat.av_codec_get_tag(mp_wav_taglists, hints.codec);
  mediaType.subtype = FOURCCMap(codecTag);
  mediaType.formattype = FORMAT_WaveFormatEx; //default value
  mediaType.SetSampleSize(256000);
  // special cases
  switch(hints.codec)
  {
  case CODEC_ID_AAC_LATM:
  case CODEC_ID_AC3:
    mediaType.subtype = MEDIASUBTYPE_WAVE_DOLBY_AC3;
    break;
  case CODEC_ID_AAC:
    mediaType.subtype = MEDIASUBTYPE_AAC;
    codecTag = WAVE_FORMAT_AAC;
    break;
  /*case CODEC_ID_AAC_LATM:
    mediaType.subtype = MEDIASUBTYPE_LATM_AAC;
    codecTag = WAVE_FORMAT_LATM_AAC;
    break;*/
  case CODEC_ID_DTS:
    mediaType.subtype = MEDIASUBTYPE_DTS;
    codecTag = WAVE_FORMAT_DTS;
    break;
  case CODEC_ID_EAC3:
    mediaType.subtype = MEDIASUBTYPE_DOLBY_DDPLUS;
    break;
  case CODEC_ID_TRUEHD:
    mediaType.subtype = MEDIASUBTYPE_DOLBY_TRUEHD;
    break;
  case CODEC_ID_VORBIS:
    //TODO
    mediaType.formattype = FORMAT_VorbisFormat;
    mediaType.subtype = MEDIASUBTYPE_Vorbis;
    break;
  case CODEC_ID_MP1:
  case CODEC_ID_MP2:
    mediaType.subtype = MEDIASUBTYPE_MPEG1AudioPayload;
    break;
  case CODEC_ID_MP3:
    mediaType.subtype = MEDIASUBTYPE_MP3;
    break;
  case CODEC_ID_PCM_BLURAY:
    mediaType.subtype = MEDIASUBTYPE_HDMV_LPCM_AUDIO;
    break;
  case CODEC_ID_PCM_DVD:
    mediaType.subtype = MEDIASUBTYPE_DVD_LPCM_AUDIO;
    break;
  }
  WAVEFORMATEX *wvfmt = (WAVEFORMATEX *)CoTaskMemAlloc(sizeof(WAVEFORMATEX) + hints.extrasize);
  memset(wvfmt, 0, sizeof(WAVEFORMATEX));
  if (mediaType.subtype == FOURCCMap(codecTag))
    wvfmt->wFormatTag = codecTag;
  else
    wvfmt->wFormatTag = mediaType.Subtype()->Data1;

  wvfmt->nChannels = hints.channels;
  wvfmt->nSamplesPerSec = hints.samplerate;
  wvfmt->nAvgBytesPerSec = hints.bitrate / 8;
  wvfmt->nBlockAlign = hints.blockalign;
#if 1
  wvfmt->wBitsPerSample = 0;
#else
  if(hints.codec == CODEC_ID_AAC || hints.codec == CODEC_ID_AAC_LATM) {
    wvfmt->wBitsPerSample = 0;
    wvfmt->nBlockAlign = 1;
  } else {
    wvfmt->wBitsPerSample = get_bits_per_sample(avstream->codec);

    if ( avstream->codec->block_align > 0 ) {
      wvfmt->nBlockAlign = avstream->codec->block_align;
    } else {
      if ( wvfmt->wBitsPerSample == 0 ) {
        DbgOutString(L"BitsPerSample is 0, no good!");
      }
      wvfmt->nBlockAlign = (WORD)((wvfmt->nChannels * av_get_bits_per_sample_format(avstream->codec->sample_fmt)) / 8);
    }
  }
#endif
  if (hints.extrasize > 0) 
  {
    wvfmt->cbSize = hints.extrasize;
    memcpy((BYTE *)wvfmt + sizeof(WAVEFORMATEX), hints.extradata, hints.extrasize);
  }

  mediaType.cbFormat = sizeof(WAVEFORMATEX) + hints.extrasize;
  mediaType.pbFormat = (BYTE *)wvfmt;
  //mmioFOURCC('X', 'V', 'I', 'D');
  //memcpy(bih + 1, hints.extradata, hints.extrasize);


  
  CStdString curfile = g_application.CurrentFile();
  CLog::Log(LOGNOTICE,"Loading directshow filter");
  
  
  wfmtTypeOut = new CMediaType();
  //audiorendererguid
  codec = DSOpenAudioCodec(""/*ffdshow.c_str()*/ ,CLSID_FFDShow_Audio_Decoder , &mediaType, curfile.c_str(), guidAudioRenderer, wfmtTypeOut , &err);
  SetOutputWaveFormat((WAVEFORMATEX *) wfmtTypeOut->Format());

  int index = 0;
  for (; index < m_channels; index++)
  {
    m_channelMap[index] = standardChannelMasks[m_channels-1][index];
  
  }

  m_channelMap[index] = PCM_INVALID;

  if (!codec)
  {
    CLog::Log(LOGERROR,"DShowNative codec failed:%s",DSStrError(err));
    return false;
  }
  CLog::Log(LOGNOTICE,"Loading directshow filter Completed");

  return true;
}

void CDVDAudioCodecDirectshow::Dispose()
{
  if (codec)
  {
    CLog::Log(LOGNOTICE,"unloading dsnative");
    DSCloseAudioCodec(codec);
    codec = NULL;
  }
}

int CDVDAudioCodecDirectshow::Decode(BYTE* pData, int iSize)
{
  int iBytesUsed=0;
  int err;

      // Zero out the frame data if we are supposed to silence the audio
    
    
  err = DSAudioDecode(codec, pData, iSize, &iBytesUsed);
  
  m_iBuffered = iBytesUsed;
  
  if (err != 0)
    return 0;


  
  return iBytesUsed;
}

void CDVDAudioCodecDirectshow::Reset()
{
  //TODO
}

int CDVDAudioCodecDirectshow::GetBufferSize()
{
  if (codec)
    return DSAudioSampleSize(codec);
  //return m_iBuffered;
}

int CDVDAudioCodecDirectshow::GetData(BYTE** dst)
{
  int newMediaType = 0;
  int sizesample = 0;
  if (codec)
  {
    
     sizesample = DSAudioGetSample(codec, dst, &newMediaType);
     if (newMediaType > 0)
     {
       CMediaType wfmtTypeOut2;
       int restype = (int)DSAudioGetMediaType(codec, &wfmtTypeOut2);
       SetOutputWaveFormat((WAVEFORMATEX*)wfmtTypeOut2.Format());

     }
  }

  return sizesample;
}

void CDVDAudioCodecDirectshow::SetOutputWaveFormat(WAVEFORMATEX* pWave)
{
  m_pWaveOut = pWave;
  m_channels = m_pWaveOut->nChannels;
  //m_layout = m_pWaveOut->dwChannelMask;
  if (g_settings.m_currentAudioSettings.m_WaveFormat)
  {
    BYTE *p = (BYTE *)g_settings.m_currentAudioSettings.m_WaveFormat;
    SAFE_DELETE_ARRAY(p);
  }
  g_settings.m_currentAudioSettings.m_WaveFormat = NULL;
  int size = sizeof(WAVEFORMATEX) + m_pWaveOut->cbSize;
  g_settings.m_currentAudioSettings.m_WaveFormat = (WAVEFORMATEX *)new BYTE[size];
  memcpy(g_settings.m_currentAudioSettings.m_WaveFormat, m_pWaveOut, size);
}

int CDVDAudioCodecDirectshow::GetChannels()
{
  if (m_pWaveOut)
    return m_pWaveOut->nChannels;
  return 0;
}
enum PCMChannels *CDVDAudioCodecDirectshow::GetChannelMap()
{
  if (m_channelMap[0] == PCM_INVALID)
    return NULL;
  return m_channelMap;
  
}

int CDVDAudioCodecDirectshow::GetSampleRate()
{
  if (m_pWaveOut)
    return m_pWaveOut->nSamplesPerSec;
  return 0;
}

int CDVDAudioCodecDirectshow::GetBitsPerSample()
{
  if (m_pWaveOut)
    return m_pWaveOut->wBitsPerSample;
  return 0;
}