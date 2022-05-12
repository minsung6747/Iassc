#include "stdafx.h"
#include "Fire.h"
#include "BmpMgr.h"

CFire::CFire()
{
}

CFire::~CFire()
{
	Release();
}

void CFire::Initialize(void)
{
	 //FireDieCheck=false;
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 48.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Fire1.bmp", L"Fire1");
	
	
	m_pFrameKey = L"Fire1";
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 4;  //가로
	m_tFrame.iMotion = 0;    //세로
	m_tFrame.dwSpeed = 200;
	m_tFrame.dwTime = GetTickCount();
	
}

int CFire::Update(void)
{
	Update_Rect();
	return 0;
}

void CFire::Late_Update(void)
{
	Move_Frame();
}

void CFire::Render(HDC hDC)
{
	
		HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Fire1");
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

void CFire::Release(void)
{
}

void CFire::OnCollision(CObj*)
{
	m_tFrame.iFrameEnd = 0;  //가로
	m_tFrame.iMotion = 1;    //세로
}
