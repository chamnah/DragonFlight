#pragma once
#include "Obj.h"
class CView : public CObj
{
private:
	bool  m_bBlt;
	UINT  m_iItem;

public:
	virtual int update();
	virtual void render(HDC _dc);

public:
	void SetBlt(bool _bBlt) { m_bBlt = _bBlt; }
	void SetItem(UINT _item) { m_iItem = _item; }
	UINT GetItem() { return m_iItem; }

public:
	CView();
	virtual ~CView();
};