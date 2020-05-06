#include "stdafx.h"
#include "CGameMgr.h"
#include "CView.h"
#include "ResMgr.h"
#include "CText.h"

CGameMgr::CGameMgr()
	:m_iScore(0),
	m_pText(NULL),
	m_wstrScore(L"SCORE 0")
{
}


CGameMgr::~CGameMgr()
{
	BuffClear();
}

void CGameMgr::AddScore(const int _iScore)
{
	m_iScore += _iScore;
	wchar_t wszScore[50] = L"";
	wsprintf(wszScore, L"SCORE %d", m_iScore);
	m_wstrScore = wszScore;
}

void CGameMgr::SetScore(int _iScore)
{
	m_iScore = _iScore;
	wchar_t wszScore[50] = L"";
	wsprintf(wszScore, L"SCORE %d", m_iScore);
	m_wstrScore = wszScore;
}

void CGameMgr::BuffPush(CView * pView)
{
	if (pView->GetItem() == ITEM_INVINCIBLE)
	{
		m_pText = new CText;
		m_pText->SetPos(Vec2(600,50));
		m_pText->SetText(L"x2");
	}
	int iSpacing = 100 * m_listBuff.size();
	pView->SetPos(Vec2(600,200 + iSpacing));
	m_listBuff.push_back(pView);
}

void CGameMgr::Render(HDC hdc)
{
	list<CView*>::iterator iter = m_listBuff.begin();
	for(;iter != m_listBuff.end();++iter)
	{
		(*iter)->render(hdc);
	}

	if(m_pText)
	m_pText->render(hdc);
}

void CGameMgr::BuffRemove(UINT _Item)
{
	if (_Item == ITEM_INVINCIBLE)
	{
		delete m_pText;
		m_pText = NULL;
	}

	list<CView*>::iterator iter = m_listBuff.begin();
	for (; iter != m_listBuff.end();)
	{
		if ((*iter)->GetItem() == _Item)
		{
			delete *iter;
			iter = m_listBuff.erase(iter);
			 break;
		}
		else
			++iter;
	}
	
	int i = 0;
	list<CView*>::iterator iter2 = m_listBuff.begin();
	for (; iter2 != m_listBuff.end(); ++iter2)
	{
		(*iter2)->SetPos(Vec2(600, 200 +(100 * i)));
		++i;
	}
}

void CGameMgr::BuffClear()
{
	list<CView*>::iterator iter = m_listBuff.begin();
	for (; iter != m_listBuff.end();)
	{
		delete *iter;
		iter = m_listBuff.erase(iter);

		if (iter == m_listBuff.end())
			break;
	}

	if (m_pText)
	{
		delete m_pText;
		m_pText = NULL;
	}
}