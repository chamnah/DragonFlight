#pragma once
#include "CStage.h"
class CView;
class CStageOne :
	public CStage
{
private:
	double m_dTotalTime;
	double m_dTime;
	double m_dScoreTime;
	int    m_IsTime;
	CObj* m_pScore;
	int   m_iSpacing;

public:
	virtual void Update();
	virtual void Enter();
	virtual void Exit();

public:
	CStageOne();
	virtual ~CStageOne();
};