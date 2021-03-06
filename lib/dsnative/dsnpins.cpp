/*
 * DShow Native wrapper
 * Copyright (c) 2010 Gianluigi Tiesi <sherpya@netfarm.it>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "stdafx.h"
#include "dsnpins.h"

#include "..\..\xbmc\utils\stdstring.h"
#pragma comment(lib, "dxva2.lib")
CSenderPin::CSenderPin(HRESULT *phr, CSenderFilter *pFilter, CCritSec *pLock) 
  : CBaseOutputPin(NAME("CSenderPin"), pFilter, pLock, phr, L"Sender")
{
}

CSenderFilter::CSenderFilter() : CBaseFilter(NAME("CSenderFilter"), NULL, &m_csFilter, GUID_NULL), m_pFileName(NULL)
{
  m_pin = new CSenderPin(&m_hr, this, &m_csFilter);
}

CSenderFilter::~CSenderFilter()
{
  delete m_pin;
  if (m_pFileName) 
    delete m_pFileName;
}

HRESULT CSenderFilter::NonDelegatingQueryInterface(REFIID riid, void **ppv)
{
  if (riid == IID_IFileSourceFilter)
    return GetInterface((IFileSourceFilter *) this, ppv);
  else if (riid == IID_IGraphBuilder)
    return GetInterface((IFilterGraph *) this, ppv);
  else
    return CBaseFilter::NonDelegatingQueryInterface(riid, ppv);
}

HRESULT CSenderFilter::Load(LPCOLESTR pszFileName, const AM_MEDIA_TYPE *pmt)
{
  if (pszFileName)
  {
    if (m_pFileName) delete m_pFileName;
    size_t len = lstrlenW(pszFileName) + 1;
    m_pFileName = new OLECHAR[len];
    memcpy(m_pFileName, pszFileName, sizeof(OLECHAR) * len);
  }
  return S_OK;
}

HRESULT CSenderFilter::GetCurFile(LPOLESTR *ppszFileName, AM_MEDIA_TYPE *pmt)
{
  if (m_pFileName)
  {
    size_t len = lstrlenW(m_pFileName) + 1;
    *ppszFileName = (LPOLESTR) CoTaskMemAlloc(sizeof(OLECHAR) * len);
    memcpy(*ppszFileName, m_pFileName, sizeof(OLECHAR) * len);
  }

  if (pmt)
  {
    memset(pmt, 0, sizeof(AM_MEDIA_TYPE));
    pmt->majortype = MEDIATYPE_NULL;
    pmt->subtype = MEDIASUBTYPE_NULL;
  }

  return S_OK;
}


CRenderPin::CRenderPin(HRESULT *phr, CRenderFilter *pFilter, CCritSec *pLock) 
  : m_gPtr(NULL),
    m_reftime(-1LL << 63),
    m_fSize(0),
    CBaseInputPin(NAME("CRenderPin"), 
    pFilter,
    pLock,
    phr,
    L"Render")
{
}

CRenderPin::~CRenderPin()
{
}

HRESULT CRenderPin::NonDelegatingQueryInterface(REFIID riid, void **ppv)
{
  return CBaseInputPin::NonDelegatingQueryInterface(riid, ppv);
}

HRESULT CRenderPin::Receive(IMediaSample *pSample)
{
  BYTE *ptr;
  REFERENCE_TIME start;
  long len = pSample->GetActualDataLength();

  if (m_gPtr && (len > 0))
  {
    pSample->GetPointer(&ptr);
    m_gPtrSize = pSample->GetSize();
    /* why the hell divxh264 returns huge sample len */
    memcpy(m_gPtr, ptr, std::min(len, m_fSize));
  }
  pSample->GetTime(&start, &m_reftime);
  return S_OK;
}

CRenderFilter::CRenderFilter()
  : CBaseFilter(NAME("CRenderFilter"), NULL, &m_csFilter, GUID_NULL)
{
  m_pin = new CRenderPin(&m_hr, this, &m_csFilter);
}

CRenderFilter::~CRenderFilter()
{
  delete m_pin;
}