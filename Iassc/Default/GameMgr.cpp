#include "stdafx.h"
#include "GameMgr.h"
#include"UIMgr.h"
#include "BmpMgr.h"
CGameMgr* CGameMgr::m_pInstance = nullptr;

CGameMgr::CGameMgr() : time(1),iCoin(0)
{
}

CGameMgr::~CGameMgr()
{
}



void CGameMgr::Release()
{
	
	time = 0;

}

void CGameMgr::PlusCoin()
{
	
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"UI_count");

	++iCoin;
	CUIMgr::Get_Instance()->RenderCoin(hMemDC, iCoin);
}
