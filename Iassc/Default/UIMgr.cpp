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
	UIcount_fCY = 270;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Fly.bmp", L"Fly");

	
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 0;  //가로
	m_tFrame.iMotion = 0;    //세로
	m_tFrame.dwSpeed = 200;
	m_tFrame.dwTime = GetTickCount();

}

void CUIMgr::Update(void)
{
	
}

void CUIMgr::Render(HDC hDC)
{
}

void CUIMgr::Release()
{
}

void CUIMgr::RenderCoin(int _iCoin)
{

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
