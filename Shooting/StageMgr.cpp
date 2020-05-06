#include "stdafx.h"
#include "StageMgr.h"
#include "CStageLogo.h"
#include "CStageOne.h"
#include "CStageResult.h"

CStageMgr::CStageMgr()
{
}


CStageMgr::~CStageMgr()
{
	int size = sizeof(m_pArrStage) / 4;

	for (int i = 0; i < size; ++i)
	{
		delete m_pArrStage[i];
	}
}

void CStageMgr::Init()
{
	m_pArrStage[(UINT)STAGE::LOGO] = new CStageLogo;
	m_pArrStage[(UINT)STAGE::ONE] = new CStageOne;
	m_pArrStage[(UINT)STAGE::RESULT] = new CStageResult;
	m_pCurStage = m_pArrStage[(UINT)STAGE::ONE];
	m_pCurStage->Enter();
}

void CStageMgr::Update()
{
	m_pCurStage->Update();
}

void CStageMgr::Render(HDC _dc)
{
	m_pCurStage->Render(_dc);
}

void CStageMgr::ChangeStage(STAGE _eStage)
{
	if (m_eCurState == _eStage)
		return;

	m_pCurStage->Exit();
	m_pCurStage = m_pArrStage[(UINT)_eStage];
	m_pCurStage->Enter();
}

void CStageMgr::PushObj(CObj * _pObj)
{
	if(_pObj)
	m_pCurStage->GetObj().push_back(_pObj);
}