#include "stdafx.h"
#include "CStage.h"
#include "Obj.h"
#include "KeyMgr.h"

void CStage::Exit()
{
	list<CObj*>::iterator iter = m_listObj.begin();
	for (; iter != m_listObj.end();)
	{
		delete *iter;
		iter = m_listObj.erase(iter);
		if (iter == m_listObj.end())
			break;
	}
}

void CStage::Render(HDC _hdc)
{
	list<CObj*>::iterator iter = m_listObj.begin();
	for (; iter != m_listObj.end(); ++iter)
	{
		(*iter)->render(_hdc);
	}

	if (CKeyMgr::GetInst()->GetKeyState(KEY_TYPE::KEY_1, KEY_STATE::TAB))
	{
		m_bDebug = !m_bDebug;
	}
	if (m_bDebug)
	{
		list<CObj*>::iterator iter = m_listObj.begin();
		for (; iter != m_listObj.end(); ++iter)
		{
			(*iter)->CollRender(_hdc);
		}
	}
}

CStage::CStage()
	:m_bDebug(false)
{
}

CStage::~CStage()
{
	list<CObj*>::iterator iter = m_listObj.begin();
	
	for (; iter != m_listObj.end(); ++iter)
	{
		delete *iter;
	}
	
	m_listObj.clear();
}