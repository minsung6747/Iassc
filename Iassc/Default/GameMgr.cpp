#include "stdafx.h"
#include "GameMgr.h"
#include"UIMgr.h"
#include "BmpMgr.h"
CGameMgr* CGameMgr::m_pInstance = nullptr;

CGameMgr::CGameMgr() : time(1),iCoin(0),iBomb(0),bTripleCheck(true)
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
	CUIMgr::Get_Instance()->RenderCoin(hMemDC);
}

void CGameMgr::PlusBomb()
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"UI_count");

	++iBomb;

	CUIMgr::Get_Instance()->RenderBomb(hMemDC);

}
void CGameMgr::Set_bTripleShot()
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"TripleShotUI");
	CUIMgr::Get_Instance()->RenderArrows(hMemDC, true);
}
