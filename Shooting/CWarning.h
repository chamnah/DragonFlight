#pragma once
#include "Obj.h"
class CWarning :
	public CObj
{
private:
	CTexture* m_pTex2;
	Vec2      m_vLeft;
	float     m_fSpeed;
	double    m_dTime;

public:
	virtual int update();
	virtual void render(HDC _dc);

public:
	CWarning();
	virtual ~CWarning();
};

