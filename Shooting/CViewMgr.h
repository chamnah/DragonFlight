#pragma once
class CView;
class CViewMgr
{
	SINGLE(CViewMgr);
private:
	list<CView*> m_plistView;

public:
	void Update();
	void Render(HDC _hdc);

};