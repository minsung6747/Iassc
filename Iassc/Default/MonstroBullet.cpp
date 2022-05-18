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
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/MBullet.bmp", L"MBullet");
	m_pFrameKey = L"MBullet";

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
		Set_Dead();
	}
}

void CMonstroBullet::Render(HDC hDC)
{
}

void CMonstroBullet::Release(void)
{
}

void CMonstroBullet::OnCollision(CObj* _pOtherObj)
{
}
