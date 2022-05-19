#include "stdafx.h"
#include "MonstroBullet.h"
#include "BmpMgr.h"
CMonstroBullet::CMonstroBullet()
{
}

CMonstroBullet::~CMonstroBullet()
{
	Release();
}

void CMonstroBullet::Initialize(void)
{
	m_tInfo.fCX = 44;
	m_tInfo.fCY = 46;
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/MonstroBullet.bmp", L"MonstroBullet");
	m_pFrameKey = L"MonstroBullet";
	m_tStatInfo = { 0,0,1 };

	m_fSpeed = 2.f;
	
}



int CMonstroBullet::Update(void)
{
	
		if (m_bDead)
			return OBJ_DEAD;

	m_tInfo.fX += m_fSpeed * cosf((m_fTheta * PI) / 180.f);
	m_tInfo.fY -= m_fSpeed * sinf((m_fTheta * PI) / 180.f);

	Update_Rect();

	return OBJ_NOEVENT;

}

void CMonstroBullet::Late_Update(void)
{
	if (80 >= m_tRect.left || WINCX - 80 <= m_tRect.right ||
		160 >= m_tRect.top || WINCY - 80 <= m_tRect.bottom)
	{
		//Set_Dead();
	}
}

void CMonstroBullet::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"MonstroBullet");

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

void CMonstroBullet::Release(void)
{
}

void CMonstroBullet::OnCollision(CObj* _pOtherObj)
{
}
