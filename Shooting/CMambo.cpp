#include "stdafx.h"
#include "CMambo.h"
#include "TimeMgr.h"
#include "CEBullet.h"
#include "StageMgr.h"
#include "ResMgr.h"
#include "Core.h"

int CMambo::update()
{
	CMonster::update();

	if (m_vPos.y <= 0)
		return 0;

	m_dTime += DT;
	if (m_dTime > 2)
	{
		m_dTime = 0.;
		CObj* pObj = new CEBullet;
		((CBullet*)pObj)->SetRealPos(Vec2(m_vRealPos.x, m_vRealPos.y + 30));
		((CBullet*)pObj)->SetDegree(210.f);
		CStageMgr::GetInst()->PushObj(pObj);

		pObj = new CEBullet;
		((CBullet*)pObj)->SetRealPos(Vec2(m_vRealPos.x, m_vRealPos.y + 30));
		((CBullet*)pObj)->SetDegree(240.f);
		CStageMgr::GetInst()->PushObj(pObj);

		pObj = new CEBullet;
		((CBullet*)pObj)->SetRealPos(Vec2(m_vRealPos.x, m_vRealPos.y + 30));
		((CBullet*)pObj)->SetDegree(270.f);
		CStageMgr::GetInst()->PushObj(pObj);

		pObj = new CEBullet;
		((CBullet*)pObj)->SetRealPos(Vec2(m_vRealPos.x, m_vRealPos.y + 30));
		((CBullet*)pObj)->SetDegree(300.f);
		CStageMgr::GetInst()->PushObj(pObj);

		pObj = new CEBullet;
		((CBullet*)pObj)->SetRealPos(Vec2(m_vRealPos.x, m_vRealPos.y + 30));
		((CBullet*)pObj)->SetDegree(330.f);
		CStageMgr::GetInst()->PushObj(pObj);
	}

	return (int)OBJ_STATE::NONE;
}

CMambo::CMambo()
{
	m_fHP = 200.f;
	m_fMaxHP = m_fHP;
	m_vScale = tRect(100,50,100,100);
	m_pTex = (CTexture*)CResMgr::GetInst()->Load<CTexture*>(L"Monster2", L"Monster\\Monster2.bmp");
}

CMambo::CMambo(float _fX, float _fY)
{
	m_vPos = Vec2(_fX, _fY);
	m_vRealPos = m_vPos;
	m_fHP = 200.f;
	m_fMaxHP = m_fHP;
	m_vScale = tRect(100, 50, 100, 100);
	m_pTex = (CTexture*)CResMgr::GetInst()->Load<CTexture*>(L"Monster2", L"Monster\\Monster2.bmp");
}

CMambo::~CMambo()
{
}