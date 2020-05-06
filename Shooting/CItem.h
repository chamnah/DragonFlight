#pragma once
#include "DynamicObj.h"
class CItem : public CDynamicObj
{
private:
	UINT m_iItem;
	Vec2 m_vRealPos;
	float m_fAcc;
	float	m_fDir;
	bool   m_bFollow;
public:
	virtual int update();
	virtual int lateupdate(CObj* _pObj);

public:
	CItem();
	CItem(ITEM _iItem, Vec2& _vPos);
	virtual ~CItem();
};