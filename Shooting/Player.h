#pragma once
#include "DynamicObj.h"

class CPlayer :
	public CDynamicObj
{
private:
	UINT    m_iItem;
	CTexture* m_pTexEffect;
	double  m_dItemTime[(UINT)ITEM::END];
	UINT   m_iDuration[(UINT)ITEM::END];
	bool   m_bInvisible;
	double m_dInviTime;

public:
	virtual int update();
	virtual void render(HDC _dc);
	virtual int lateupdate(CObj* _pObj);

public:
	void TimeCheck();

public:
	void SetItem(UINT _iItem);
	UINT GetItem() { return m_iItem; }
	bool GetIvisible() { return m_bInvisible; }

public:
	CPlayer();
	virtual ~CPlayer();
};