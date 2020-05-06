#pragma once
#include "Obj.h"
class CDynamicObj :
	public CObj
{
protected:
	float	m_fSpeed;

public:
	virtual float GetSpeed() { return m_fSpeed; };
	virtual void SetSpeed(float _fSpeed) { m_fSpeed = _fSpeed; }
	virtual void render(HDC _dc);

public:
	CDynamicObj();
	virtual ~CDynamicObj();
};