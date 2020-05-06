#include "stdafx.h"
#include "Texture.h"
#include "Core.h"
#include "ResMgr.h"

CTexture * CTexture::Load(wstring _path)
{
	HBITMAP bit = (HBITMAP)LoadImage(NULL, _path.c_str(), IMAGE_BITMAP, 0, 0,
		LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);

	HDC dc = CreateCompatibleDC(CCore::GetInst()->GetMainDC());

	if (NULL == bit || NULL == dc)
		return NULL;

	HBITMAP oldbit = (HBITMAP)SelectObject(dc, bit);
	DeleteObject(oldbit);

	BITMAP bm{};

	GetObject(bit,sizeof(bm),&bm);

	CTexture* pTex = new CTexture;
	pTex->m_dc = dc;
	pTex->m_bit = bit;
	pTex->m_iWidth = bm.bmWidth;
	pTex->m_iHeight = bm.bmHeight;

	return pTex;
}

CTexture::CTexture()
{
}

CTexture::~CTexture()
{
}

void CTexture::ChangeSize(UINT _iWidth, UINT _iHeight)
{
	HBITMAP hBit = CreateCompatibleBitmap(CCore::GetInst()->GetMainDC(), _iWidth, _iHeight);
	HDC dc = CreateCompatibleDC(CCore::GetInst()->GetMainDC());

	HBITMAP hOld = (HBITMAP)SelectObject(dc, hBit);
	DeleteObject(hOld);

	UINT iWidth = _iWidth > m_iWidth ? m_iWidth : _iWidth;
	UINT iHeight = _iHeight > m_iHeight ? m_iHeight : _iHeight;

	BitBlt(dc, 0, 0, iWidth, iHeight, m_dc, 0, 0, SRCCOPY);

	DeleteDC(m_dc);
	DeleteObject(m_bit);

	m_dc = dc;
	m_bit = hBit;

	m_iHeight = _iHeight;
	m_iWidth = _iWidth;
}