#include "stdafx.h"
#include "Block.h"
#include "BmpMgr.h"
CBlock::CBlock()
{
}

CBlock::~CBlock()
{
	Release();
}

void CBlock::Initialize(void)
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Block.bmp", L"Block");

	m_pFrameKey = L"Block";
}

int CBlock::Update(void)
{
	Update_Rect();

	return 0;
}

void CBlock::Late_Update(void)
{
}

void CBlock::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Block");
	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	GdiTransparentBlt(hDC, 					// 복사 받을, 최종적으로 그림을 그릴 DC
		int(m_tRect.left),	// 2,3 인자 :  복사받을 위치 X, Y
		int(m_tRect.top),
		int(m_tInfo.fCX),				// 4,5 인자 : 복사받을 가로, 세로 길이
		int(m_tInfo.fCY),
		hMemDC,							// 비트맵을 가지고 있는 DC
		0,								// 비트맵 출력 시작 좌표, X,Y
		0,
		(int)m_tInfo.fCX,				// 복사할 비트맵의 가로, 세로 길이
		(int)m_tInfo.fCY,
		RGB(255, 255, 255));			// 제거하고자 하는 색상
}

void CBlock::Release(void)
{
}
