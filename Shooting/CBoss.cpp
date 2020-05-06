#include "stdafx.h"
#include "CBoss.h"
#include "TimeMgr.h"
#include "StageMgr.h"
#include "CEBullet.h"
#include "ResMgr.h"
#include "Core.h"
#include "CGameMgr.h"

CBoss::CBoss()
	:m_dTime(0.),
	m_iSelect(1),
	m_fAngle(0.f),
	m_dTotalTime(0.),
	m_dBreakTime(0.),
	m_sNumber(0),
	m_bStart(true),
	m_bTest(true),
	m_bOne(true),
	m_pObj(NULL)
{
	m_fSpeed = 200.f;
	m_fHP = 2000.f;
	m_fMaxHP = m_fHP;
	m_pTexBackHP = (CTexture*)CResMgr::GetInst()->Load<CTexture*>(L"LHP_in", L"UI\\LHP_back.bmp");
	m_pTexInHP = (CTexture*)CResMgr::GetInst()->Load<CTexture*>(L"LHP_back", L"UI\\LHP_in.bmp");
	m_pTex = (CTexture*)CResMgr::GetInst()->Load<CTexture*>(L"Monster4", L"Monster\\clown.bmp");
	m_fHeight = 100.f;
	m_vTempPos = Vec2(0, 0);

	m_vScale = tRect(140,100,120,160);

	m_vPos = Vec2(400,-m_pTex->GetHeight());
}

CBoss::~CBoss()
{
}

int CBoss::update()
{
	if(m_bStart)
		StartPattern();

	else
	{
		m_vPos.x += m_fSpeed * (float)DT;

		switch (m_iSelect)
		{
		case 1:
			PatternOne();
			break;
		case 2:
			PatternTwo();
			break;
		case 3:
			PatternThree();
			break;

		default:
			break;
		}
	}
	return (int)OBJ_STATE::NONE;
}

int CBoss::lateupdate(CObj * _pObj)
{
	if (m_vPos.x > 600.f)
	{
		m_vPos.x = 600.f;
		m_fSpeed = -m_fSpeed;
	}
	else if (m_vPos.x < 100.f)
	{
		m_vPos.x = 100.f;
		m_fSpeed = -m_fSpeed;
	}

	if (CMonster::lateupdate(_pObj) == (int)OBJ_STATE::DIE)
	{
		CGameMgr::GetInst()->AddScore(1000);
		return (int)OBJ_STATE::GAME_END;
	}
	return (int)OBJ_STATE::NONE;
}

void CBoss::PatternOne()
{
	m_fSpeed = 0.f;
	m_dTotalTime += DT;
	m_dTime += DT;

	if (m_dTime > 0.05)
	{
		m_dTime = 0;
		CObj* pObj = new CEBullet;
		((CEBullet*)pObj)->SetIsCamera(false);
		pObj->SetPos(m_vPos);
		((CBullet*)pObj)->SetDegree(m_fAngle);
		CStageMgr::GetInst()->PushObj(pObj);

		m_fAngle += 20.f;
	}

	if (m_dTotalTime > 4)
	{
		m_dTime = 0.;
		m_dTotalTime = 0.;
		m_fSpeed = 100.f;
		if (m_bTest)
			m_iSelect = 2;
		else
			m_iSelect = (rand() % 3) + 1;
	}
}

void CBoss::PatternTwo()
{
	m_dTotalTime += DT;
	m_dTime += DT;

	if (m_bOne)
	{
		m_bOne = false;
		m_fAngle = OppAngle(this, m_pObj);
		m_vTempPos = m_vPos;
	}

	static Vec2  vPos = m_vPos;
	if (m_dTotalTime <= 0.6)
	{
		if (m_dTime > 0.125)
		{
			m_dTime = 0;
			CObj* pObj = new CEBullet;
			((CEBullet*)pObj)->SetIsCamera(false);
			pObj->SetPos(Vec2(m_vTempPos.x, m_vTempPos.y + 50));
			((CBullet*)pObj)->SetRadian(m_fAngle);
			CStageMgr::GetInst()->PushObj(pObj);
		}
	}
	else
	{
		m_dBreakTime += DT;
	}

	if (m_dBreakTime > 1.)
	{
		m_fAngle = OppAngle(this, m_pObj);
		m_vTempPos = m_vPos;
		m_sNumber += 1;
		m_dBreakTime = 0.;
		m_dTime = 0.;
		m_dTotalTime = 0.;
	}

	if (m_sNumber > 3)
	{
		m_bOne = true;
		m_sNumber = 0;
		if(m_bTest)
		m_iSelect = 3;
		else
			m_iSelect = (rand() % 3) + 1;
	}
}

void CBoss::PatternThree()
{
	if (fabsf(CCore::GetInst()->GetResolution().x / 2 - m_vPos.x) > 0.5f) // 현재 여기서 문제 발생 원인은 위에 업데이트에서 계속 움직이고 있어서 중첩이 되어 멈추지 않는다. 오면 이것부터 수정바람
	{
		m_fAngle = 240.f;

		if (CCore::GetInst()->GetResolution().x / 2 > m_vPos.x)
		{
			m_fSpeed = fabsf(m_fSpeed);
		}
		else if (CCore::GetInst()->GetResolution().x / 2 < m_vPos.x)
		{
			m_fSpeed = -(fabsf(m_fSpeed));
		}
	}
	else
	{
		static float fMove = 10.f;
		m_dTime += DT;
		m_fAngle += fMove * DT;
		m_fSpeed = 0;

		if (m_fAngle > 285.f)
		{
			m_fAngle = 285.f;
			fMove = -fMove;
		}

		if (m_dTime > 0.3)
		{
			m_dTime = 0;
			CObj* pObj = new CEBullet;
			((CEBullet*)pObj)->SetIsCamera(false);
			pObj->SetPos(Vec2(m_vPos.x, m_vPos.y + 80.f));
			((CBullet*)pObj)->SetDegree(m_fAngle);
			CStageMgr::GetInst()->PushObj(pObj);

			pObj = new CEBullet;
			((CEBullet*)pObj)->SetIsCamera(false);
			pObj->SetPos(Vec2(m_vPos.x, m_vPos.y + 80.f));
			((CBullet*)pObj)->SetDegree(m_fAngle + 15.f);
			CStageMgr::GetInst()->PushObj(pObj);
		}

		if (m_fAngle < 240.f)
		{
			fMove = 10.f;
			m_fSpeed = 100.f;
			m_dTime = 0.;
			m_fAngle = 0.f;
			m_bTest = false;
			m_iSelect = (rand() % 3) + 1;
		}
	}
}

void CBoss::StartPattern()
{
	m_vPos.y += m_fSpeed * DT;

	if (m_vPos.y > 250.f)
		m_bStart = false;
}