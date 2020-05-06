#pragma once
#include "CStage.h"
class CStageLogo : public CStage
{
public:
	virtual void Update();
	virtual void Enter();
public:
	CStageLogo();
	virtual ~CStageLogo();
};