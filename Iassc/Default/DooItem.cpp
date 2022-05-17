#include "stdafx.h"
#include "DoorItem.h"
#include "BmpMgr.h"
#include "SceneMgr.h"
#include "ObjMgr.h"

CDoorItem::CDoorItem()
{
}

CDoorItem::~CDoorItem()
{
	Release();
}

void CDoorItem::Initialize(void)
{
	m_tInfo.fCX = 52;
	m_tInfo.fCY = 102;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/DoorItem.bmp", L"DoorItem");

	m_pFrameKey = L"DoorItem";
}

int CDoorItem::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	Update_Rect();
	return 0;
}

void CDoorItem::Late_Update(void)
{
}

void CDoorItem::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"DoorItem");
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

void CDoorItem::Release(void)
{
}

void CDoorItem::OnCollision(DIRECTION eDir, CObj* other)
{
	if (eDir == DIR_RIGHT)
	{
		CSceneMgr::Get_Instance()->Scene_Change(SC_STAGE_ITEM);
		CObjMgr::Get_Instance()->Get_Player()->Set_Pos(700, 350);
		return;
	}
}
