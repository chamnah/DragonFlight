#pragma once
#include "CMonster.h"
class CMambo :
	public CMonster
{
private:
	double m_dTime;

public:
	virtual int update();

public:
	CMambo();
	CMambo(float _fX,float _fY);
	virtual ~CMambo();
};