#include "stdafx.h"
#include "CView.h"

CView::CView()
	:m_bBlt(false),
	m_iItem(0)
{
}

CView::~CView()
{
}

int CView::update()
{
	return 0;
}

void CView::render(HDC _dc)
{
	if(m_bBlt)
		BitBlt(_dc, (int)m_vPos.x, (int)m_vPos.y, m_pTex->GetWidth(), m_pTex->GetHeight(), m_pTex->GetDC(), 0, 0, SRCCOPY);
	else
		TransparentBlt(_dc, (int)m_vPos.x, (int)m_vPos.y, m_pTex->GetWidth(), m_pTex->GetHeight(), m_pTex->GetDC(), 0, 0, m_pTex->GetWidth(), m_pTex->GetHeight(), RGB(0, 0, 0));
}