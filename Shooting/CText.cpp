#include "stdafx.h"
#include "CText.h"
#include "ResMgr.h"

tTextPos CText::m_tPos[(UINT)TEXT::END] = {};

CText::CText()
	:m_iSize(32),
	m_iSpacing(24)
{
	m_eBelong = BELONG::UI;
	for (UINT i = 0; i < 7; ++i)
	{
		for (UINT j = 0; j < 8; ++j)
		{
			if ((i * 8 + j) == (UINT)TEXT::END)
				break;
			m_tPos[i * 8 + j] = { Vec2(j * m_iSize,i * m_iSize),Vec2((j * m_iSize) + m_iSize,(i * m_iSize) + m_iSize) };
		}
	}

	m_pTex = (CTexture*)CResMgr::GetInst()->Load<CTexture*>(L"Text", L"UI\\Text1.bmp");
}

CText::~CText()
{
}

int CText::update()
{
	return 0;
}


// 현재 이코드는 정사각형일때만 작동 된다 주의하자 만약 직각으로 정사각형이 아니라면 size를 xy 나눠서 설정해주면 된다. 지금은 힘들어서 못하겟다.ㅠ

void CText::render(HDC _dc)
{
	for (UINT i = 0; i < m_wstrText.size(); ++i)
	{
		if(m_wstrText[i] == 'A' || m_wstrText[i] == 'a')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, 
				m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_A].start.x, m_tPos[(UINT)TEXT::TEXT_A].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == 'B' || m_wstrText[i] == 'b')											 
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, 
				m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_B].start.x, m_tPos[(UINT)TEXT::TEXT_B].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == 'C' || m_wstrText[i] == 'c')											 
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, 
				m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_C].start.x, m_tPos[(UINT)TEXT::TEXT_C].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == 'D' || m_wstrText[i] == 'd')											 
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, 
				m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_D].start.x, m_tPos[(UINT)TEXT::TEXT_D].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == 'E' || m_wstrText[i] == 'e')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, 
				m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_E].start.x, m_tPos[(UINT)TEXT::TEXT_E].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == 'F' || m_wstrText[i] == 'f')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, 
				m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_F].start.x, m_tPos[(UINT)TEXT::TEXT_F].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == 'G' || m_wstrText[i] == 'g')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_G].start.x, m_tPos[(UINT)TEXT::TEXT_G].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == 'H' || m_wstrText[i] == 'h')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_H].start.x, m_tPos[(UINT)TEXT::TEXT_H].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == 'I' || m_wstrText[i] == 'i')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_I].start.x, m_tPos[(UINT)TEXT::TEXT_I].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == 'J' || m_wstrText[i] == 'j')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_J].start.x, m_tPos[(UINT)TEXT::TEXT_J].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == 'K' || m_wstrText[i] == 'k')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_K].start.x, m_tPos[(UINT)TEXT::TEXT_K].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == 'L' || m_wstrText[i] == 'l')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_L].start.x, m_tPos[(UINT)TEXT::TEXT_L].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == 'M' || m_wstrText[i] == 'm')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_M].start.x, m_tPos[(UINT)TEXT::TEXT_M].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == 'N' || m_wstrText[i] == 'n')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_N].start.x, m_tPos[(UINT)TEXT::TEXT_N].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == 'O' || m_wstrText[i] == 'o')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_O].start.x, m_tPos[(UINT)TEXT::TEXT_O].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == 'P' || m_wstrText[i] == 'p')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_P].start.x, m_tPos[(UINT)TEXT::TEXT_P].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == 'Q' || m_wstrText[i] == 'q')											 
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_Q].start.x, m_tPos[(UINT)TEXT::TEXT_Q].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == 'R' || m_wstrText[i] == 'r')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_R].start.x, m_tPos[(UINT)TEXT::TEXT_R].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == 'S' || m_wstrText[i] == 's')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_S].start.x, m_tPos[(UINT)TEXT::TEXT_S].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == 'T' || m_wstrText[i] == 't')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_T].start.x, m_tPos[(UINT)TEXT::TEXT_T].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == 'U' || m_wstrText[i] == 'u')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_U].start.x, m_tPos[(UINT)TEXT::TEXT_U].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == 'V' || m_wstrText[i] == 'v')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_V].start.x, m_tPos[(UINT)TEXT::TEXT_V].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == 'W' || m_wstrText[i] == 'w')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_W].start.x, m_tPos[(UINT)TEXT::TEXT_W].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == 'X' || m_wstrText[i] == 'x')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_X].start.x, m_tPos[(UINT)TEXT::TEXT_X].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == 'Y' || m_wstrText[i] == 'y')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_Y].start.x, m_tPos[(UINT)TEXT::TEXT_Y].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == 'Z' || m_wstrText[i] == 'z')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_Z].start.x, m_tPos[(UINT)TEXT::TEXT_Z].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == '0')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_0].start.x, m_tPos[(UINT)TEXT::TEXT_0].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == '1')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_1].start.x, m_tPos[(UINT)TEXT::TEXT_1].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == '2')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_2].start.x, m_tPos[(UINT)TEXT::TEXT_2].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == '3')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_3].start.x, m_tPos[(UINT)TEXT::TEXT_3].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == '4')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_4].start.x, m_tPos[(UINT)TEXT::TEXT_4].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == '5')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_5].start.x, m_tPos[(UINT)TEXT::TEXT_5].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == '6')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_6].start.x, m_tPos[(UINT)TEXT::TEXT_6].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == '7')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_7].start.x, m_tPos[(UINT)TEXT::TEXT_7].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == '8')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_8].start.x, m_tPos[(UINT)TEXT::TEXT_8].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == '9')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_9].start.x, m_tPos[(UINT)TEXT::TEXT_9].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
		else if (m_wstrText[i] == '*')
			TransparentBlt(_dc, m_vPos.x + i * m_iSpacing, m_vPos.y, m_iSize, m_iSize, m_pTex->GetDC(), m_tPos[(UINT)TEXT::TEXT_MULTIPLY].start.x, m_tPos[(UINT)TEXT::TEXT_MULTIPLY].start.y, m_iSize, m_iSize, RGB(0, 0, 0));
	}
}