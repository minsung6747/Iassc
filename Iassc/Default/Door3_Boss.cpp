#include "stdafx.h"
#include "Door3_Boss.h"
#include "BmpMgr.h"
#include "SceneMgr.h"
CDoor3_Boss::CDoor3_Boss()
{
}

CDoor3_Boss::~CDoor3_Boss()
{
	Release();
}

void CDoor3_Boss::Initialize(void)
{
	m_tInfo.fCX = 60;
	m_tInfo.fCY = 120;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/DoorBoss.bmp", L"DoorBoss");

	m_pFrameKey = L"DoorBoss";
}

int CDoor3_Boss::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	Update_Rect();
	return 0;
}

void CDoor3_Boss::Late_Update(void)
{
}

void CDoor3_Boss::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"DoorBoss");
	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	GdiTransparentBlt(hDC, 					// ���� ����, ���������� �׸��� �׸� DC
		int(m_tRect.left),	// 2,3 ���� :  ������� ��ġ X, Y
		int(m_tRect.top),
		int(m_tInfo.fCX),				// 4,5 ���� : ������� ����, ���� ����
		int(m_tInfo.fCY),
		hMemDC,							// ��Ʈ���� ������ �ִ� DC
		0,								// ��Ʈ�� ��� ���� ��ǥ, X,Y
		0,
		(int)m_tInfo.fCX,				// ������ ��Ʈ���� ����, ���� ����
		(int)m_tInfo.fCY,
		RGB(255, 255, 255));			// �����ϰ��� �ϴ� ����
}

void CDoor3_Boss::Release(void)
{
}


void CDoor3_Boss::OnCollision(DIRECTION eDir, CObj* other)
{
	if (eDir == DIR_LEFT)
	{
		CSceneMgr::Get_Instance()->Scene_Change(SC_STAGE_BOSS);
		CObjMgr::Get_Instance()->Get_Player()->Set_Pos(130, 350);

		return;
	}
}
