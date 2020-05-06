#include "stdafx.h"
#include "DynamicObj.h"

CDynamicObj::CDynamicObj()
	:m_fSpeed(0.f)
{
}

CDynamicObj::~CDynamicObj()
{
}

void CDynamicObj::render(HDC _dc)
{
	TransparentBlt(_dc, int(m_vPos.x - m_pTex->GetWidth() / 2), int(m_vPos.y - m_pTex->GetHeight() / 2), m_pTex->GetWidth(), m_pTex->GetHeight(), m_pTex->GetDC(), 0, 0, m_pTex->GetWidth(), m_pTex->GetHeight(), RGB(0, 0, 0));
}