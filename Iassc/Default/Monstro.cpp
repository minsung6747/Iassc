#include "stdafx.h"
#include "Monstro.h"
#include "BmpMgr.h"
CMonstro::CMonstro()
{
}

CMonstro::~CMonstro()
{
	Release();
}

void CMonstro::Initialize(void)
{
	m_tInfo.fCX = 80;
	m_tInfo.fCY = 85;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Monstro.bmp", L"Monstro");
	m_pFrameKey = L"Monstro";
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 3;  //가로
	m_tFrame.iMotion = 0;    //세로
	m_tFrame.dwSpeed = 400;
	m_tFrame.dwTime = GetTickCount64();

}

int CMonstro::Update(void)
{

	if (m_bDead)
		return OBJ_DEAD;
	Update_Rect();
	return 0;
}

void CMonstro::Late_Update(void)
{
	Move_Frame();

}

void CMonstro::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);
	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	GdiTransparentBlt(hDC, 					// 복사 받을, 최종적으로 그림을 그릴 DC
		int(m_tRect.left),	// 2,3 인자 :  복사받을 위치 X, Y
		int(m_tRect.top),
		int(m_tInfo.fCX),				// 4,5 인자 : 복사받을 가로, 세로 길이
		int(m_tInfo.fCY),
		hMemDC,							// 비트맵을 가지고 있는 DC
		m_tFrame.iFrameStart * (int)m_tInfo.fCX,								// 비트맵 출력 시작 좌표, X,Y
		m_tFrame.iMotion * (int)m_tInfo.fCY,
		(int)m_tInfo.fCX,				// 복사할 비트맵의 가로, 세로 길이
		(int)m_tInfo.fCY,
		RGB(255, 255, 255));			// 제거하고자 하는 색상
}

void CMonstro::Release(void)
{
}
