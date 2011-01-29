#pragma once
//------------------------------------------------------------------------------
// File: DumpUIDs.h
//
// Desc: DirectShow sample code - CLSIDs used by the dump renderer.
//
// Copyright (c) 1992-2001 Microsoft Corporation.  All rights reserved.
//------------------------------------------------------------------------------

// H264
// 34363248-0000-0010-8000-00aa00389b71
// DEFINE_GUID(MEDIASUBTYPE_H264,
// 0x34363248, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);

// 34363268-0000-0010-8000-00AA00389B71
DEFINE_GUID(MEDIASUBTYPE_h264,
0x34363268, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);

// 34363258-0000-0010-8000-00AA00389B71
DEFINE_GUID(MEDIASUBTYPE_X264,
0x34363258, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);

// 34363278-0000-0010-8000-00AA00389B71
DEFINE_GUID(MEDIASUBTYPE_x264,
0x34363278, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);

// 6F29D2AD-E130-45AA-B42F-F623AD354A90
DEFINE_GUID(MEDIASUBTYPE_ArcsoftH264,
0x6F29D2AD, 0xE130, 0x45AA, 0xB4, 0x2F, 0xF6, 0x23, 0xAD, 0x35, 0x4A, 0x90);

// 48535356-0000-0010-8000-00AA00389B71
DEFINE_GUID(MEDIASUBTYPE_VSSH,
0x48535356, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);

// 68737376-0000-0010-8000-00AA00389B71
DEFINE_GUID(MEDIASUBTYPE_vssh,
0x68737376, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);

// 43564144-0000-0010-8000-00AA00389B71
DEFINE_GUID(MEDIASUBTYPE_DAVC,
0x43564144, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);

// 63766164-0000-0010-8000-00AA00389B71
DEFINE_GUID(MEDIASUBTYPE_davc,
0x63766164, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);

// 43564150-0000-0010-8000-00AA00389B71
DEFINE_GUID(MEDIASUBTYPE_PAVC,
0x43564150, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);

// 63766170-0000-0010-8000-00AA00389B71
DEFINE_GUID(MEDIASUBTYPE_pavc,
0x63766170, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);

// 31435641-0000-0010-8000-00AA00389B71
DEFINE_GUID(MEDIASUBTYPE_AVC1,
0x31435641, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);

// 31637661-0000-0010-8000-00AA00389B71
DEFINE_GUID(MEDIASUBTYPE_avc1,
0x31637661, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);

// 31564343-0000-0010-8000-00AA00389B71 (custom H.264 FourCC used by Haali Media Splitter)
DEFINE_GUID(MEDIASUBTYPE_CCV1,
0x31564343, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);

// 8D2D71CB-243F-45E3-B2D8-5FD7967EC09B		<= Use by MediaPortal for example...
DEFINE_GUID(MEDIASUBTYPE_H264_bis,
0x8D2D71CB, 0x243F, 0x45E3, 0xB2, 0xD8, 0x5F, 0xD7, 0x96, 0x7E, 0xC0, 0x9B);

#define WAVE_FORMAT_DOLBY_AC3 0x2000
// {00002000-0000-0010-8000-00aa00389b71}
DEFINE_GUID(MEDIASUBTYPE_WAVE_DOLBY_AC3,
WAVE_FORMAT_DOLBY_AC3, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);

#define WAVE_FORMAT_DVD_DTS 0x2001
// {00002001-0000-0010-8000-00aa00389b71}
DEFINE_GUID(MEDIASUBTYPE_WAVE_DTS,
WAVE_FORMAT_DVD_DTS, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);

// Be compatible with 3ivx
#define WAVE_FORMAT_AAC 0x00FF
// {000000FF-0000-0010-8000-00AA00389B71}
DEFINE_GUID(MEDIASUBTYPE_AAC,
WAVE_FORMAT_AAC, 0x000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);

