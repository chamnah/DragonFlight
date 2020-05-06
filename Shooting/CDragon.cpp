#include "stdafx.h"
#include "CDragon.h"
#include "ResMgr.h"
#include "CameraMgr.h"

CDragon::CDragon()
{
	m_vRealPos = m_vPos;
	m_fHP = 100.f;
	m_fMaxHP = m_fHP;
	m_vScale = tRect(100, 50, 100, 100);
	m_pTex = (CTexture*)CResMgr::GetInst()->Load<CTexture*>(L"Monster", L"Monster\\Monster1.bmp");
}

CDragon::CDragon(float _fX, float _fY)
{
	m_vPos = Vec2(_fX, _fY);
	m_vRealPos = m_vPos;
	m_fHP = 100.f;
	m_fMaxHP = m_fHP;
	m_vScale = tRect(100, 50, 100, 100);
	m_pTex = (CTexture*)CResMgr::GetInst()->Load<CTexture*>(L"Monster", L"Monster\\Monster1.bmp");
}

CDragon::~CDragon()
{
}