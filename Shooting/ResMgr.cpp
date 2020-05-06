#include "stdafx.h"
#include "ResMgr.h"
#include "Texture.h"

CResMgr::CResMgr()
{
}

CResMgr::~CResMgr()
{
	map<wstring, CTexture*>::iterator iter = m_mapTex.begin();

	for (; iter != m_mapTex.end(); ++iter)
	{
		delete iter->second;
	}

	m_mapTex.clear();
}