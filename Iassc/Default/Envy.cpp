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
	m_tFrame.iFrameEnd = 0;  //����
	m_tFrame.iMotion = 0;    //����
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
	else
	{
		m_tFrame.iFrameStart = 1;
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