#pragma once
class CObj;
class CStage
{

protected:
	list<CObj*> m_listObj; // 바꾼이유 나는 중간 삽입 삭제를 할것이다.
	list<CObj*> m_listView; // 이녀석은 충돌 검사 안하고 띄우기만 할 녀석들
	CObj*      m_pPlayer;
private:
	bool       m_bDebug;

public:
	virtual void Update() = 0;
	virtual void Enter() = 0;
	virtual void Exit();
	virtual void Render(HDC _hdc);

public:
	list<CObj*>& GetObj() { return m_listObj; }

public:
	CStage();
	virtual ~CStage();
};