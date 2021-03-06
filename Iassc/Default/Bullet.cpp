#include "stdafx.h"
#include "Bullet.h"
#include "BmpMgr.h"
#include "Block.h"
#include "SoundMgr.h"
CBullet::CBullet()
{
}


CBullet::~CBullet()
{
	Release();
}

void CBullet::Initialize(void)
{
	 m_bDead = false;
	 bCheckBullet = 0;
	 bDeadEffectTime=0;
	


	m_tInfo.fCX = 27.f;
	m_tInfo.fCY = 27.f;
	
	fBulletDie_fCX=50;
	fBulletDie_fCY=50;

	m_fSpeed = 7.f;

	m_tStatInfo = { 0,0,1 };
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Bullet.bmp", L"Bullet");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/BulletDie.bmp", L"BulletDie");

}

int CBullet::Update(void)
{

	if (m_bDead)
		return OBJ_DEAD;


	m_tInfo.fX += m_fSpeed * cosf((m_fAngle * PI) / 180.f);
	m_tInfo.fY -= m_fSpeed * sinf((m_fAngle * PI) / 180.f);
	/*switch (m_eDir)
	{
	case DIR_LEFT:
		m_fAngle = 180.f;
		m_tInfo.fX += m_fSpeed * cosf((m_fAngle * PI) / 180.f);
		m_tInfo.fY -= m_fSpeed * sinf((m_fAngle * PI) / 180.f);
		break;
	case DIR_UP:
		m_fAngle = 90.f;
		m_tInfo.fX += m_fSpeed * cosf((m_fAngle * PI) / 180.f);
		m_tInfo.fY -= m_fSpeed * sinf((m_fAngle * PI) / 180.f);
		break;
		
	case DIR_RIGHT:
		m_fAngle = 0.f;
		m_tInfo.fX += m_fSpeed * cosf((m_fAngle * PI) / 180.f);
		m_tInfo.fY -= m_fSpeed * sinf((m_fAngle * PI) / 180.f);
		break;

	case DIR_DOWN:
		m_fAngle = 270.f;
		m_tInfo.fX += m_fSpeed * cosf((m_fAngle * PI) / 180.f);
		m_tInfo.fY -= m_fSpeed * sinf((m_fAngle * PI) / 180.f);
	
		break;
	}*/

	// 조건 ? 
		
	Update_Rect();

	// 조건 ? 

	return OBJ_NOEVENT;
}

void CBullet::Late_Update(void)
{
	if (80 >= m_tRect.left || WINCX - 80 <= m_tRect.right ||
		160 >= m_tRect.top || WINCY - 80 <= m_tRect.bottom)
	{
		//m_bDead=true;
		bCheckBullet++;
		

	}
}

void CBullet::Render(HDC hDC)
{
	////Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	//HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Bullet");
	////Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	//GdiTransparentBlt(hDC, 					// 복사 받을, 최종적으로 그림을 그릴 DC
	//	int(m_tRect.left),	// 2,3 인자 :  복사받을 위치 X, Y
	//	int(m_tRect.top),
	//	int(m_tInfo.fCX),				// 4,5 인자 : 복사받을 가로, 세로 길이
	//	int(m_tInfo.fCY),
	//	hMemDC,							// 비트맵을 가지고 있는 DC
	//	0,								// 비트맵 출력 시작 좌표, X,Y
	//	0,
	//	(int)m_tInfo.fCX,				// 복사할 비트맵의 가로, 세로 길이
	//	(int)m_tInfo.fCY,
	//	RGB(255, 255, 255));			// 제거하고자 하는 색상
if (1 <= bCheckBullet)
{

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"BulletDie");
	GdiTransparentBlt(hDC, 					// 복사 받을, 최종적으로 그림을 그릴 DC
		int(m_tRect.left),	// 2,3 인자 :  복사받을 위치 X, Y
		int(m_tRect.top),
		int(m_tInfo.fCX),				// 4,5 인자 : 복사받을 가로, 세로 길이
		int(m_tInfo.fCY),
		hMemDC,							// 비트맵을 가지고 있는 DC
		0,								// 비트맵 출력 시작 좌표, X,Y
		0,
		(int)fBulletDie_fCX,				// 복사할 비트맵의 가로, 세로 길이
		(int)fBulletDie_fCY,
		RGB(255, 255, 255));			// 제거하고자 하는 색상

	CSoundMgr::Get_Instance()->PlaySoundW(L"BulletEnd.wav", SOUND_PLAYER, g_fSound);
	bDeadEffectTime++;

	if (bDeadEffectTime >= 100)
	{
		
		m_bDead = true;
		
	}
	m_fSpeed = 0;
}
else {
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Bullet");
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
	
}

void CBullet::Release(void)
{
	
}

void CBullet::OnCollision(CObj* other)
{
	Set_Dead();

	
}





