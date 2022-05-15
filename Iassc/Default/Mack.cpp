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

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Mack.bmp", L"Mack");
	m_pFrameKey = L"Mack";
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 5;  //����
	m_tFrame.iMotion = 0;    //����
	m_tFrame.dwSpeed = 400;
	m_tFrame.dwTime = GetTickCount();

	m_fDelay = 1000.f;
	m_fOldTime = GetTickCount64();

	
}

int CMack::Update(void)
{
	if (m_fOldTime + 1000 < GetTickCount())  // ���࿡ �����ð��� ���ϱ� ��Ÿ��2�� ���� ������� �� �ð����� �۴ٸ� 
	{


			CObjMgr::Get_Instance()->Add_Object(OBJ_MBULLET, Create_Bullet());

			// ����Ʈ�� ���͸� �ϳ� �����. 
		
		m_fOldTime = GetTickCount();  //�׸��� �����ð����� �ٽ� ������� �� �ð����� �ʱ�ȭ��Ų��. 
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

void CMack::Release(void)
{
}



CObj* CMack::Create_Bullet()
{
	CObj* pBullet = CAbstractFactory<CMonsterBullet>::Create(m_tInfo.fX,m_tInfo.fY);
	return pBullet;
}

void CMack::AutoShot()
{
	
		CObjMgr::Get_Instance()->Add_Object(OBJ_MBULLET, Create_Bullet());
	


}

void CMack::OnCollision(CObj* other)
{
}
//if (m_tInfo.fX == m_pTarget->Get_Info().fX || m_tInfo.fY == m_pTarget->Get_Info().fY)
//{
//	CObjMgr::Get_Instance()->Add_Object(OBJ_MBULLET, Create_Bullet());
//}*/