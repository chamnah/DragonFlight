#include "stdafx.h"
#include "CWarning.h"
#include "ResMgr.h"
#include "Core.h"
#include "TimeMgr.h"

CWarning::CWarning()
	:m_dTime(0.)
{
	m_eBelong = BELONG::UI;
	m_pTex = (CTexture*)CResMgr::GetInst()->Load<CTexture*>(L"Warning",L"UI\\Warning.bmp");
	m_pTex2  = (CTexture*)CResMgr::GetInst()->Load<CTexture*>(L"Warning2", L"UI\\Warning2.bmp");

	m_vPos = Vec2(CCore::GetInst()->GetResolution().x - m_pTex->GetWidth(), CCore::GetInst()->GetResolution().y - m_pTex->GetHeight());
	m_vLeft = Vec2(0,0);
	m_fSpeed = 200.f;
}


CWarning::~CWarning()
{
}

int CWarning::update()
{
	m_dTime += DT;
	m_vLeft.y -= m_fSpeed * DT;
	m_vPos.y += m_fSpeed * DT;
	
	if(m_dTime > 3)
	return (int)OBJ_STATE::DIE_BOSS;

	return (int)OBJ_STATE::NONE;
}

void CWarning::render(HDC _dc)
{
	for(int i = 0; i < 3;++i)
	TransparentBlt(_dc, (int)m_vLeft.x, int(m_vLeft.y + i * m_pTex2->GetHeight()), m_pTex2->GetWidth(), m_pTex2->GetHeight(), m_pTex2->GetDC(), 0, 0, m_pTex2->GetWidth(), m_pTex2->GetHeight(), RGB(0, 0, 0));
	for (int i = 0; i < 3; ++i)
	TransparentBlt(_dc, (int)m_vPos.x, int(m_vPos.y - i * m_pTex2->GetHeight()), m_pTex->GetWidth(), m_pTex->GetHeight(), m_pTex->GetDC(), 0, 0, m_pTex->GetWidth(), m_pTex->GetHeight(), RGB(0, 0, 0));
}