#include "stdafx.h"
#include "UIMgr.h"
#include "GameMgr.h"
#include "BmpMgr.h"
#include "Obj.h"
#include "ObjMgr.h"
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


	Arrows_fCX = 51;
	Arrows_fCY = 54;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/UI_count.bmp", L"UI_count");
	
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/TripleShotUI.bmp", L"TripleShotUI");

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Arrows.bmp", L"Arrows");

	
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 0;  //����
	m_tFrame.iMotion = 0;    //����
	m_tFrame.dwSpeed = 200;
	m_tFrame.dwTime = GetTickCount();


	m_tFrame1.iFrameStart = 0;
	m_tFrame1.iFrameEnd = 0;  //����
	m_tFrame1.iMotion = 0;    //����
	m_tFrame1.dwSpeed = 200;
	m_tFrame1.dwTime = GetTickCount();


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
		8,
		int(UIcount_fCX),				// 4,5 ���� : ������� ����, ���� ����
		int(UIcount_fCY),
		hMemDC,							// ��Ʈ���� ������ �ִ� DC
		m_tFrame.iFrameStart * (int)UIcount_fCX,								// ��Ʈ�� ��� ���� ��ǥ, X,Y
		m_tFrame.iMotion * (int)UIcount_fCY,
		(int)(UIcount_fCX),				// ������ ��Ʈ���� ����, ���� ����
		(int)(UIcount_fCY),
		RGB(0, 0, 255));			// �����ϰ��� �ϴ� ����

	
}

void CUIMgr::RenderArrows(HDC hDC, bool _bTripleCheck)
{
	if (_bTripleCheck == false)
	{
		HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"TripleShotUI");

		GdiTransparentBlt(hDC, 					// ���� ����, ���������� �׸��� �׸� DC
			405,	// 2,3 ���� :  ������� ��ġ X, Y
			12,
			int(Arrows_fCX),				// 4,5 ���� : ������� ����, ���� ����
			int(Arrows_fCY),
			hMemDC,							// ��Ʈ���� ������ �ִ� DC
			0,								// ��Ʈ�� ��� ���� ��ǥ, X,Y
			0,
			(int)(Arrows_fCX),				// ������ ��Ʈ���� ����, ���� ����
			(int)(Arrows_fCY),
			RGB(255, 255, 255));			// �����ϰ��� �ϴ� ����
	}
	else
	{
		HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Arrows");

		GdiTransparentBlt(hDC, 					// ���� ����, ���������� �׸��� �׸� DC
			405,	// 2,3 ���� :  ������� ��ġ X, Y
			12,
			int(Arrows_fCX),				// 4,5 ���� : ������� ����, ���� ����
			int(Arrows_fCY),
			hMemDC,							// ��Ʈ���� ������ �ִ� DC
			0,								// ��Ʈ�� ��� ���� ��ǥ, X,Y
			0,
			(int)(Arrows_fCX),				// ������ ��Ʈ���� ����, ���� ����
			(int)(Arrows_fCY),
			RGB(255, 255, 255));			// �����ϰ��� �ϴ� ����
	}

}

void CUIMgr::RenderBomb(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"UI_count");

	m_tFrame1.iMotion = CGameMgr::Get_Instance()->Set_Bomb();

	Move_Frame();
	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	GdiTransparentBlt(hDC, 					// ���� ����, ���������� �׸��� �׸� DC
		360,	// 2,3 ���� :  ������� ��ġ X, Y
		30,
		int(UIcount_fCX),				// 4,5 ���� : ������� ����, ���� ����
		int(UIcount_fCY),
		hMemDC,							// ��Ʈ���� ������ �ִ� DC
		m_tFrame1.iFrameStart * (int)UIcount_fCX,								// ��Ʈ�� ��� ���� ��ǥ, X,Y
		m_tFrame1.iMotion * (int)UIcount_fCY,
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

