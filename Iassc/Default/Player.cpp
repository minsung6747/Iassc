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
	bTripleCheck = false;
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 300.f;
	statInfo PlayerStat = { 6,6,1 };

	m_tInfo.fCX = 66.f;
	m_tInfo.fCY = 55.f;

	m_fSpeed = 5.f; 
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Player_Idle.bmp", L"Player_Idle");
	//CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Player_Walk.bmp", L"Player_Walk");*/
	//CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Player_Shot.bmp", L"Player_Shot");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/isaac.bmp", L"isaac");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/isaac.bmp", L"SHOT_DOWN");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/isaac.bmp", L"SHOT_UP");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/isaac.bmp", L"SHOT_LEFT");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/isaac.bmp", L"SHOT_RIGHT");

	

	
	m_pFrameKey = L"Player_Idle";


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
	Motion_Change();
	Move_Frame();
}

void CPlayer::Render(HDC hDC)
{
	if (m_eCurState == IDLE)
	{
		HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Player_Idle");

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
	else
	{
		HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);
		//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
		GdiTransparentBlt(hDC, 					// ���� ����, ���������� �׸��� �׸� DC
			int(m_tRect.left),	// 2,3 ���� :  ������� ��ġ X, Y
			int(m_tRect.top),
			int(m_tInfo.fCX),				// 4,5 ���� : ������� ����, ���� ����
			int(m_tInfo.fCY),
			hMemDC,							// ��Ʈ���� ������ �ִ� DC
			m_tFrame.iFrameStart * (int)m_tInfo.fCX,								// ��Ʈ�� ��� ���� ��ǥ, X,Y
			m_tFrame.iMotion * (int)m_tInfo.fCY,
			(int)m_tInfo.fCX,				// ������ ��Ʈ���� ����, ���� ����
			(int)m_tInfo.fCY,
			RGB(255, 255, 255));			// �����ϰ��� �ϴ� ����
	}
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
			m_pFrameKey = L"isaac";
			m_eCurState = WALK;
		}
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		if (m_tInfo.fX <= 700)
		{
			m_tInfo.fX += m_fSpeed;
			m_pFrameKey = L"isaac";
			m_eCurState = WALK;
		}
	}
	else if (GetAsyncKeyState(VK_UP))
	{
		if (m_tInfo.fY >= 200)
		{
			m_tInfo.fY -= m_fSpeed;
			m_pFrameKey = L"isaac";
			m_eCurState = WALK;
		}
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		if (m_tInfo.fY <= 490)
		{
			m_tInfo.fY += m_fSpeed;

			m_pFrameKey = L"isaac";
			m_eCurState = WALK;
		}
	}
	else
	{
		m_pFrameKey = L"Player_Idle";
		m_eCurState = IDLE;
	}

	 if (CKeyMgr::Get_Instance()->Key_Up('W'))
	{
		 if (bTripleCheck == false)
		 {
			 CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, Create_Bullet(90));
			 m_pFrameKey = L"SHOT_UP";
			 m_eCurState = SHOT_UP;
		 }
		 else 
		 {
			 CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, Create_Bullet(87));
			 CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, Create_Bullet(90));
			 CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, Create_Bullet(93));
			 m_pFrameKey = L"SHOT_UP";
			 m_eCurState = SHOT_UP;
		 }
	}

	 if (CKeyMgr::Get_Instance()->Key_Up('A'))
	{
		 if (bTripleCheck == false)
		 {
			 CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, Create_Bullet(180));
			 m_pFrameKey = L"SHOT_LEFT";
			 m_eCurState = SHOT_LEFT;
		 }
		 else
		 {
			 CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, Create_Bullet(187));
			 CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, Create_Bullet(180));
			 CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, Create_Bullet(183));
			 m_pFrameKey = L"SHOT_UP";
			 m_eCurState = SHOT_UP;

		 }
	}
	 if (CKeyMgr::Get_Instance()->Key_Up('S'))
	{
		 if (bTripleCheck == false)
		 {
			 CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, Create_Bullet(270));
			 m_pFrameKey = L"SHOT_DOWN";
			 m_eCurState = SHOT_DOWN;
		 }
		 else
		 {
			 CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, Create_Bullet(267));
			 CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, Create_Bullet(270));
			 CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, Create_Bullet(273));
			 m_pFrameKey = L"SHOT_DOWN";
			 m_eCurState = SHOT_DOWN;
		 }

		 
	}

	 if (CKeyMgr::Get_Instance()->Key_Up('D'))
	{
		 if (bTripleCheck == false)
		 {
			 CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, Create_Bullet(360));
			 m_pFrameKey = L"SHOT_RIGHT";
			 m_eCurState = SHOT_RIGHT;
		 }
		 else
		 {
			 CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, Create_Bullet(357));
			 CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, Create_Bullet(360));
			 CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, Create_Bullet(363));
			 m_pFrameKey = L"SHOT_RIGHT";
			 m_eCurState = SHOT_RIGHT;

		 }
	}

}
CObj* CPlayer::Create_Bullet(float m_fAngle)
{
	/*CObj*		pBullet = new CBullet;
	pBullet->Set_Pos(m_tInfo.fX, m_tInfo.fY);
	pBullet->Initialize();
	pBullet->Set_Dir(eDir);*/

	CObj*		pBullet = CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY, m_fAngle);

	return pBullet;
}


void CPlayer::Motion_Change(void)
{
	if (m_ePreState != m_eCurState)
	{
		switch (m_eCurState)
		{
		case IDLE:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 8;  //����
			m_tFrame.iMotion = 2;    //����
			m_tFrame.dwSpeed = 200;
			m_tFrame.dwTime = GetTickCount();
			break;


		case WALK:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 8;  //����
			m_tFrame.iMotion = 2;    //����
			m_tFrame.dwSpeed = 200;
			m_tFrame.dwTime = GetTickCount();
			break;
			
		case SHOT_UP:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 5;  //����
			m_tFrame.iMotion = 3;    //����
			m_tFrame.dwSpeed = 500;
			m_tFrame.dwTime = GetTickCount();

		case SHOT_DOWN:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 8;  //����
			m_tFrame.iMotion = 2;    //����
			m_tFrame.dwSpeed = 500;
			m_tFrame.dwTime = GetTickCount();

		case SHOT_LEFT:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 5;  //����
			m_tFrame.iMotion = 4;    //����
			m_tFrame.dwSpeed = 500;
			m_tFrame.dwTime = GetTickCount();

		case SHOT_RIGHT:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 6;  //����
			m_tFrame.iMotion = 5;    //����
			m_tFrame.dwSpeed = 500;
			m_tFrame.dwTime = GetTickCount();


		}
		m_ePreState = m_eCurState;
	}
}
