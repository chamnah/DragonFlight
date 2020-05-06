#include "stdafx.h"
#include "Player.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "Core.h"
#include "CPBullet.h"
#include "StageMgr.h"
#include "ResMgr.h"
#include "CameraMgr.h"
#include "CGameMgr.h"
#include "CView.h"

CPlayer::CPlayer()
	: m_iItem(0),
	m_dItemTime{0},
	m_bInvisible(false),
	m_dInviTime(0.)
{
	m_fSpeed = 400.f;
	m_vScale = tRect(25,60,20,5);
	m_eBelong = BELONG::PLAYER;
	m_pTexEffect = (CTexture*)CResMgr::GetInst()->Load<CTexture*>(L"2", L"Effect\\12.bmp");

	m_iDuration[(UINT)ITEM::DUAL] = 3;
	m_iDuration[(UINT)ITEM::INVINCIBLE] = 3;
	m_iDuration[(UINT)ITEM::MAGNET] = 3;
}

CPlayer::~CPlayer()
{
}

int CPlayer::update()
{
	TimeCheck();

	if (CKeyMgr::GetInst()->GetKeyState(KEY_TYPE::KEY_LEFT, KEY_STATE::HOLD))
	{
		m_vPos.x -= m_fSpeed * (float)DT;
	}
	if (CKeyMgr::GetInst()->GetKeyState(KEY_TYPE::KEY_RIGHT, KEY_STATE::HOLD))
	{
		m_vPos.x += m_fSpeed * (float)DT;
	}

	if ((m_iItem & ITEM_INVINCIBLE) == 0 && CKeyMgr::GetInst()->GetKeyState(KEY_TYPE::KEY_SPACE, KEY_STATE::AWAY))
	{
		if (m_iItem & ITEM_DUAL)
		{
			CObj* pObj = new CPBullet;
			pObj->SetPos(Vec2(m_vPos.x - 20,m_vPos.y));
			CStageMgr::GetInst()->PushObj(pObj);
			
			pObj = new CPBullet;
			pObj->SetPos(Vec2(m_vPos.x + 10, m_vPos.y));
			CStageMgr::GetInst()->PushObj(pObj);
		}
		else
		{
			CObj* pObj = new CPBullet;
			pObj->SetPos(m_vPos);
			CStageMgr::GetInst()->PushObj(pObj);
		}
	}



	return 0;
}

void CPlayer::render(HDC _dc)
{
	if((m_iItem & ITEM_INVINCIBLE))
	TransparentBlt(_dc, int(m_vPos.x - m_pTexEffect->GetWidth() / 2), int(m_vPos.y + 30 - m_pTexEffect->GetHeight() / 2), m_pTexEffect->GetWidth(), m_pTexEffect->GetHeight(), m_pTexEffect->GetDC(), 0, 0, m_pTexEffect->GetWidth(), m_pTexEffect->GetHeight(), RGB(0, 0, 0));
	TransparentBlt(_dc, int(m_vPos.x - m_pTex->GetWidth() / 2), int(m_vPos.y - m_pTex->GetHeight() / 2), m_pTex->GetWidth(), m_pTex->GetHeight(),m_pTex->GetDC(),0,0, m_pTex->GetWidth(), m_pTex->GetHeight(),RGB(0,0,0));
}

int CPlayer::lateupdate(CObj* _pObj)
{	
	if (m_vPos.x + m_vScale.right / 2 >= CCore::GetInst()->GetResolution().x)
	{
		m_vPos.x -= (m_vPos.x + m_vScale.right / 2) - CCore::GetInst()->GetResolution().x;
	}
	else if (m_vPos.x - m_vScale.left / 2 <= 0)
	{
		m_vPos.x += -(m_vPos.x - m_vScale.left / 2);
	}

	return 0;
}

void CPlayer::TimeCheck()
{
	if (m_iItem & ITEM_DUAL)
	{
		m_dItemTime[(UINT)ITEM::DUAL] += DT;
		if (m_dItemTime[(UINT)ITEM::DUAL] > m_iDuration[(UINT)ITEM::DUAL])
		{
			CGameMgr::GetInst()->BuffRemove(ITEM_DUAL);
			m_iItem ^= ITEM_DUAL;
			m_dItemTime[(UINT)ITEM::DUAL] = 0.;
		}
	}
	
	if (m_iItem & ITEM_MAGNET)
	{
		m_dItemTime[(UINT)ITEM::MAGNET] += DT;
		if (m_dItemTime[(UINT)ITEM::MAGNET] > m_iDuration[(UINT)ITEM::MAGNET])
		{
			CGameMgr::GetInst()->BuffRemove(ITEM_MAGNET);
			m_iItem ^= ITEM_MAGNET;
			m_dItemTime[(UINT)ITEM::MAGNET] = 0.;
		}
	}

	if (m_iItem & ITEM_INVINCIBLE)
	{
		m_dItemTime[(UINT)ITEM::INVINCIBLE] += DT;
		CCameraMgr::GetInst()->SetSpeed(1400.f);
		if (m_dItemTime[(UINT)ITEM::INVINCIBLE] > m_iDuration[(UINT)ITEM::INVINCIBLE])
		{
			CGameMgr::GetInst()->BuffRemove(ITEM_INVINCIBLE);
			m_bInvisible = true;
			CCameraMgr::GetInst()->SetSpeed(140.f);
			m_iItem ^= ITEM_INVINCIBLE;
			m_dItemTime[(UINT)ITEM::INVINCIBLE] = 0.;
		}
	}

	if (m_bInvisible)
	{
		m_dInviTime += DT;
		if (m_dInviTime > 1)
		{
			m_dInviTime = 0.;
			m_bInvisible = false;
		}
	}
}

void CPlayer::SetItem(UINT _iItem)
{
	if ((m_iItem & _iItem) == 0)
	{
		CView* pView = new CView;
		pView->SetItem(_iItem);

		if (_iItem == ITEM_DUAL)
			pView->SetTexture((CTexture*)CResMgr::GetInst()->Load<CTexture*>(L"DUAL", L"Item\\Dual.bmp"));
		else if (_iItem == ITEM_MAGNET)
			pView->SetTexture((CTexture*)CResMgr::GetInst()->Load<CTexture*>(L"MAGNET", L"Item\\Magnet.bmp"));
		else if (_iItem == ITEM_INVINCIBLE)
			pView->SetTexture((CTexture*)CResMgr::GetInst()->Load<CTexture*>(L"INVINCIBLE", L"Item\\Invincible.bmp"));

		CGameMgr::GetInst()->BuffPush(pView);
		m_iItem |= _iItem;
	}
	else
	{
		if (_iItem == ITEM_DUAL)
			m_dItemTime[(UINT)ITEM::DUAL] = 0.;
		else if (_iItem == ITEM_MAGNET)
			m_dItemTime[(UINT)ITEM::MAGNET] = 0.;
		else if (_iItem == ITEM_INVINCIBLE)
			m_dItemTime[(UINT)ITEM::INVINCIBLE] = 0.;
	}
}