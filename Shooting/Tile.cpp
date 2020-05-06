#include "stdafx.h"
#include "Tile.h"

CTile::CTile()
{
}

CTile::CTile(Vec2 _pos, float _size)
{
	m_vPos = _pos;
	/*m_vScale.x = _size;
	m_vScale.y = _size;*/
}

CTile::~CTile()
{
}
int CTile::update()
{
	return 0;
}

void CTile::render(HDC _dc)
{
	/*Rectangle(_dc, m_vPos.x - m_vScale.x / 2
		, m_vPos.y - m_vScale.y / 2
		, m_vPos.x + m_vScale.x / 2
		, m_vPos.y + m_vScale.y / 2);*/
}