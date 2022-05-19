#include "stdafx.h"
#include "GameMgr.h"
#include"UIMgr.h"

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
	++iCoin;
}
