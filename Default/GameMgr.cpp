#include "stdafx.h"
#include "GameMgr.h"


CGameMgr* CGameMgr::m_pInstance = nullptr;

CGameMgr::CGameMgr() : time(1), m_iScore(0)
{
}

CGameMgr::~CGameMgr()
{
}



void CGameMgr::Release()
{
	m_iScore = 0;
	time = 0;

}
