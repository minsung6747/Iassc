#include "stdafx.h"
#include "Player.h"
#include "AbstractFactory.h"
#include "BmpMgr.h"
#include "KeyMgr.h"
#include "Bullet.h"
#include "ObjMgr.h"

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

	m_tInfo.fCX = 60.f;
	m_tInfo.fCY = 65.f;

	m_fSpeed = 5.f; 
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Iassc.bmp", L"Player");
}

int CPlayer::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	// ������ ����
	Key_Input();



	// ��� ������ ���� �ڿ� �������� ��ǥ�� �ϼ�
	Update_Rect();

	return OBJ_NOEVENT;
}

void CPlayer::Late_Update(void)
{
	//if (100 >= m_tRect.left || WINCX - 100 <= m_tRect.right ||
	//	100 >= m_tRect.top || WINCY - 100 <= m_tRect.bottom)
	//{
	//	m_bDead = true;
	//}
}

void CPlayer::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Player");
	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	GdiTransparentBlt(hDC, 					// ���� ����, ���������� �׸��� �׸� DC
		int(m_tRect.left),	// 2,3 ���� :  ������� ��ġ X, Y
		int(m_tRect.top),
		int(m_tInfo.fCX),				// 4,5 ���� : ������� ����, ���� ����
		int(m_tInfo.fCY),
		hMemDC,							// ��Ʈ���� ������ �ִ� DC
		0,								// ��Ʈ�� ��� ���� ��ǥ, X,Y
		0,
		(int)m_tInfo.fCX,				// ������ ��Ʈ���� ����, ���� ����
		(int)m_tInfo.fCY,
		RGB(255, 255, 255));			// �����ϰ��� �ϴ� ����
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
