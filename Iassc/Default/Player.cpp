#include "stdafx.h"
#include "Player.h"
#include "AbstractFactory.h"
#include "BmpMgr.h"
#include "KeyMgr.h"
#include "Bullet.h"
#include "ObjMgr.h"

CPlayer::CPlayer()
	: m_eCurState(IDLE), m_ePreState(END)
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize(void)
{
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 300.f;

	m_tInfo.fCX = 71.f;
	m_tInfo.fCY = 73.f;

	m_fSpeed = 5.f; 
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Player_Idle.bmp", L"Player_Idle");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Player_Walk.bmp", L"Player_Walk");
	//CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Player_Shot.bmp", L"Player_Shot");
	

	
	m_pFrameKey = L"Player_Idle";


}

int CPlayer::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	// 연산을 진행
	Key_Input();



	// 모든 연산이 끝난 뒤에 최종적인 좌표를 완성
	Update_Rect();

	return OBJ_NOEVENT;
}

void CPlayer::Late_Update(void)
{
	Motion_Change();
	Move_Frame();
}

void CPlayer::Render(HDC hDC)
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

void CPlayer::Release(void)
{
	
}

void CPlayer::Key_Input(void)
{
	// GetKeyState
	if (GetAsyncKeyState(VK_LEFT))
	{
		if (m_tInfo.fX >= 100)
		{
			m_tInfo.fX -= m_fSpeed;
			m_pFrameKey = L"Player_Walk";
			m_eCurState = WALK;
		}
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		if (m_tInfo.fX <= 700)
		{
			m_tInfo.fX += m_fSpeed;
			m_pFrameKey = L"Player_Walk";
			m_eCurState = WALK;
		}
	}
	else if (GetAsyncKeyState(VK_UP))
	{
		if (m_tInfo.fY >= 200)
		{
			m_tInfo.fY -= m_fSpeed;
			m_pFrameKey = L"Player_Walk";
			m_eCurState = WALK;
		}
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		if (m_tInfo.fY <= 490)
		{
			m_tInfo.fY += m_fSpeed;
			m_pFrameKey = L"Player_Walk";
			m_eCurState = WALK;
		}
	}
	else
		m_eCurState = IDLE;

	if (CKeyMgr::Get_Instance()->Key_Up('W'))
		CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, Create_Bullet(DIR_UP));

	if (CKeyMgr::Get_Instance()->Key_Up('A'))
		CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, Create_Bullet(DIR_LEFT));

	if (CKeyMgr::Get_Instance()->Key_Up('S'))
		CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, Create_Bullet(DIR_DOWN));

	if (CKeyMgr::Get_Instance()->Key_Up('D'))
		CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, Create_Bullet(DIR_RIGHT));

}
CObj* CPlayer::Create_Bullet(DIRECTION eDir)
{
	/*CObj*		pBullet = new CBullet;
	pBullet->Set_Pos(m_tInfo.fX, m_tInfo.fY);
	pBullet->Initialize();
	pBullet->Set_Dir(eDir);*/

	CObj*		pBullet = CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY, eDir);

	return pBullet;
}


void CPlayer::Motion_Change(void)
{
	if (m_ePreState != m_eCurState)
	{
		switch (m_eCurState)
		{
		case IDLE:

			break;


		case WALK:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 8;  //가로
			m_tFrame.iMotion = 0;    //세로
			m_tFrame.dwSpeed = 200;
			m_tFrame.dwTime = GetTickCount();
			break;
			//case SHOT:
			//	if (m_pFrameKey = L"Player_ShotUp")
			//	{
			//		m_tFrame.iFrameStart = 0;
			//		m_tFrame.iFrameEnd = 5;  //가로
			//		m_tFrame.iMotion = 4;    //세로
			//		m_tFrame.dwSpeed = 200;
			//		m_tFrame.dwTime = GetTickCount();
			//	}
			//}

		}
		m_ePreState = m_eCurState;
	}
}
