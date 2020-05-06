#pragma once
class CStage;
class CObj;
class CStageMgr 
{
	SINGLE(CStageMgr)

private:
	CStage* m_pArrStage[(UINT)STAGE::END];
	CStage* m_pCurStage;
	STAGE   m_eCurState;

public:
	void Init();
	void Update();
	void Render(HDC _dc);
	void ChangeStage(STAGE _eStage);
	void PushObj(CObj* _pObj);
};