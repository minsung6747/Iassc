#include "stdafx.h"
#include "Mack.h"
#include "BmpMgr.h"
#include "AbstractFactory.h"
#include "MonsterBullet.h"
#include "ObjMgr.h"
#include "Obj.h"


CMack::CMack()
{
}

CMack::~CMack()
{
	Release();
}

void CMack::Initialize(void)
{
	m_tInfo.fCX = 75;
	m_tInfo.fCY = 85;
	
	m_tStatInfo = { 3,0,1 };
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Mack.bmp", L"Mack");
	m_pFrameKey = L"Mack";
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 5;  //가로
	m_tFrame.iMotion = 0;    //세로
	m_tFrame.dwSpeed = 400;
	m_tFrame.dwTime = GetTickCount64();

	m_fDelay = 1000.f;
	m_fOldTime = GetTickCount64();

	
}

int CMack::Update(void)
{
	if (m_fOldTime + 1000 < GetTickCount64())  // 만약에 이전시간값 더하기 쿨타임2초 보다 디버깅한 후 시간보다 작다면 
	{


			CObjMgr::Get_Instance()->Add_Object(OBJ_MBULLET, Create_Bullet());

			
			// 리스트에 몬스터를 하나 만든다. 
		
		m_fOldTime = GetTickCount64();  //그리고 이전시간값을 다시 디버깅한 후 시간으로 초기화시킨다. 
	}
	

	

	if(m_bDead)
		return OBJ_DEAD;

	
		
	Update_Rect();
	return 0;
}

void CMack::Late_Update(void)
{
	Move_Frame();
}

void CMack::Render(HDC hDC)
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

void CMack::Release(void)
{
}



CObj* CMack::Create_Bullet()
{
	CObj* pBullet = CAbstractFactory<CMonsterBullet>::Create(m_tInfo.fX,m_tInfo.fY);
	return pBullet;
}



void CMack::OnCollision(CObj* other)
{
	statInfo& GetBullet = other->Get_StatInfo();

	m_tStatInfo.iHp -= GetBullet.iAt;

	if (m_tStatInfo.iHp <= 0)
	{
		Set_Dead();
		++exIhowMack;
	}

}
