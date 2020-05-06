#pragma once
#include "DynamicObj.h"
class CMonster :
	public CDynamicObj
{
protected:
	float m_fHP;
	float m_fMaxHP;
	Vec2 m_vRealPos;
protected:
	CTexture* m_pTexInHP;
	CTexture* m_pTexBackHP;
	float m_fHeight;

public:
	virtual int update();
	virtual void render(HDC _dc);
	virtual int lateupdate(CObj* _pObj);
public:
	const float GetHP() { return m_fHP; }
	void SetHP(const float _fhp) { m_fHP = _fhp; }
	void Damage(const float _fdamage) { m_fHP -= _fdamage; }
public:
	CMonster();
	virtual ~CMonster();
};