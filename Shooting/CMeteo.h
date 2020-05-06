#pragma once
#include "Bullet.h"
class CMeteo :
	public CBullet
{
public:
	virtual int update();

public:
	CMeteo();
	virtual ~CMeteo();
};