// ... and also compatible with nero
// btw, older nero parsers use a lower-case fourcc, newer upper-case (why can't it just offer both?)
// {4134504D-0000-0010-8000-00AA00389B71}
DEFINE_GUID(MEDIASUBTYPE_MP4A,
0x4134504D, 0x000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);

// {6134706D-0000-0010-8000-00AA00389B71}
DEFINE_GUID(MEDIASUBTYPE_mp4a,
0x6134706D, 0x000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);

#define WAVE_FORMAT_MP3 0x0055
// 00000055-0000-0010-8000-00AA00389B71
DEFINE_GUID(MEDIASUBTYPE_MP3,
WAVE_FORMAT_MP3, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);

#define WAVE_FORMAT_FLAC 0xF1AC
// 0000F1AC-0000-0010-8000-00AA00389B71
DEFINE_GUID(MEDIASUBTYPE_FLAC,
WAVE_FORMAT_FLAC, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);

// {1541C5C0-CDDF-477d-BC0A-86F8AE7F8354}
DEFINE_GUID(MEDIASUBTYPE_FLAC_FRAMED,
0x1541c5c0, 0xcddf, 0x477d, 0xbc, 0xa, 0x86, 0xf8, 0xae, 0x7f, 0x83, 0x54);

#define WAVE_FORMAT_TTA1 0x77A1
// {000077A1-0000-0010-8000-00AA00389B71}
DEFINE_GUID(MEDIASUBTYPE_TTA1,
WAVE_FORMAT_TTA1, 0x000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);

#define WAVE_FORMAT_WAVPACK4 0x5756
// {00005756-0000-0010-8000-00AA00389B71}
DEFINE_GUID(MEDIASUBTYPE_WAVPACK4,
WAVE_FORMAT_WAVPACK4, 0x000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);

// {D2855FA9-61A7-4db0-B979-71F297C17A04}
DEFINE_GUID(MEDIASUBTYPE_Ogg,
0xd2855fa9, 0x61a7, 0x4db0, 0xb9, 0x79, 0x71, 0xf2, 0x97, 0xc1, 0x7a, 0x4);

// cddca2d5-6d75-4f98-840e-737bedd5c63b
DEFINE_GUID(MEDIASUBTYPE_Vorbis,
0xcddca2d5, 0x6d75, 0x4f98, 0x84, 0x0e, 0x73, 0x7b, 0xed, 0xd5, 0xc6, 0x3b);

// {8D2FD10B-5841-4a6b-8905-588FEC1ADED9}
DEFINE_GUID(MEDIASUBTYPE_Vorbis2, 
0x8d2fd10b, 0x5841, 0x4a6b, 0x89, 0x5, 0x58, 0x8f, 0xec, 0x1a, 0xde, 0xd9);

DEFINE_GUID(MEDIASUBTYPE_DOLBY_DDPLUS,  
0xa7fb87af, 0x2d02, 0x42fb, 0xa4, 0xd4, 0x5, 0xcd, 0x93, 0x84, 0x3b, 0xdd);

DEFINE_GUID(MEDIASUBTYPE_DOLBY_TRUEHD,
0xeb27cec4, 0x163e, 0x4ca3, 0x8b, 0x74, 0x8e, 0x25, 0xf9, 0x1b, 0x51, 0x7e);

DEFINE_GUID(MEDIASUBTYPE_DTS_HD,
0xa2e58eb7, 0xfa9, 0x48bb, 0xa4, 0xc, 0xfa, 0xe, 0x15, 0x6d, 0x6, 0x45);


//
// RealMedia
//

// {57428EC6-C2B2-44a2-AA9C-28F0B6A5C48E}
DEFINE_GUID(MEDIASUBTYPE_RealMedia, 
0x57428ec6, 0xc2b2, 0x44a2, 0xaa, 0x9c, 0x28, 0xf0, 0xb6, 0xa5, 0xc4, 0x8e);

