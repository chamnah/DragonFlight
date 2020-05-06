#include "stdafx.h"
#include "CStageResult.h"
#include "CView.h"
#include "ResMgr.h"
#include "Core.h"
#include "CText.h"
#include "KeyMgr.h"
#include "StageMgr.h"
#include "CGameMgr.h"

void CStageResult::Update()
{
	if (CKeyMgr::GetInst()->GetKeyState(KEY_TYPE::KEY_ENTER, KEY_STATE::TAB))
	{
		CGameMgr::GetInst()->SetScore(0);
		CStageMgr::GetInst()->ChangeStage(STAGE::ONE);
	}
}

void CStageResult::Enter()
{
	CObj* pObj = new CView;
	((CView*)pObj)->SetBlt(true);
	pObj->SetTexture((CTexture*)CResMgr::GetInst()->Load<CTexture*>(L"Stage2", L"Back\\Stage2.bmp"));
	m_listObj.push_back(pObj);

	pObj = new CView;
	pObj->SetTexture((CTexture*)CResMgr::GetInst()->Load<CTexture*>(L"Complete", L"UI\\Complete.bmp"));
	pObj->SetPos(Vec2(CCore::GetInst()->GetResolution().x / 4, 50.f));
	m_listObj.push_back(pObj);

	pObj = new CView;
	pObj->SetTexture((CTexture*)CResMgr::GetInst()->Load<CTexture*>(L"Result", L"UI\\Result.bmp"));
	pObj->SetPos(Vec2(CCore::GetInst()->GetResolution().x / 4, 200.f));
	m_listObj.push_back(pObj);

	pObj = new CText;
	pObj->SetPos(Vec2(CCore::GetInst()->GetResolution().x / 3, 700.f));
	((CText*)pObj)->SetText(L"ENTER");
	m_listObj.push_back(pObj);

	pObj = new CText;
	pObj->SetPos(Vec2(200, 650));
	((CText*)pObj)->SetText(CGameMgr::GetInst()->GetScore());
	m_listObj.push_back(pObj);
}

CStageResult::CStageResult()
{
}

CStageResult::~CStageResult()
{
}