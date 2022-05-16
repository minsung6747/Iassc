#include "stdafx.h"
#include "Ddong.h"
#include "BmpMgr.h"
CDdong::CDdong()
{
}

CDdong::~CDdong()
{
	Release();
}

void CDdong::Initialize(void)
{

	m_tInfo.fCX = 65.f;
	m_tInfo.fCY = 38.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Ddong.bmp", L"Ddong");


	m_pFrameKey = L"Ddong";

	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 1;  //가로
	m_tFrame.iMotion = 0;    //세로
	m_tFrame.dwSpeed = 200;
	m_tFrame.dwTime = GetTickCount();


}

int CDdong::Update(void)
{
	Update_Rect();

	return 0;
}

void CDdong::Late_Update(void)
{
	Move_Frame();
}

void CDdong::Render(HDC hDC)
{

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Ddong");
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

void CDdong::Release(void)
{
}

void CDdong::OnCollision(CObj*)
{
}
