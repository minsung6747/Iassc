#include "stdafx.h"
#include "Monstro.h"
#include "BmpMgr.h"
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

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Monstro.bmp", L"Monstro");
	m_pFrameKey = L"Monstro";
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 3;  //����
	m_tFrame.iMotion = 0;    //����
	m_tFrame.dwSpeed = 400;
	m_tFrame.dwTime = GetTickCount64();

}

int CMonstro::Update(void)
{

	if (m_bDead)
		return OBJ_DEAD;
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

void CMonstro::Release(void)
{
}
