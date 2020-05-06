#include "stdafx.h"
#include "CStageLogo.h"
#include "ResMgr.h"
#include "CBackGround.h"
#include "CameraMgr.h"

void CStageLogo::Update()
{
}

void CStageLogo::Enter()
{
	CCameraMgr::GetInst()->SetSpeed(100.f);
	CObj* pObj = new CBackGround;
	pObj->SetTexture((CTexture*)CResMgr::GetInst()->Load<CTexture*>(L"Tiger", L"Image\\tiger.bmp"));
	m_listObj.push_back(pObj);
}

CStageLogo::CStageLogo()
{
}


CStageLogo::~CStageLogo()
{
}