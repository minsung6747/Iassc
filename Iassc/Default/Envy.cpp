#include "stdafx.h"
#include "Envy.h"
#include "BmpMgr.h"
CEnvy::CEnvy()
{
}

CEnvy::~CEnvy()
{
	Release();
}

void CEnvy::Initialize(void)
{

	bCheckDir = false;
	m_tInfo.fCX = 75;
	m_tInfo.fCY = 74;

	m_tStatInfo = { 5,0,1 };
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Envy.bmp", L"Envy");

	m_pFrameKey = L"Envy";
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 0;  //가로
	m_tFrame.iMotion = 0;    //세로
	m_tFrame.dwSpeed = 200;
	m_tFrame.dwTime = GetTickCount();

	m_fSpeed = 3;


	

}

int CEnvy::Update(void)
{
	
	if (m_bDead)
		return OBJ_DEAD;
	
	m_tInfo.fX += m_fSpeed * cosf((m_fAngle * PI) / 180.f);
	m_tInfo.fY += m_fSpeed * sinf((m_fAngle * PI) / 180.f);

	
	Update_Rect();


	return 0;
}

void CEnvy::Late_Update(void)
{
	
	if (70 >= m_tRect.left || WINCX - 70 <= m_tRect.right || 170 >= m_tRect.top || 540 <= m_tRect.bottom)

	{
		m_fSpeed *= -1;
	
		if (m_fSpeed <= 0)
		{
			bCheckDir = true;

		}
		else
		{
			bCheckDir = false;

		}
	}
	
	
	
	Move_Frame();
}

void CEnvy::Render(HDC hDC)
{
	if (bCheckDir == true)
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
	else
	{
		m_tFrame.iFrameStart = 1;
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

	
}

void CEnvy::Release(void)
{
}

void CEnvy::OnCollision(CObj* other)
{
	statInfo& GetBullet = other->Get_StatInfo();

	m_tStatInfo.iHp -= GetBullet.iAt;

	if (m_tStatInfo.iHp <= 0)
	{
		Set_Dead();
	}
}