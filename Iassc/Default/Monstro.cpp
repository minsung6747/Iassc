#include "stdafx.h"
#include "Monstro.h"
#include "BmpMgr.h"
#include "MonstroBullet.h"
#include "AbstractFactory.h"
#include "ObjMgr.h"

CMonstro::CMonstro()
{
}

CMonstro::~CMonstro()
{
	Release();
}

void CMonstro::Initialize(void)
{
	m_tInfo.fCX = 80;
	m_tInfo.fCY = 85;
	m_tStatInfo = { 20,0,1 };
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Monstro.bmp", L"Monstro");
	m_pFrameKey = L"Monstro";
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 3;  //가로
	m_tFrame.iMotion = 0;    //세로
	m_tFrame.dwSpeed = 800;
	m_tFrame.dwTime = GetTickCount64();

	m_fSpeed = 1;
	fCooltime1Sec = GetTickCount64();
	fCooltime3Sec = GetTickCount64();
	fMovingCoolTimeSec = GetTickCount64();
	fStopCoolTimeSec = GetTickCount64();

	bStopCheck = false;
}

int CMonstro::Update(void)
{


	
	if (m_bDead)
		return OBJ_DEAD;
	
	MovingMonstro();

	Phase_Pattern();

	Update_Rect();

	return 0;
}

void CMonstro::Late_Update(void)
{
	Move_Frame();

}

void CMonstro::Render(HDC hDC)
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

void CMonstro::Release(void)
{
}


void CMonstro::MovingMonstro()
{
	if (fMovingCoolTimeSec + 5000 < GetTickCount64())
	{
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

		bStopCheck = true;
		

	}
	/*if (bStopCheck == true)
	{
		if (fStopCoolTimeSec + 3000 < GetTickCount64())
		{
			m_fSpeed = 0;
			fStopCoolTimeSec = GetTickCount64();

		}
	}
	bStopCheck = false;*/

	

	
	
}

CObj* CMonstro::CreateBossMonsterBullet(float _fTheta, int _fx, int _fy)
{
	CObj* pBullet = new CMonstroBullet;
	
	pBullet->Set_Pos(_fx, _fy);
	pBullet->Initialize();


	pBullet->Set_Theta(_fTheta);

	return pBullet;
}

void CMonstro::OnCollision(CObj* other)
{
	statInfo& GetBullet = other->Get_StatInfo();

	m_tStatInfo.iHp -= GetBullet.iAt;

	if (m_tStatInfo.iHp <= 0)
	{
		Set_Dead();
	}
	
}

void CMonstro::Phase_Pattern()
{
	if (fCooltime1Sec + 1000 < GetTickCount64())
	{
		NormalGun();
		fCooltime1Sec = GetTickCount64();
	}
	else if (fCooltime3Sec + 12000 < GetTickCount64())
	{
		SpreadGun();
		fCooltime3Sec = GetTickCount64();
	}
	

	
}

void CMonstro::NormalGun()
{
	
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTROBULLET, CreateBossMonsterBullet(0.f, m_tInfo.fX, m_tInfo.fY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTROBULLET, CreateBossMonsterBullet(90.0f, m_tInfo.fX, m_tInfo.fY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTROBULLET, CreateBossMonsterBullet(180.0f, m_tInfo.fX, m_tInfo.fY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTROBULLET, CreateBossMonsterBullet(270.0f, m_tInfo.fX, m_tInfo.fY));

}

void CMonstro::SpreadGun()
{
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTROBULLET, CreateBossMonsterBullet(0.f, m_tInfo.fX, m_tInfo.fY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTROBULLET, CreateBossMonsterBullet(30.f, m_tInfo.fX, m_tInfo.fY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTROBULLET, CreateBossMonsterBullet(60.f, m_tInfo.fX, m_tInfo.fY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTROBULLET, CreateBossMonsterBullet(90.f, m_tInfo.fX, m_tInfo.fY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTROBULLET, CreateBossMonsterBullet(120.f, m_tInfo.fX, m_tInfo.fY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTROBULLET, CreateBossMonsterBullet(150.f, m_tInfo.fX, m_tInfo.fY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTROBULLET, CreateBossMonsterBullet(180.f, m_tInfo.fX, m_tInfo.fY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTROBULLET, CreateBossMonsterBullet(210.f, m_tInfo.fX, m_tInfo.fY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTROBULLET, CreateBossMonsterBullet(240.f, m_tInfo.fX, m_tInfo.fY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTROBULLET, CreateBossMonsterBullet(270.f, m_tInfo.fX, m_tInfo.fY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTROBULLET, CreateBossMonsterBullet(300.f, m_tInfo.fX, m_tInfo.fY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTROBULLET, CreateBossMonsterBullet(330.f, m_tInfo.fX, m_tInfo.fY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTROBULLET, CreateBossMonsterBullet(360.f, m_tInfo.fX, m_tInfo.fY));


}

