#include "stdafx.h"
#include "TileMgr.h"
#include "Tile.h"

CTileMgr::CTileMgr()
{
}


CTileMgr::~CTileMgr()
{
}

void CTileMgr::Init()
{
	for(int i = 0; i < 20; ++i)
	m_vTile.push_back(CTile(Vec2(50 + i * 100,500),100.f));
}

void CTileMgr::update()
{
}

void CTileMgr::Render(HDC _hdc)
{
	for (UINT i = 0; i < m_vTile.size(); ++i)
		m_vTile[i].render(_hdc);
}