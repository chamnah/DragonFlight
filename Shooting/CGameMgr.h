#pragma once
class CView;
class CText;
class CGameMgr
{
	SINGLE(CGameMgr)

private:
	wstring   m_wstrScore;
	int       m_iScore;
	list<CView*> m_listBuff;
	CText*	  m_pText;

public:
	const wstring& GetScore() { return m_wstrScore; }
	void  AddScore(const int _iScore);
	void SetScore(wstring _wstrScore) { m_wstrScore = _wstrScore; }
	void SetScore(int _iScore);
	void BuffPush(CView* pView);
	void Render(HDC hdc);
	void BuffRemove(UINT _Item);
	void BuffClear();
};