#pragma once
#include "Obj.h"
class CUI :
	public CObj
{
private:
	double m_dTime;

public:
	virtual int update();
	virtual void render(HDC _dc);

public:
	CUI();
	virtual ~CUI();
};