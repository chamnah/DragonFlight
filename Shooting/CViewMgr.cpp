#include "stdafx.h"
#include "CViewMgr.h"
#include "CView.h"

CViewMgr::CViewMgr()
{
}


CViewMgr::~CViewMgr()
{
}

void CViewMgr::Update()
{
}

void CViewMgr::Render(HDC _hdc)
{
	list<CView*>::iterator iter = m_plistView.begin();
	for (; iter != m_plistView.end(); ++iter)
	{
		(*iter)->render(_hdc);
	}
}