// 30315652-0000-0010-8000-00AA00389B71
DEFINE_GUID(MEDIASUBTYPE_RV10,
0x30315652, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);

// 30325652-0000-0010-8000-00AA00389B71
DEFINE_GUID(MEDIASUBTYPE_RV20,
0x30325652, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);

// 30335652-0000-0010-8000-00AA00389B71
DEFINE_GUID(MEDIASUBTYPE_RV30,
0x30335652, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);

// 30345652-0000-0010-8000-00AA00389B71
DEFINE_GUID(MEDIASUBTYPE_RV40,
0x30345652, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);

// 31345652-0000-0010-8000-00AA00389B71
DEFINE_GUID(MEDIASUBTYPE_RV41,
0x31345652, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);

// 345f3431-0000-0010-8000-00AA00389B71
DEFINE_GUID(MEDIASUBTYPE_14_4,
0x345f3431, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);

// 385f3832-0000-0010-8000-00AA00389B71
DEFINE_GUID(MEDIASUBTYPE_28_8,
0x385f3832, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);

// 43525441-0000-0010-8000-00AA00389B71
DEFINE_GUID(MEDIASUBTYPE_ATRC,
0x43525441, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);

// 4b4f4f43-0000-0010-8000-00AA00389B71
DEFINE_GUID(MEDIASUBTYPE_COOK,
0x4b4f4f43, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);

// 54454e44-0000-0010-8000-00AA00389B71
DEFINE_GUID(MEDIASUBTYPE_DNET,
0x54454e44, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);

// 52504953-0000-0010-8000-00AA00389B71
DEFINE_GUID(MEDIASUBTYPE_SIPR,
0x52504953, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);

// 43414152-0000-0010-8000-00AA00389B71
DEFINE_GUID(MEDIASUBTYPE_RAAC,
0x43414152, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);

// 50434152-0000-0010-8000-00AA00389B71
DEFINE_GUID(MEDIASUBTYPE_RACP,
0x50434152, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);

// 00002004-0000-0010-8000-00AA00389B71
DEFINE_GUID(MEDIASUBTYPE_COOK_HAALI,
0x00002004, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);

// {E487EB08-6B26-4be9-9DD3-993434D313FD}
DEFINE_GUID(MEDIATYPE_Subtitle,
0xe487eb08, 0x6b26, 0x4be9, 0x9d, 0xd3, 0x99, 0x34, 0x34, 0xd3, 0x13, 0xfd);

// { 36a5f770-fe4c-11ce-a8ed-00aa002feab5 }
DEFINE_GUID(CLSID_Dump,
0x36a5f770, 0xfe4c, 0x11ce, 0xa8, 0xed, 0x00, 0xaa, 0x00, 0x2f, 0xea, 0xb5);

// { C1F400A4-3F08-11D3-9F0B-006008039E37 } 
DEFINE_GUID(CLSID_NullRenderer, 
0xC1F400A4, 0x3F08, 0x11D3, 0x9F, 0x0B, 0x00, 0x60, 0x08, 0x03, 0x9e, 0x37);

// { DC257063-045F-4BE2-BD5B-E12279C464F0 }
DEFINE_GUID(CLSID_MPC_MPEGSplitter,
0xDC257063, 0x045F, 0x4BE2, 0xBD, 0x5B, 0xE1, 0x22, 0x79, 0xC4, 0x64, 0xF0);

// { 1365BE7A-C86A-473C-9A41-C0A6E82C9FA3 }
DEFINE_GUID(CLSID_MPC_MPEGSource,
0x1365BE7A, 0xC86A, 0x473C, 0x9A, 0x41, 0xC0, 0xA6, 0xE8, 0x2C, 0x9F, 0xA3);

// { C9ECE7B3-1D8E-41F5-9F24-B255DF16C087 }
DEFINE_GUID(CLSID_MPC_FLVSource,
0xC9ECE7B3, 0x1D8E, 0x41F5, 0x9F, 0x24, 0xB2, 0x55, 0xDF, 0x16, 0xC0, 0x87);

