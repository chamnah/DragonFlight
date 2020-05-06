#include "stdafx.h"
#include "CItem.h"
#include "ResMgr.h"
#include "CameraMgr.h"
#include "TimeMgr.h"
#include "Player.h"

CItem::CItem()
	:m_fAcc(10.f),
	m_fDir(90.f)
{
	m_vScale.left = 20.f;
	m_vScale.right = 20.f;
	m_vScale.top = 20.f;
	m_vScale.bottom = 20.f;
	m_fSpeed = 100.f;
	m_eBelong = BELONG::ITEM;
}

CItem::CItem(ITEM _iItem,Vec2& _vPos)
	:m_fAcc(100.f)
	, m_fDir(PI / 2)
	, m_bFollow(false)
{
	m_vPos = _vPos;

	if (_iItem == ITEM::DUAL)
	{
		m_iItem = ITEM_DUAL;
		m_pTex = (CTexture*)CResMgr::GetInst()->Load<CTexture*>(L"DUAL", L"Item\\Dual.bmp");
	}
	else if (_iItem == ITEM::MAGNET)
	{
		m_iItem = ITEM_MAGNET;
		m_pTex = (CTexture*)CResMgr::GetInst()->Load<CTexture*>(L"MAGNET", L"Item\\Magnet.bmp");
	}
	else if (_iItem == ITEM::INVINCIBLE)
	{
		m_iItem = ITEM_INVINCIBLE;
		m_pTex = (CTexture*)CResMgr::GetInst()->Load<CTexture*>(L"INVINCIBLE", L"Item\\Invincible.bmp");
	}

	m_vScale = tRect(50,50,50,50);

	m_eBelong = BELONG::ITEM;

	m_fSpeed = 150.f;
}

CItem::~CItem()
{
}

int CItem::update()
{
	if (!m_bFollow)
	{
		m_fDir = PI / 2;
		m_fAcc -= 80 * (float)DT;
		m_vPos.x += m_fAcc * cosf(m_fDir) * (float)DT;
		m_vPos.y -= m_fAcc * sinf(m_fDir) * (float)DT;
		//m_vPos = CCameraMgr::GetInst()->GetRealPos(m_vRealPos.x, m_vRealPos.y); // ���� ���⼭ ������ ����� ���� ���� ���� ó�� pos �� ������ �ξ� ���� ��ġ����
	}
	else
	{
		m_vPos.x += m_fSpeed * cosf(m_fDir) * (float)DT;
		m_vPos.y -= m_fSpeed * sinf(m_fDir) * (float)DT;
		m_bFollow = false;
	}
	return 0;																// �� �������� Ǫ���� ��ġ�� �����Ƿ� ���̰� �����.
}

int CItem::lateupdate(CObj * _pObj) // �̰� �ڵ� ��ġ�� �Ź� ���鼭 �˻��ϴ��� �׳� ������ Obj�� �������°� �ξ� ������ �ʹ�.
{
	if (_pObj->GetBelong() == BELONG::PLAYER)
	{
		if (((CPlayer*)_pObj)->GetItem() & ITEM_MAGNET && OppDistance(this, _pObj) < 300.f)
		{
			m_fDir = OppAngle(this, _pObj);
			m_bFollow = true;
		}
		if (CollisionRect(this, _pObj))
		{
			((CPlayer*)_pObj)->SetItem(m_iItem);
			return (int)OBJ_STATE::DIE;
		}
	}
	return (int)OBJ_STATE::NONE;
}