#include "stdafx.h"
#include "CStageOne.h"
#include "CStageLogo.h"
#include "ResMgr.h"
#include "CBackGround.h"
#include "CameraMgr.h"
#include "Player.h"
#include "CMambo.h"
#include "CMeteo.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "CUI.h"
#include "CText.h"
#include "CView.h"
#include "CPBullet.h"
#include "CEBullet.h"
#include "CDragon.h"
#include "Core.h"
#include "CGameMgr.h"
#include "CBoss.h"
#include "CWarning.h"
#include "StageMgr.h"

void CStageOne::Update()
{
	m_dTotalTime += DT;
	m_dTime += DT;

	m_dScoreTime += DT;
	if (m_dScoreTime > 1)
	{
		m_dScoreTime = 0.;
		CGameMgr::GetInst()->AddScore(10);
	}
	static CText* pText = dynamic_cast<CText*>(m_pScore);
	pText->SetText(CGameMgr::GetInst()->GetScore());

	int iState = 0;
	list<CObj*>::iterator iter = m_listObj.begin();

	for (; iter != m_listObj.end();)
	{
		iState = (*iter)->update();
		if (iState == (UINT)OBJ_STATE::DIE)
		{
			delete *iter;
			iter = m_listObj.erase(iter);
			if (iter == m_listObj.end())
				break;
		}
		else if (iState == (UINT)OBJ_STATE::DIE_METEO)
		{
			CObj* pObj = new CMeteo;
			((CBullet*)pObj)->SetPos((*iter)->GetPos());
			m_listObj.push_back(pObj);

			delete *iter;
			iter = m_listObj.erase(iter);
			if (iter == m_listObj.end())
				break;
		}
		else if (iState == (UINT)OBJ_STATE::DIE_BOSS)
		{
			CObj* pObj = new CBoss;
			((CBoss*)pObj)->SetObjAngle(m_pPlayer);
			m_listObj.push_back(pObj);


			delete *iter;
			iter = m_listObj.erase(iter);
			if (iter == m_listObj.end())
				break;
		}
		else
			++iter;
	}

	bool bColl = false;
	list<CObj*>::iterator Colliter1 = m_listObj.begin();

	for (; Colliter1 != m_listObj.end();)
	{
		//if ((*Colliter1)->GetBelong() == BELONG::NONE || (*Colliter1)->GetBelong() == BELONG::UI) // 충돌 처리 필요없는 녀석은 그냥 통과
		//{
		//	++Colliter1;        
		//	continue;
		//}
		bColl = false;
		list<CObj*>::iterator Colliter2 = m_listObj.begin();
		for (; Colliter2 != m_listObj.end(); ++Colliter2)
		{
			//if ((*Colliter2)->GetBelong() == BELONG::NONE || (*Colliter2)->GetBelong() == BELONG::UI || *Colliter1 == *Colliter2) // 충돌 처리 필요없는 녀석은 그냥 통과
			//	continue;

			iState = (*Colliter1)->lateupdate(*Colliter2);
			if (iState == 1) // 일반 적인 충돌
			{
				bColl = true;
				delete *Colliter1;
				Colliter1 = m_listObj.erase(Colliter1);
				break;
			}
			else if (iState == (int)OBJ_STATE::GAME_END) // 플레이어와의 충돌
			{
				CStageMgr::GetInst()->ChangeStage(STAGE::RESULT);
				return;
			}
			else
				bColl = false;
		}

		if (Colliter1 == m_listObj.end())
			break;

		if (!bColl)
			++Colliter1;
	}

	if (m_dTotalTime < 25)
	{
		if (CCameraMgr::GetInst()->GetDifference().y < -(500 + (1000 * m_iSpacing)))
		{
			int iRandom = (rand() % 2);

			if (iRandom == 0)
			{
				CObj* pObj = new CMambo(200, -(700 + (1000 * m_iSpacing)));
				m_listObj.push_back(pObj);

				pObj = new CMambo(500, -(700 + (1000 * m_iSpacing)));
				m_listObj.push_back(pObj);
			}
			else if(iRandom == 1)
			{
				for (int i = 80; i < 700; i += 130) // 드래곤 한줄 솬
				{
					CObj* pObj = new CDragon(i, -(700 + (1000 * m_iSpacing)));
					m_listObj.push_back(pObj);
				}
			}
			m_iSpacing += 1;
		}
	}
	//else if (!(m_IsTime & TimeTwo) && CCameraMgr::GetInst()->GetDifference().y < -1500)
	//{
	//	m_IsTime |= TimeTwo;
	//	
	//}
	//else if (!(m_IsTime & TimeThree) && CCameraMgr::GetInst()->GetDifference().y < -2500)
	//{
	//	m_IsTime |= TimeThree;
	//	for (int i = 80; i < 700; i += 130) // 드래곤 한줄 솬
	//	{
	//		CObj* pObj = new CDragon(i, -2700);
	//		m_listObj.push_back(pObj);
	//	}
	//}
	if (!(m_IsTime & TimeFour) && m_dTotalTime > 30)
	{
		m_IsTime |= TimeFour;
		CObj* pObj = new CWarning;
		m_listObj.push_back(pObj);
	}
	//m_IsTime |= TimeOne;
	// !(m_IsTime & TimeOne)  이 문장은 내가 정해진 시간에 딱 한번만 무언가를 할때 사용하기 위해 만듬 필요하면 쓰셈

	if (m_dTime > 5 && m_dTotalTime < 25)
	{
		m_dTime = 0;
		CObj* pObj = new CUI;
		pObj->SetTexture((CTexture*)CResMgr::GetInst()->Load<CTexture*>(L"WaringMark", L"UI\\WaringMark.bmp"));
		m_listObj.push_back(pObj);
	}


	m_listObj.sort(AscendingSort<CObj*, CObj*>);
}

