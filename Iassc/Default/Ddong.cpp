#include "stdafx.h"
#include "Ddong.h"
#include "BmpMgr.h"
CDdong::CDdong()
{
}

CDdong::~CDdong()
{
	Release();
}

void CDdong::Initialize(void)
{

	m_tInfo.fCX = 65.f;
	m_tInfo.fCY = 38.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Ddong.bmp", L"Ddong");


	m_pFrameKey = L"Ddong";

	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 0;  //����
	m_tFrame.iMotion = 0;    //����
	m_tFrame.dwSpeed = 200;
	m_tFrame.dwTime = GetTickCount();


}

int CDdong::Update(void)
{
	Update_Rect();

	return 0;
}

void CDdong::Late_Update(void)
{
	Move_Frame();
}

void CDdong::Render(HDC hDC)
{

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Ddong");
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

void CDdong::Release(void)
{
}

void CDdong::OnCollision(CObj*)
{
}
