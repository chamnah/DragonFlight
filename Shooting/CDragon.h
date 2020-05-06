#pragma once
#include "CMonster.h"
class CDragon :
	public CMonster
{
public:
	CDragon();
	CDragon(float _fX,float _fY);
	virtual ~CDragon();
};