#include "stdafx.h"
#include "CPBullet.h"
#include "TimeMgr.h"
#include "ResMgr.h"

int CPBullet::update()
{
	m_vPos.y -= m_fSpeed * DT;
	return (int)OBJ_STATE::NONE;
}

CPBullet::CPBullet()
{
	m_fSpeed = 400.f;
	m_iDamage = 20;
	m_vScale = tRect(20, 50, 20, 40);
	m_pTex = (CTexture*)CResMgr::GetInst()->Load<CTexture*>(L"Bullet", L"Bullet\\Bullet1.bmp");
	m_eBelong = BELONG::PBULLET;
}

CPBullet::~CPBullet()
{
}