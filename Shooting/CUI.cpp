#include "stdafx.h"
#include "CUI.h"
#include "Core.h"
#include "time.h"
#include "TimeMgr.h"
#include "StageMgr.h"

CUI::CUI()
{
	//srand((UINT)time(NULL));
	m_vPos.x = float(rand() % int(CCore::GetInst()->GetResolution().x));
	m_vPos.y = 50;
	m_dTime = 0.;
	m_eBelong = BELONG::UI;
}


CUI::~CUI()
{
}

int CUI::update()
{
	m_dTime += DT;

	if (m_dTime > 2)
	{
		return (int)OBJ_STATE::DIE_METEO;
	}
	return (int)OBJ_STATE::NONE;
}

void CUI::render(HDC _dc)
{
	TransparentBlt(_dc, int(m_vPos.x - m_pTex->GetWidth() / 2), int(m_vPos.y - m_pTex->GetHeight() / 2), m_pTex->GetWidth(), m_pTex->GetHeight(), m_pTex->GetDC(), 0, 0, m_pTex->GetWidth(), m_pTex->GetHeight(), RGB(0, 0, 0));
}