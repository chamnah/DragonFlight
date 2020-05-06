#pragma once
class CTile;
class CTileMgr
{
SINGLE(CTileMgr)

private:
	vector<CTile> m_vTile;

public:
	vector<CTile>& GetTileList() { return m_vTile; }

public:
	void Init();
	void update();
	void Render(HDC _hdc);
};