#pragma once
#include "DynamicObj.h"

class CBullet :
	public CDynamicObj
{
protected:
	int   m_iDamage;
	float m_fAngle;
	Vec2 m_vRealPos;

public:
	virtual int update();
	virtual void render(HDC _dc);
	virtual int lateupdate(CObj* _pObj);
	virtual void SetDegree(float _fAngle);
	virtual void SetRadian(float _fAngle);
	virtual void SetRealPos(Vec2 _vPos) { m_vRealPos = _vPos; }

public:
	CBullet();
	virtual ~CBullet();
};