#pragma once
#include "Bullet.h"
class CPBullet :
	public CBullet
{
public:
	virtual int update();

public:
	CPBullet();
	virtual ~CPBullet();
};

