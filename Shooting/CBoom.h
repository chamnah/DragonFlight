#pragma once
#include "Obj.h"
class CBoom :
	public CObj
{
private:
	double m_dTime;
	double m_dTotalTime;

public:
	virtual int update();
	virtual void render(HDC _dc);

public:
	CBoom();
	virtual ~CBoom();
};