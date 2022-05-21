#include "stdafx.h"
#include "UIMgr.h"
#include "GameMgr.h"
#include "BmpMgr.h"
#include "Obj.h"

CUIMgr* CUIMgr::m_pInstance = nullptr;

CUIMgr::CUIMgr()
{
}

CUIMgr::~CUIMgr()
{
	Release();
}

void CUIMgr::Initialize()
{
	UIcount_fCX = 12;
	UIcount_fCY = 27;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/UI_count.bmp", L"UI_count");

	
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 0;  //가로
	m_tFrame.iMotion = 0;    //세로
	m_tFrame.dwSpeed = 200;
	m_tFrame.dwTime = GetTickCount();

}

void CUIMgr::Update(void)
{
	//m_pInstance->Update();
}

void CUIMgr::Render(HDC hDC)
{
	
}

void CUIMgr::Release()
{
	Safe_Delete(m_pInstance);
}

void CUIMgr::RenderCoin(HDC hDC)
{

	
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"UI_count");

	m_tFrame.iMotion = CGameMgr::Get_Instance()->Set_Coin();
	
	Move_Frame();
	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	GdiTransparentBlt(hDC, 					// 복사 받을, 최종적으로 그림을 그릴 DC
		360,	// 2,3 인자 :  복사받을 위치 X, Y
		10,
		int(UIcount_fCX),				// 4,5 인자 : 복사받을 가로, 세로 길이
		int(UIcount_fCY),
		hMemDC,							// 비트맵을 가지고 있는 DC
		m_tFrame.iFrameStart * (int)UIcount_fCX,								// 비트맵 출력 시작 좌표, X,Y
		m_tFrame.iMotion * (int)UIcount_fCY,
		(int)(UIcount_fCX),				// 복사할 비트맵의 가로, 세로 길이
		(int)(UIcount_fCY),
		RGB(0, 0, 255));			// 제거하고자 하는 색상

	
}


void CUIMgr::Move_Frame(void)
{
	if (m_tFrame.dwTime + m_tFrame.dwSpeed < GetTickCount())
	{
		m_tFrame.iFrameStart++;

		m_tFrame.dwTime = GetTickCount();

		if (m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
			m_tFrame.iFrameStart = 0;
	}

}
