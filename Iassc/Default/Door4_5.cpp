#include "stdafx.h"
#include "Door4_5.h"
#include "BmpMgr.h"
#include "SceneMgr.h"
#include "ObjMgr.h"

CDoor4_5::CDoor4_5()
{
}

CDoor4_5::~CDoor4_5()
{
    Release();
}

void CDoor4_5::Initialize(void)
{
	m_tInfo.fCX = 102;
	m_tInfo.fCY = 54;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Door4_5.bmp", L"Door4_5");

	m_pFrameKey = L"Door4_5";
}

int CDoor4_5::Update(void)
{
	Update_Rect();
	return 0;
}

void CDoor4_5::Late_Update(void)
{
}

void CDoor4_5::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Door4_5");
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

void CDoor4_5::Release(void)
{
}

void CDoor4_5::OnCollision(DIRECTION eDir, CObj* other)
{
	if (eDir == DIR_DOWN)
	{
		CSceneMgr::Get_Instance()->Scene_Change(SC_STAGE5);
		CObjMgr::Get_Instance()->Get_Player()->Set_Pos(400, 490);
		return;
	}
}
