#include "stdafx.h"
#include "Core.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "ResMgr.h"
#include "Texture.h"
#include "PathMgr.h"
#include "StageMgr.h"
#include "CameraMgr.h"
#include "time.h"
#include "CGameMgr.h"

CCore::CCore()
	: m_hWnd(NULL)
	, m_hDC(NULL)
	, m_hBit(NULL)
{
}

CCore::~CCore()
{
	ReleaseDC(m_hWnd, m_hDC);
	DeleteObject(m_hBit);
	DeleteDC(m_memDC);
}

void CCore::init(HWND _hWnd)
{
	srand((UINT)time(NULL));
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	m_hWnd = _hWnd;		   // ���� ������ �ڵ�
	m_hDC = GetDC(m_hWnd); // ���� ������ DC 
		
	// ���� �۾����� ����� ������� ������ ������ ũ�⸦ ������ִ� �Լ�
	ChageWindowSize(500, 10, 691, 922);	

	// ī�� ������ ���� �����
	m_hBit = CreateCompatibleBitmap(m_hDC, (int)m_vResolution.x, (int)m_vResolution.y); // ���� ������ �� ������ ũ���� ��Ʈ�� �̹��� ���۸� ����.
	m_memDC = CreateCompatibleDC(m_hDC);			   // �޸� ��Ʈ�ʰ� ��������� DC �ϳ� ����
	HBITMAP oldBit = (HBITMAP)SelectObject(m_memDC, m_hBit); // DC �� Bitmap �� �����ϰ�, DC �� ������ �ִ� ���� ��Ʈ���� ����
	DeleteObject(oldBit);								// DC �� ������ �ִ� ���� Bitmap �� ������

	// Manager �ʱ�ȭ
	CKeyMgr::GetInst()->init();
	CTimeMgr::GetInst()->init();
	CPathMgr::init();
	CStageMgr::GetInst()->Init();
	CCameraMgr::GetInst()->SetLook(m_vResolution.x / 2, m_vResolution.y / 2);
}

UINT CCore::progress()
{	
	update();
	render();
	return 0;
}

void CCore::ChageWindowSize(UINT _iLeft, UINT _iTop, UINT _iWidth, UINT _iHeight)
{
	RECT rt{ 0,	0,	(int)_iWidth, (int)_iHeight };
	UINT iStyle = GetWindowLong(m_hWnd, GWL_STYLE);
	AdjustWindowRect(&rt, iStyle, false);

	SetWindowPos(m_hWnd, NULL, _iLeft, _iTop, rt.right - rt.left, rt.bottom - rt.top, 0);
	ShowWindow(m_hWnd, true);

	m_vResolution.x = (float)_iWidth;
	m_vResolution.y = (float)_iHeight;
}

int CCore::update()
{
	CKeyMgr::GetInst()->update();
	CTimeMgr::GetInst()->update();
	CStageMgr::GetInst()->Update();
	CCameraMgr::GetInst()->update();

	return 0;
}

void CCore::render()
{
	// ȭ�� �����
	Rectangle(m_memDC, -1, -1, (int)m_vResolution.x + 1, (int)m_vResolution.y + 1);
	CStageMgr::GetInst()->Render(m_memDC);
	CGameMgr::GetInst()->Render(m_memDC);
	//CTimeMgr::GetInst()->render(m_memDC);
	BitBlt(m_hDC, 0, 0, (int)m_vResolution.x, (int)m_vResolution.y, m_memDC, 0, 0, SRCCOPY);
}