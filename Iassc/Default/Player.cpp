#include "stdafx.h"
#include "Player.h"
#include "AbstractFactory.h"
#include "BmpMgr.h"
#include "KeyMgr.h"
CPlayer::CPlayer()
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

	m_tInfo.fCX = 84.f;
	m_tInfo.fCY = 92.f;

	m_fSpeed = 10.f; 
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Iassc.bmp", L"Player");
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

}

void CPlayer::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Player");
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

void CPlayer::Release(void)
{
	
}

void CPlayer::Key_Input(void)
{
	// GetKeyState
	if (GetAsyncKeyState(VK_LEFT))
		m_tInfo.fX -= m_fSpeed;

	if (GetAsyncKeyState(VK_RIGHT))
		m_tInfo.fX += m_fSpeed;

	if (GetAsyncKeyState(VK_UP))
		m_tInfo.fY -= m_fSpeed;

	if (GetAsyncKeyState(VK_DOWN))
		m_tInfo.fY += m_fSpeed;

	if (CKeyMgr::Get_Instance()->Key_Up('W'))
		m_pBullet->push_back(Create_Bullet(DIR_UP));

	if (CKeyMgr::Get_Instance()->Key_Up('A'))
		m_pBullet->push_back(Create_Bullet(DIR_LEFT));

	if (CKeyMgr::Get_Instance()->Key_Up('S'))
		m_pBullet->push_back(Create_Bullet(DIR_DOWN));

	if (GetAsyncKeyState('D'))
		m_pBullet->push_back(CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY, DIR_RIGHT));

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
