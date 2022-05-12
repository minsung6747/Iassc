#include "stdafx.h"
#include "Fire.h"
#include "BmpMgr.h"

CFire::CFire()
{
}

CFire::~CFire()
{
	Release();
}

void CFire::Initialize(void)
{
	 //FireDieCheck=false;
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 48.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Fire1.bmp", L"Fire1");
	
	
	m_pFrameKey = L"Fire1";
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 4;  //����
	m_tFrame.iMotion = 0;    //����
	m_tFrame.dwSpeed = 200;
	m_tFrame.dwTime = GetTickCount();
	
}

int CFire::Update(void)
{
	Update_Rect();
	return 0;
}

void CFire::Late_Update(void)
{
	Move_Frame();
}

void CFire::Render(HDC hDC)
{
	
		HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Fire1");
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

void CFire::Release(void)
{
}

void CFire::OnCollision(CObj*)
{
	m_tFrame.iFrameEnd = 0;  //����
	m_tFrame.iMotion = 1;    //����
}
