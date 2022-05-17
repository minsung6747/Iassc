#include "stdafx.h"
#include "SceneMgr.h"

CSceneMgr* CSceneMgr::m_pInstance = nullptr;

CSceneMgr::CSceneMgr()
	: m_pScene(nullptr), m_eCurScene(SC_END), m_ePreScene(SC_END)
{
}

CSceneMgr::~CSceneMgr()
{
	Release();
}

// FSM(finite state machine) : 유한 상태 기계, 자신이 취할 수 있는 유한한 개수의 상태

void CSceneMgr::Scene_Change(SCENEID eID)
{
	m_eCurScene = eID;

	if (m_ePreScene != m_eCurScene)
	{
		Safe_Delete(m_pScene);

		switch (m_eCurScene)
		{
		case SC_LOGO:
			m_pScene = new CLogo;
			break;

		case SC_STAGE:
			m_pScene = new CStage;
			break;
		case SC_STAGE2:
			m_pScene = new CStage2;
			break;
		case SC_STAGE3:
			m_pScene = new CStage3;
			break;
		case SC_STAGE4:
			m_pScene = new CStage4;
			break;
		case SC_STAGE5:
			m_pScene = new CStage5;
			break;
		case SC_STAGE_ITEM:
			m_pScene = new CStage_Item;
			break;
		case SC_STAGE_BOSS:
			m_pScene = new CStage_Boss;
			break;

		}

		m_pScene->Initialize();
		m_ePreScene = m_eCurScene;
	}

}

void CSceneMgr::Update(void)
{
	m_pScene->Update();
}

void CSceneMgr::Late_Update(void)
{
	m_pScene->Late_Update();
}

void CSceneMgr::Render(HDC hDC)
{
	m_pScene->Render(hDC);
}

void CSceneMgr::Release(void)
{
	Safe_Delete(m_pScene);
}