// { 3CCC052E-BDEE-408a-BEA7-90914EF2964B }
DEFINE_GUID(CLSID_MPC_MP4Source,
0x3CCC052E, 0xBDEE, 0x408a, 0xBE, 0xA7, 0x90, 0x91, 0x4E, 0xF2, 0x96, 0x4B);

// { 6D3688CE-3E9D-42F4-92CA-8A11119D25CD }
DEFINE_GUID(CLSID_MPC_OggSource,
0x6D3688CE, 0x3E9D, 0x42F4, 0x92, 0xCA, 0x8A, 0x11, 0x11, 0x9D, 0x25, 0xCD);

// { 0A68C3B5-9164-4a54-AFAF-995B2FF0E0D4 }
DEFINE_GUID(CLSID_MPC_MatroskaSource,
0x0A68C3B5, 0x9164, 0x4a54, 0xAF, 0xAF, 0x99, 0x5B, 0x2F, 0xF0, 0xE0, 0xD4);

// { 765035B3-5944-4A94-806B-20EE3415F26F }
DEFINE_GUID(CLSID_MPC_RealSource,
0x765035B3, 0x5944, 0x4A94, 0x80, 0x6B, 0x20, 0xEE, 0x34, 0x15, 0xF2, 0x6F);

// { E21BE468-5C18-43EB-B0CC-DB93A847D769 }
DEFINE_GUID(CLSID_MPC_RealSplitter,
0xE21BE468, 0x5C18, 0x43EB, 0xB0, 0xCC, 0xDB, 0x93, 0xA8, 0x47, 0xD7, 0x69);

// { 238D0F23-5DC9-45A6-9BE2-666160C324DD }
DEFINE_GUID(CLSID_MPC_RealVideoDecoder,
0x238D0F23, 0x5DC9, 0x45A6, 0x9B, 0xE2, 0x66, 0x61, 0x60, 0xC3, 0x24, 0xDD);

// { 941A4793-A705-4312-8DFC-C11CA05F397E }
DEFINE_GUID(CLSID_MPC_RealAudioDecoder,
0x941A4793, 0xA705, 0x4312, 0x8D, 0xFC, 0xC1, 0x1C, 0xA0, 0x5F, 0x39, 0x7E);

// { 564FD788-86C9-4444-971E-CC4A243DA150 }
DEFINE_GUID(CLSID_HAALI_Splitter,
0x564FD788, 0x86C9, 0x4444, 0x97, 0x1E, 0xCC, 0x4A, 0x24, 0x3D, 0xA1, 0x50);

// { 55DA30FC-F16B-49FC-BAA5-AE59FC65F82D }
DEFINE_GUID(CLSID_HAALI_Media_Splitter,
0x55DA30FC, 0xF16B, 0x49FC, 0xBA, 0xA5, 0xAE, 0x59, 0xFC, 0x65, 0xF8, 0x2D);

// { 09571A4B-F1FE-4C60-9760-DE6D310C7C31 }
DEFINE_GUID(CLSID_COREAVC_Video_Decoder,
0x09571A4B, 0xF1FE, 0x4C60, 0x97, 0x60, 0xDE, 0x6D, 0x31, 0x0C, 0x7C, 0x31);

// { 6F513D27-97C3-453C-87FE-B24AE50B1601 }
DEFINE_GUID(CLSID_DIVXH264_Video_Decoder,
0x6F513D27, 0x97C3, 0x453C, 0x87, 0xFE, 0xB2, 0x4A, 0xE5, 0x0B, 0x16, 0x01);

// { 04FE9017-F873-410E-871E-AB91661A4EF7 }
DEFINE_GUID(CLSID_FFDShow_Video_Decoder,
0x04FE9017, 0xF873, 0x410E, 0x87, 0x1E, 0xAB, 0x91, 0x66, 0x1A, 0x4E, 0xF7);

