#pragma once

class CCore
{
	SINGLE(CCore);

private:
	HWND		m_hWnd;
	HDC			m_hDC;
	HBITMAP		m_hBit;
	HDC			m_memDC;
	Vec2		m_vResolution;

public:
	void init(HWND _hWnd);
	UINT progress();
	void ChageWindowSize(UINT _iLeft, UINT _iTop, UINT _iWidth, UINT _iHeight);
	const HDC& GetMainDC() { return m_hDC; }
	const Vec2& GetResolution() { return m_vResolution; }
private:
	int update();
	void render();
};