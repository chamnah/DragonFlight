#pragma once
#include "Res.h"
class CTexture :
	public CRes
{
private:
	HBITMAP m_bit;
	HDC		m_dc;
	UINT    m_iWidth;
	UINT    m_iHeight;

public:
	static CTexture* Load(wstring _path);
	HDC& GetDC() { return m_dc; }
	int GetWidth() { return m_iWidth; }
	int GetHeight() { return m_iHeight; }
	void ChangeSize(UINT _iWidth, UINT _iHeight);

public:
	CTexture();
	virtual ~CTexture();
};