// { 0B0EFF97-C750-462C-9488-B10E7D87F1A6 }
DEFINE_GUID(CLSID_FFDShow_DXVA_Video_Decoder,
0x0B0EFF97, 0xC750, 0x462C, 0x94, 0x88, 0xB1, 0x0E, 0x7D, 0x87, 0xF1, 0xA6);

DEFINE_GUID(CLSID_EnhancedVideoRenderer,
0xFA10746C, 0x9B63, 0x4B6C, 0xBC, 0x49, 0xFC, 0x30, 0x0E, 0xA5, 0xF2, 0x56);

// { 0F40E1E5-4F79-4988-B1A9-CC98794E6B55 }
DEFINE_GUID(CLSID_FFDShow_Audio_Decoder,
0x0F40E1E5, 0x4F79, 0x4988, 0xB1, 0xA9, 0xCC, 0x98, 0x79, 0x4E, 0x6B, 0x55);

// { 008BAC12-FBAF-497b-9670-BC6F6FBAE2C4 }
DEFINE_GUID(CLSID_MPC_Video_Decoder,
0x008BAC12, 0xFBAF, 0x497b, 0x96, 0x70, 0xBC, 0x6F, 0x6F, 0xBA, 0xE2, 0xC4);

// { 3D446B6F-71DE-4437-BE15-8CE47174340F }
DEFINE_GUID(CLSID_MPC_Audio_Decoder,
0x3D446B6F, 0x71DE, 0x4437, 0xBE, 0x15, 0x8C, 0xE4, 0x71, 0x74, 0x34, 0x0F);

// { 9852A670-F845-491B-9BE6-EBD841B8A613 }
DEFINE_GUID(CLSID_DirectVobSub_Autoload,
0x9852A670, 0xF845, 0x491B, 0x9B, 0xE6, 0xEB, 0xD8, 0x41, 0xB8, 0xA6, 0x13);

DEFINE_GUID(CLSID_MPC_VTSReader,
0x773EAEDE, 0xD5EE, 0x4FCE, 0x9C, 0x8F, 0xC4, 0xF5, 0x3D, 0x0A, 0x2F, 0x73);

#define WAVE_FORMAT_LATM_AAC 0x01FF
// {000001FF-0000-0010-8000-00AA00389B71}
DEFINE_GUID(MEDIASUBTYPE_LATM_AAC,
			WAVE_FORMAT_LATM_AAC, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);

// 6bddfa7e-9f22-46a9-ab5e-884eff294d9f
DEFINE_GUID(FORMAT_VorbisFormat,
			0x6bddfa7e, 0x9f22, 0x46a9, 0xab, 0x5e, 0x88, 0x4e, 0xff, 0x29, 0x4d, 0x9f);

typedef struct tagVORBISFORMAT
{
	WORD nChannels;
	DWORD nSamplesPerSec;
	DWORD nMinBitsPerSec;
	DWORD nAvgBitsPerSec;
	DWORD nMaxBitsPerSec;
	float fQuality;
} VORBISFORMAT, *PVORBISFORMAT, FAR *LPVORBISFORMAT;

// {949F97FD-56F6-4527-B4AE-DDEB375AB80F}		Mpc-hc specific !
DEFINE_GUID(MEDIASUBTYPE_HDMV_LPCM_AUDIO,
			0x949f97fd, 0x56f6, 0x4527, 0xb4, 0xae, 0xdd, 0xeb, 0x37, 0x5a, 0xb8, 0xf);

struct WAVEFORMATEX_HDMV_LPCM : public WAVEFORMATEX
{
	BYTE channel_conf;

	struct WAVEFORMATEX_HDMV_LPCM()
	{
		memset(this, 0, sizeof(*this));
		cbSize = sizeof(WAVEFORMATEX_HDMV_LPCM) - sizeof(WAVEFORMATEX);
	}
};