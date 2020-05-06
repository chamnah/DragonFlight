#include "stdafx.h"
#include "Bullet.h"
#include "Core.h"
#include "CMonster.h"
#include "StageMgr.h"
#include "Player.h"
#include "CBoom.h"

CBullet::CBullet()
	:m_iDamage(0),
	m_fAngle(0),
	m_vRealPos{}
{


}

CBullet::~CBullet()
{
}

int CBullet::update()
{
	return (int)OBJ_STATE::NONE;
}

void CBullet::render(HDC _dc)
{
	TransparentBlt(_dc, m_vPos.x - m_pTex->GetWidth() / 2, m_vPos.y - m_pTex->GetHeight() / 2, m_pTex->GetWidth(), m_pTex->GetHeight(), m_pTex->GetDC(), 0, 0, m_pTex->GetWidth(), m_pTex->GetHeight(), RGB(0, 0, 0));
}

int CBullet::lateupdate(CObj* _pObj)
{
	if (m_vPos.x - m_pTex->GetWidth() / 2 >= CCore::GetInst()->GetResolution().x)
	{
		return (int)OBJ_STATE::DIE;
	}
	else if (m_vPos.x + m_pTex->GetWidth() / 2 <= 0)
	{
		return (int)OBJ_STATE::DIE;
	}
	else if (m_vPos.y - m_pTex->GetHeight() / 2 >= CCore::GetInst()->GetResolution().y)
	{
		return (int)OBJ_STATE::DIE;
	}
	else if (m_vPos.y + m_pTex->GetHeight() / 2 <= 0)
	{
		return (int)OBJ_STATE::DIE;
	}

	if (CollisionRect(this, _pObj))
	{
		if (m_eBelong == BELONG::PBULLET && _pObj->GetBelong() == BELONG::MONSTER)
		{
			((CMonster*)_pObj)->Damage(m_iDamage);
			return (int)OBJ_STATE::DIE;
		}
		else if ((m_eBelong == BELONG::MBULLET || m_eBelong == BELONG::METEO) && _pObj->GetBelong() == BELONG::PLAYER)
		{
			if (((CPlayer*)_pObj)->GetItem() & ITEM_INVINCIBLE)
			{
				if (m_eBelong == BELONG::METEO)
				{
					CObj* pObj = new CBoom;
					pObj->SetPos(m_vPos);
					CStageMgr::GetInst()->PushObj(pObj);
				}
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

void CBullet::SetDegree(float _fAngle)
{
	m_fAngle = DegreeToRadian(_fAngle);
}

void CBullet::SetRadian(float _fAngle)
{
	m_fAngle = _fAngle;
}