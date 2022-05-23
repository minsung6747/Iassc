#include "stdafx.h"
#include "BackDoor5_4.h"
#include "BmpMgr.h"
#include "ObjMgr.h"
#include "SceneMgr.h"
CBackDoor5_4::CBackDoor5_4()
{
}

CBackDoor5_4::~CBackDoor5_4()
{
	Release();
}

void CBackDoor5_4::Initialize(void)
{
	m_tInfo.fCX = 102;
	m_tInfo.fCY = 54;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/BackDoor5_4.bmp", L"BackDoor5_4");

	m_pFrameKey = L"BackDoor5_4";
}

int CBackDoor5_4::Update(void)
{

	if (m_bDead)
		return OBJ_DEAD;

	Update_Rect();
	return 0;
}
void CBackDoor5_4::Late_Update(void)
{
}

void CBackDoor5_4::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"BackDoor5_4");
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

void CBackDoor5_4::Release(void)
{
}

void CBackDoor5_4::OnCollision(DIRECTION eDir, CObj* other)
{
	if (eDir == DIR_UP)
	{
		CSceneMgr::Get_Instance()->Scene_Change(SC_STAGE4);
		CObjMgr::Get_Instance()->Get_Player()->Set_Pos(400, 350);



		return;
	}
}
