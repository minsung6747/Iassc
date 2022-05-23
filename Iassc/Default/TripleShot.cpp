#include "stdafx.h"
#include "TripleShot.h"
#include "BmpMgr.h"
#include "Player.h"
#include "GameMgr.h"
CTripleShot::CTripleShot()
{
}

CTripleShot::~CTripleShot()
{
	Release();
}

void CTripleShot::Initialize(void)
{
	m_tInfo.fCX = 41;
	m_tInfo.fCY = 41;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Tripleshotitem.bmp", L"Tripleshotitem");

	m_pFrameKey = L"Tripleshotitem";
}

int CTripleShot::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	Update_Rect();


	return 0;
}

void CTripleShot::Late_Update(void)
{
	Move_Frame();
}

void CTripleShot::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Tripleshotitem");
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

void CTripleShot::Release(void)
{
}

void CTripleShot::OnCollision(CObj* other)
{
	Set_Dead();
	dynamic_cast<CPlayer*>(other)->Set_tripleShot();
	CGameMgr::Get_Instance()->Set_bTripleShot();
}
