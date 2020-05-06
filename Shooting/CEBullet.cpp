#include "stdafx.h"
#include "CEBullet.h"
#include "ResMgr.h"
#include "TimeMgr.h"
#include "CameraMgr.h"

CEBullet::CEBullet()
	:m_bCamera(true)
{
	m_fSpeed = 300;
	m_iDamage = 10;
	m_vScale = tRect(20, 20, 20, 20);
	m_pTex = (CTexture*)CResMgr::GetInst()->Load<CTexture*>(L"EBullet", L"Bullet\\SmallBullet.bmp");
	m_eBelong = BELONG::MBULLET;
}

CEBullet::~CEBullet()
{
}

int CEBullet::update()
{
	if (m_bCamera)
	{
		m_vRealPos.x += m_fSpeed * cosf(m_fAngle) * DT;
		m_vRealPos.y -= m_fSpeed * sinf(m_fAngle) * DT;
		m_vPos = CCameraMgr::GetInst()->GetRealPos(m_vRealPos.x, m_vRealPos.y);
	}
	else
	{
		m_vPos.x += m_fSpeed * cosf(m_fAngle) * DT;
		m_vPos.y -= m_fSpeed * sinf(m_fAngle) * DT;
	}
	return (int)OBJ_STATE::NONE;
}