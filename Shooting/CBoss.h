#pragma once
#include "CMonster.h"
class CBoss :
	public CMonster
{
private:
	double m_dTime;
	double m_dTotalTime;
	double m_dBreakTime;
	short  m_sNumber;
	UINT   m_iSelect;
	float  m_fAngle;
	CObj*  m_pObj;
	bool   m_bStart;
	bool   m_bTest;  // 한번만 보여주고 지울 것
	bool   m_bOne;
	Vec2   m_vTempPos;

public:
	virtual int update();
	virtual int lateupdate(CObj* _pObj);
	void SetObjAngle( CObj* _pObj) { m_pObj = _pObj; }

	void PatternOne();
	void PatternTwo();
	void PatternThree();
	void StartPattern();

public:
	CBoss();
	virtual ~CBoss();
};