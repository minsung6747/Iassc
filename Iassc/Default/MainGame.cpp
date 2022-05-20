#include "stdafx.h"
#include "MainGame.h"
#include "AbstractFactory.h"
#include "CollisionMgr.h"
#include "ObjMgr.h"
#include "KeyMgr.h"
#include "BmpMgr.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
int exIhowfly = 0;
float g_fSound = 1.f;
CMainGame::CMainGame()
	: m_dwTime(GetTickCount())
{
	ZeroMemory(m_szFPS, sizeof(TCHAR) * 64);
	m_iFPS = 0;
}


CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize(void)
{
	m_hDC = GetDC(g_hWnd);
	CSceneMgr::Get_Instance()->Scene_Change(SC_LOGO);
	CSoundMgr::Get_Instance()->Initialize();
	//m_ObjList[OBJ_PLAYER].push_back(CAbstractFactory<CPlayer>::Create());
	//dynamic_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front())->Set_BulletList(&m_ObjList[OBJ_BULLET]);
	
}

void CMainGame::Update(void)
{
	CSceneMgr::Get_Instance()->Update();
	
}

void CMainGame::Late_Update(void)
{

	CSceneMgr::Get_Instance()->Late_Update();

}

void CMainGame::Render(void)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Logo");
	BitBlt(m_hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
	CSceneMgr::Get_Instance()->Render(hMemDC);
	/*Rectangle(m_hDC, 0, 0, WINCX, WINCY);
	Rectangle(m_hDC, 100, 100, WINCX - 100, WINCY - 100);*/

	

	// ��Ʈ ���

	//lstrcpy(m_szFPS, L"Hello");
	//TextOut(m_hDC, 50, 50, m_szFPS, lstrlen(m_szFPS));
	// 1. dc 2, 3. ����� ������ left, top ��ǥ, 4. ����� ���ڿ� 5. ���ڿ� ���� ũ��
	
	//RECT rc{ 0, 0, 50, 50 };
	//DrawText(m_hDC, m_szFPS, lstrlen(m_szFPS), &rc, DT_RIGHT);
	// 1. dc 2. ����� ���ڿ� 3. ���ڿ� ���� ũ�� 4. ����� ��Ʈ �ּ�, 5. ��� �ɼ�

	//TCHAR	szBuff[32] = L"";
	// �Ҽ��� �ڸ� ����� �Ұ����ϴ�. winapi ���̺귯������ �����ϴ� �Լ�
	//wsprintf(szBuff, L"Bullet : %d", m_ObjList[OBJ_BULLET].size());

	// visual c++ ���̺귯������ ����(��� ���� ���ڸ� ����)
	//swprintf_s(szBuff, L"Bullet : %f", 3.14f);
	//TextOut(m_hDC, 50, 50, szBuff, lstrlen(szBuff));
	
	++m_iFPS;

	if (m_dwTime + 1000 < GetTickCount())
	{
		swprintf_s(m_szFPS, L"FPS : %d", m_iFPS);
		SetWindowText(g_hWnd, m_szFPS);

		m_iFPS = 0;
		m_dwTime = GetTickCount();
	}

}

void CMainGame::Release(void)
{
	CObjMgr::Get_Instance()->Destroy_Instance();
	CKeyMgr::Get_Instance()->Destroy_Instance();
	CSceneMgr::Get_Instance()->Destroy_Instance();
	CSoundMgr::Get_Instance()->Destroy_Instance();
	CBmpMgr::Get_Instance()->Destroy_Instance();
	ReleaseDC(g_hWnd, m_hDC);	
}

// 1. w,a,s,d Ű�� ���� 4���� �Ѿ˽��
// 2. ���� ���ΰ� 100�� ���� ��Ʈ�� ����� �簢�� ������ ����� �̻����� �����϶