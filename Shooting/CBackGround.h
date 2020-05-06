#pragma once
#include "DynamicObj.h"
class CBackGround :
	public CDynamicObj
{
private:
	Vec2 m_vMovePos;

public:
	virtual int update();
	virtual void render(HDC _dc);

public:
	CBackGround();
	virtual ~CBackGround();
};