void CStageOne::Enter()
{
	CCameraMgr::GetInst()->SetSpeed(140.f);
	
	CObj* pObj = new CBackGround;
	pObj->SetTexture((CTexture*)CResMgr::GetInst()->Load<CTexture*>(L"Stage1", L"Back\\Stage1.bmp"));
	m_listObj.push_back(pObj);

	pObj = new CBackGround;
	pObj->SetTexture((CTexture*)CResMgr::GetInst()->Load<CTexture*>(L"Stage1", L"Back\\Stage1.bmp"));
	pObj->SetPos(Vec2(0,-pObj->GetTexture()->GetHeight()));
	m_listObj.push_back(pObj);

	m_pPlayer = new CPlayer;
	m_pPlayer->SetTexture((CTexture*)CResMgr::GetInst()->Load<CTexture*>(L"Player1", L"Character\\Player2.bmp"));
	m_pPlayer->SetPos(Vec2(300.f, CCore::GetInst()->GetResolution().y - 120.f));
	m_listObj.push_back(m_pPlayer);

	m_pScore = new CText;
	m_pScore->SetTexture((CTexture*)CResMgr::GetInst()->Load<CTexture*>(L"Text", L"UI\\Text1.bmp"));
	m_pScore->SetPos(Vec2(10, 10));
	m_listObj.push_back(m_pScore);

	m_listObj.sort(AscendingSort<CObj*,CObj*>);
}

void CStageOne::Exit()
{
	CCameraMgr::GetInst()->SetLook(CCore::GetInst()->GetResolution().x / 2, CCore::GetInst()->GetResolution().y / 2);
	m_dTime = 0.;
	m_IsTime = 0;
	m_pScore = NULL;
	m_dTotalTime = 0.;
	m_iSpacing = 0;
	CGameMgr::GetInst()->BuffClear();
	CStage::Exit();
}

CStageOne::CStageOne()
	:m_dTime(0.),
	m_IsTime(0),
	m_dTotalTime(0.),
	m_iSpacing(0),
	m_dScoreTime(0.)
{
}

CStageOne::~CStageOne()
{
}