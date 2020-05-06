#include "stdafx.h"
#include "CMonster.h"
#include "ResMgr.h"
#include "CBoom.h"
#include "StageMgr.h"
#include "Core.h"
#include "CameraMgr.h"
#include "CItem.h"
#include "time.h"
#include "Player.h"
#include "CGameMgr.h"

int CMonster::update()
{
	m_vPos = CCameraMgr::GetInst()->GetRealPos(m_vRealPos.x, m_vRealPos.y);
	return (int)OBJ_STATE::NONE;
}

void CMonster::render(HDC _dc)
{
	TransparentBlt(_dc, int(m_vPos.x - m_pTex->GetWidth() / 2), int(m_vPos.y - m_pTex->GetHeight() / 2), m_pTex->GetWidth(), m_pTex->GetHeight(), m_pTex->GetDC(), 0, 0, m_pTex->GetWidth(), m_pTex->GetHeight(), RGB(0, 0, 0));
	TransparentBlt(_dc, int(m_vPos.x - m_pTexBackHP->GetWidth() / 2), int(m_vPos.y + m_fHeight), m_pTexBackHP->GetWidth(), m_pTexBackHP->GetHeight(), m_pTexBackHP->GetDC(), 0, 0, m_pTexBackHP->GetWidth(), m_pTexBackHP->GetHeight(), RGB(0, 0, 0));
	TransparentBlt(_dc, int(m_vPos.x - m_pTexInHP->GetWidth() / 2), int(m_vPos.y + m_fHeight), int((m_pTexInHP->GetWidth() / m_fMaxHP) * m_fHP), m_pTexInHP->GetHeight(), m_pTexInHP->GetDC(), 0, 0, int((m_pTexInHP->GetWidth() / m_fMaxHP) * m_fHP), m_pTexInHP->GetHeight(), RGB(0, 0, 0));
}

int CMonster::lateupdate(CObj* _pObj)
{

	if (m_fHP <= 0)
	{
		CObj* pObj = new CItem(ITEM(rand() % int(ITEM::END)), m_vPos);
		CStageMgr::GetInst()->PushObj(pObj);

		pObj = new CBoom;
		pObj->SetPos(m_vPos);
		CStageMgr::GetInst()->PushObj(pObj);
		CGameMgr::GetInst()->AddScore(50);
		return (int)OBJ_STATE::DIE;
	}
	else if (m_vPos.y - m_pTex->GetHeight() / 2 >= CCore::GetInst()->GetResolution().y)
	{
		return (int)OBJ_STATE::DIE;
	}

	if (m_vPos.y <= 0)
		return (int)OBJ_STATE::NONE;

	if (CollisionRect(this, _pObj))
	{
		if (_pObj->GetBelong() == BELONG::PLAYER)
		{
			if (((CPlayer*)_pObj)->GetItem() & ITEM_INVINCIBLE)
			{
				CObj* pObj = new CItem(ITEM(rand() % int(ITEM::END)), m_vPos);
				CStageMgr::GetInst()->PushObj(pObj);

				pObj = new CBoom;
				pObj->SetPos(m_vPos);
				CStageMgr::GetInst()->PushObj(pObj);

				CGameMgr::GetInst()->AddScore(100);
				return (int)OBJ_STATE::DIE;
			}
			else if(((CPlayer*)_pObj)->GetIvisible() == false)
			{
				return (int)OBJ_STATE::GAME_END;
			}
		}
	}
	return (int)OBJ_STATE::NONE;
}

CMonster::CMonster()
	:m_fHP(100.f),
	m_fHeight(65.f)
{
	m_fMaxHP = m_fHP;
	m_pTexBackHP = (CTexture*)CResMgr::GetInst()->Load<CTexture*>(L"HP_in", L"UI\\HP_back.bmp");
	m_pTexInHP = (CTexture*)CResMgr::GetInst()->Load<CTexture*>(L"HP_back", L"UI\\HP_in.bmp");
	m_eBelong = BELONG::MONSTER;
}

CMonster::~CMonster()
{
}