#pragma once

#include "stdafx.h"
#include "Texture.h"

class CObj
{
protected:
	Vec2	m_vPos;
	tRect	m_vScale;
	CTexture* m_pTex;
	BELONG   m_eBelong;

public:
	virtual int update() = 0;
	virtual void render(HDC _dc) { return; };
	virtual int lateupdate(CObj* _pObj) { return 0; };
	virtual void CollRender(HDC _hdc);

public:
	const Vec2& GetPos() { return m_vPos; }
	const tRect& GetScale() { return m_vScale; }
	void SetPos(const Vec2& _vPos) { m_vPos = _vPos; }
	void SetScale(const tRect& _vScale) { m_vScale = _vScale; }
	void SetTexture(CTexture* _Tex) { m_pTex = _Tex; }
	CTexture* GetTexture() { return m_pTex; }
	const BELONG GetBelong() { return m_eBelong; }
	void SetBelong(BELONG _eBelong) { m_eBelong = _eBelong; }

public:
	CObj();
	virtual ~CObj(); // »ó¼Ó
};