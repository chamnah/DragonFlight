#pragma once
class CObj;
class CStage
{

protected:
	list<CObj*> m_listObj; // �ٲ����� ���� �߰� ���� ������ �Ұ��̴�.
	list<CObj*> m_listView; // �̳༮�� �浹 �˻� ���ϰ� ���⸸ �� �༮��
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