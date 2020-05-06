#pragma once
#include "Obj.h"
class CTile :
	public CObj
{

public:
	virtual int update();
	virtual void render(HDC _dc);
public:
	CTile();
	CTile(Vec2 _pos,float _size);
	virtual ~CTile();
};