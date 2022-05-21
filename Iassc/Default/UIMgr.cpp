#include "stdafx.h"
#include "UIMgr.h"
#include "GameMgr.h"
#include "BmpMgr.h"
#include "Obj.h"

CUIMgr* CUIMgr::m_pInstance = nullptr;

CUIMgr::CUIMgr()
{
}

CUIMgr::~CUIMgr()
{
	Release();
}

void CUIMgr::Initialize()
{
	UIcount_fCX = 12;
	UIcount_fCY = 27;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/UI_count.bmp", L"UI_count");

	
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 0;  //����
	m_tFrame.iMotion = 0;    //����
	m_tFrame.dwSpeed = 200;
	m_tFrame.dwTime = GetTickCount();

}

void CUIMgr::Update(void)
{
	//m_pInstance->Update();
}

void CUIMgr::Render(HDC hDC)
{
	
}

void CUIMgr::Release()
{
	Safe_Delete(m_pInstance);
}

void CUIMgr::RenderCoin(HDC hDC)
{

	
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"UI_count");

	m_tFrame.iMotion = CGameMgr::Get_Instance()->Set_Coin();
	
	Move_Frame();
	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	GdiTransparentBlt(hDC, 					// ���� ����, ���������� �׸��� �׸� DC
		360,	// 2,3 ���� :  ������� ��ġ X, Y
		10,
		int(UIcount_fCX),				// 4,5 ���� : ������� ����, ���� ����
		int(UIcount_fCY),
		hMemDC,							// ��Ʈ���� ������ �ִ� DC
		m_tFrame.iFrameStart * (int)UIcount_fCX,								// ��Ʈ�� ��� ���� ��ǥ, X,Y
		m_tFrame.iMotion * (int)UIcount_fCY,
		(int)(UIcount_fCX),				// ������ ��Ʈ���� ����, ���� ����
		(int)(UIcount_fCY),
		RGB(0, 0, 255));			// �����ϰ��� �ϴ� ����

	
}


void CUIMgr::Move_Frame(void)
{
	if (m_tFrame.dwTime + m_tFrame.dwSpeed < GetTickCount())
	{
		m_tFrame.iFrameStart++;

		m_tFrame.dwTime = GetTickCount();

		if (m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
			m_tFrame.iFrameStart = 0;
	}

}
