#include "stdafx.h"
#include "CBackGround.h"
#include "CameraMgr.h"
#include "Core.h"

CBackGround::CBackGround()
	:m_vMovePos(Vec2(0,0))
{
	m_eBelong = BELONG::NONE;
}


CBackGround::~CBackGround()
{
}

int CBackGround::update()
{
	// ���� �����̴� ��ǥ�� ������ ����� ���� ���� ��ǥ�� �ٲ۴�.
	if (m_vMovePos.y >= CCore::GetInst()->GetResolution().y)
	{
		m_vPos.y -= (CCore::GetInst()->GetResolution().y * 2);
	}
	return 0;
}

void CBackGround::render(HDC _dc)
{
	m_vMovePos = CCameraMgr::GetInst()->GetRealPos(m_vPos.x, m_vPos.y);
	BitBlt(_dc, m_vMovePos.x, m_vMovePos.y, m_pTex->GetWidth(), m_pTex->GetHeight(), m_pTex->GetDC(), 0, 0, SRCCOPY);
}     