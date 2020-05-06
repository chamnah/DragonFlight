#pragma once
#include "CStage.h"
class CStageResult :
	public CStage
{

public:
	virtual void Update();
	virtual void Enter();

public:
	CStageResult();
	virtual ~CStageResult();
};