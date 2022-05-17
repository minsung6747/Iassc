#include "stdafx.h"
#include "Block3.h"
#include "BmpMgr.h"

CBlock3::CBlock3()
{
}

CBlock3::~CBlock3()
{
	Release();
}

void CBlock3::Initialize(void)
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Block3.bmp", L"Block3");

	m_pFrameKey = L"Block3";
}

int CBlock3::Update(void)
{
	Update_Rect();

	return 0;
}

void CBlock3::Late_Update(void)
{
}

void CBlock3::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Block3");
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

void CBlock3::Release(void)
{
}
