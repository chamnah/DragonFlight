#include "stdafx.h"
#include "Obj.h"

CObj::CObj()
	:m_vPos{0.f,0.f}
	, m_vScale{0.f,0.f,0.f,0.f}
	, m_pTex(NULL)
	, m_eBelong(BELONG::NONE)
{
}

CObj::~CObj()
{
}

void CObj::CollRender(HDC _hdc)
{
	if (m_eBelong == BELONG::NONE || m_eBelong == BELONG::UI)
		return;

	HPEN Pen = CreatePen(PS_SOLID,5,RGB(255,0,0));
	HPEN Old = (HPEN)SelectObject(_hdc,Pen);

	MoveToEx(_hdc,int(m_vPos.x - m_vScale.left / 2), int(m_vPos.y - m_vScale.top / 2),NULL);
	LineTo(_hdc, int(m_vPos.x + m_vScale.right / 2), int(m_vPos.y - m_vScale.top / 2));
	LineTo(_hdc, int(m_vPos.x + m_vScale.right / 2), int(m_vPos.y + m_vScale.bottom / 2));
	LineTo(_hdc, int(m_vPos.x - m_vScale.left / 2), int(m_vPos.y + m_vScale.bottom / 2));
	LineTo(_hdc, int(m_vPos.x - m_vScale.left / 2), int(m_vPos.y - m_vScale.top / 2));

	(HPEN)SelectObject(_hdc, Old);
	DeleteObject(Pen);
}