#include "stdafx.h"
#include "MonsterBullet.h"
#include "BmpMgr.h"
#include "ObjMgr.h"
CMonsterBullet::CMonsterBullet()
{
}

CMonsterBullet::~CMonsterBullet()
{
	Release();
}

void CMonsterBullet::Initialize(void)
{
	m_tInfo.fCX = 44;
	m_tInfo.fCY = 46;
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/MBullet.bmp", L"MBullet");
	m_pFrameKey = L"MBullet";

	m_fSpeed = 2.f;
	m_tStatInfo = { 0,0,1 };
	m_dwBulletDie = GetTickCount();
}

int CMonsterBullet::Update(void)
{

	

	if (m_bDead)
		return OBJ_DEAD;
	
	m_pTarget = CObjMgr::Get_Instance()->Get_Target(OBJ_PLAYER, this);

	if (m_pTarget)
	{
		float		fWidth = m_pTarget->Get_Info().fX - m_tInfo.fX;
		float		fHeight = m_pTarget->Get_Info().fY - m_tInfo.fY;

		float		fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);
		float		fRadian = acosf(fWidth / fDiagonal);

		m_fAngle = fRadian * 180.f / PI;

		if (m_tInfo.fY < m_pTarget->Get_Info().fY)
			m_fAngle *= -1.f;
	}

	m_tInfo.fX += m_fSpeed * cosf(m_fAngle * PI / 180.f);
	m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * PI / 180.f);
	Update_Rect();

	if (m_dwBulletDie + 5000 < GetTickCount())
	{
		Set_Dead();
		m_dwBulletDie = GetTickCount();
	}
	return 0;
}

void CMonsterBullet::Late_Update(void)
{
	
}

void CMonsterBullet::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"MBullet");

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
void CMonsterBullet::Release(void)
{
}

void CMonsterBullet::OnCollision(CObj* other)
{
	Set_Dead();
}
