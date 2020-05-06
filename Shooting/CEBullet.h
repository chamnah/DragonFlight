#pragma once
#include "Bullet.h"
class CEBullet :
	public CBullet
{
public:
	bool  m_bCamera;
	virtual int update();

public:
	void SetIsCamera(bool _bCam) { m_bCamera = _bCam; }

public:
	CEBullet();
	virtual ~CEBullet();
};

