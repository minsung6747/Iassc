#include "stdafx.h"
#include "Bullet.h"
#include "BmpMgr.h"
#include "Block.h"

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


	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Bullet.bmp", L"Bullet");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/BulletDie.bmp", L"BulletDie");

}

int CBullet::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	switch (m_eDir)
	{
	case DIR_LEFT:
		m_tInfo.fX -= m_fSpeed;
		break;
	case DIR_UP:
		m_tInfo.fY -= m_fSpeed;
		break;
		
	case DIR_RIGHT:
		m_tInfo.fX += m_fSpeed;
		break;

	case DIR_DOWN:
		m_tInfo.fY += m_fSpeed;
		break;
	}

	// ���� ? 
		
	Update_Rect();

	// ���� ? 

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
	//GdiTransparentBlt(hDC, 					// ���� ����, ���������� �׸��� �׸� DC
	//	int(m_tRect.left),	// 2,3 ���� :  ������� ��ġ X, Y
	//	int(m_tRect.top),
	//	int(m_tInfo.fCX),				// 4,5 ���� : ������� ����, ���� ����
	//	int(m_tInfo.fCY),
	//	hMemDC,							// ��Ʈ���� ������ �ִ� DC
	//	0,								// ��Ʈ�� ��� ���� ��ǥ, X,Y
	//	0,
	//	(int)m_tInfo.fCX,				// ������ ��Ʈ���� ����, ���� ����
	//	(int)m_tInfo.fCY,
	//	RGB(255, 255, 255));			// �����ϰ��� �ϴ� ����
if (1 <= bCheckBullet)
{

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"BulletDie");
	GdiTransparentBlt(hDC, 					// ���� ����, ���������� �׸��� �׸� DC
		int(m_tRect.left),	// 2,3 ���� :  ������� ��ġ X, Y
		int(m_tRect.top),
		int(m_tInfo.fCX),				// 4,5 ���� : ������� ����, ���� ����
		int(m_tInfo.fCY),
		hMemDC,							// ��Ʈ���� ������ �ִ� DC
		0,								// ��Ʈ�� ��� ���� ��ǥ, X,Y
		0,
		(int)fBulletDie_fCX,				// ������ ��Ʈ���� ����, ���� ����
		(int)fBulletDie_fCY,
		RGB(255, 255, 255));			// �����ϰ��� �ϴ� ����


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
	
}

void CBullet::Release(void)
{
	
}

void CBullet::OnCollision(CObj* other)
{
	Set_Dead();
}






//if (1 <= bCheckBullet)
//{
//
//	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"BulletDie");
//	GdiTransparentBlt(hDC, 					// ���� ����, ���������� �׸��� �׸� DC
//		int(m_tRect.left),	// 2,3 ���� :  ������� ��ġ X, Y
//		int(m_tRect.top),
//		int(m_tInfo.fCX),				// 4,5 ���� : ������� ����, ���� ����
//		int(m_tInfo.fCY),
//		hMemDC,							// ��Ʈ���� ������ �ִ� DC
//		0,								// ��Ʈ�� ��� ���� ��ǥ, X,Y
//		0,
//		(int)fBulletDie_fCX,				// ������ ��Ʈ���� ����, ���� ����
//		(int)fBulletDie_fCY,
//		RGB(255, 255, 255));			// �����ϰ��� �ϴ� ����
//
//
//	bDeadEffectTime++;
//	if (bDeadEffectTime >= 100)
//	{
//		m_bDead = true;
//	}
//
//}
//else {
//	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Bullet");
//	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
//	GdiTransparentBlt(hDC, 					// ���� ����, ���������� �׸��� �׸� DC
//		int(m_tRect.left),	// 2,3 ���� :  ������� ��ġ X, Y
//		int(m_tRect.top),
//		int(m_tInfo.fCX),				// 4,5 ���� : ������� ����, ���� ����
//		int(m_tInfo.fCY),
//		hMemDC,							// ��Ʈ���� ������ �ִ� DC
//		0,								// ��Ʈ�� ��� ���� ��ǥ, X,Y
//		0,
//		(int)m_tInfo.fCX,				// ������ ��Ʈ���� ����, ���� ����
//		(int)m_tInfo.fCY,
//		RGB(255, 255, 255));			// �����ϰ��� �ϴ� ����
//
//}