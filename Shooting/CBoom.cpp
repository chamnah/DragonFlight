#include "stdafx.h"
#include "CBoom.h"
#include "ResMgr.h"
#include "TimeMgr.h"

CBoom::CBoom()
	:m_dTime(0.)
	, m_dTotalTime(0.)
{
	m_vScale = tRect(0,0,132,128);
	m_pTex = (CTexture*)CResMgr::GetInst()->Load<CTexture*>(L"Boom", L"Effect\\Boom.bmp");
	m_eBelong = BELONG::NONE;
}

CBoom::~CBoom()
{
}

int CBoom::update()
{
	m_dTotalTime += DT;
	m_dTime += DT;

	if (m_dTotalTime >= 0.9)
		return (int)OBJ_STATE::DIE;

	if (m_dTime > 0.1)
	{
		m_dTime = 0;
		m_vScale.left += 132;
	}

	return (int)OBJ_STATE::NONE;
}

void CBoom::render(HDC _dc)
{
	TransparentBlt(_dc, m_vPos.x - m_vScale.right / 2, m_vPos.y - m_vScale.bottom / 2, m_vScale.right, m_vScale.bottom, m_pTex->GetDC(), m_vScale.left, m_vScale.top, m_vScale.right, m_vScale.bottom, RGB(0, 0, 0));
}