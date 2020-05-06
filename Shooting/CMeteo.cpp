#include "stdafx.h"
#include "CMeteo.h"
#include "ResMgr.h"
#include "TimeMgr.h"
#include "CameraMgr.h"

int CMeteo::update()
{
	//m_vRealPos.y = CCameraMgr::GetInst()->GetRealPos(m_vRealPos.x, m_vRealPos.y);
	m_vPos.y += float(m_fSpeed * DT) + (CCameraMgr::GetInst()->GetCameraSpeed() * DT); 

	 return (int)OBJ_STATE::NONE;
}

CMeteo::CMeteo()
{
	m_vPos = Vec2(0, 0);
	m_fSpeed = 400.f;
	m_iDamage = 10;
	m_vScale = tRect(100,100,100,100);
	m_pTex = (CTexture*)CResMgr::GetInst()->Load<CTexture*>(L"Meteo",L"Bullet\\Meteo.bmp");
	m_eBelong = BELONG::METEO;
}

CMeteo::~CMeteo()
{
}