#include "stdafx.h"
#include "BackDoorItem_5.h"
#include "BmpMgr.h"
#include "SceneMgr.h"

CBackDoorItem_5::CBackDoorItem_5()
{
}

CBackDoorItem_5::~CBackDoorItem_5()
{
	Release();
}

void CBackDoorItem_5::Initialize(void)
{
	m_tInfo.fCX = 52;
	m_tInfo.fCY = 102;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/BackDoorItem_5.bmp", L"BackDoorItem_5");

	m_pFrameKey = L"BackDoorItem_5";

}

int CBackDoorItem_5::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	Update_Rect();
	return 0;
}

void CBackDoorItem_5::Late_Update(void)
{
}

void CBackDoorItem_5::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"BackDoorItem_5");
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

void CBackDoorItem_5::Release(void)
{
}

void CBackDoorItem_5::OnCollision(DIRECTION eDir, CObj* other)
{
	if (eDir == DIR_LEFT)
	{
		CSceneMgr::Get_Instance()->Scene_Change(SC_STAGE5);
		CObjMgr::Get_Instance()->Get_Player()->Set_Pos(130, 350);
		return;
	}
}
