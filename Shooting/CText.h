#pragma once
#include "Obj.h"
class CText :
	public CObj
{
private:
	wstring m_wstrText;
	static tTextPos m_tPos[(UINT)TEXT::END];
	UINT    m_iSize;
	UINT    m_iSpacing;
public:
	virtual int update();
	virtual void render(HDC _dc);

public:
	void SetText(wstring _wstr) { m_wstrText = _wstr; }

public:
	CText();
	virtual ~CText();
};