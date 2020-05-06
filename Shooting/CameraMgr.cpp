#include "stdafx.h"
#include "CameraMgr.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "Core.h"

CCameraMgr::CCameraMgr()
	:m_fSpeed(10)
{
	m_vDiff.x = 0.f;
}


CCameraMgr::~CCameraMgr()
{
}

void CCameraMgr::update()
{
	m_vLook.y -= m_fSpeed * (float)DT;
	m_vDiff.y = m_vLook.y - CCore::GetInst()->GetResolution().y / 2;
}