#include "stdafx.h"
#include "Door.h"
#include "BmpMgr.h"
#include "SceneMgr.h"
CDoor::CDoor()
{
}

CDoor::~CDoor()
{
	Release();
}

void CDoor::Initialize(void)
{
	m_tInfo.fCX = 52;
	m_tInfo.fCY = 102;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Door.bmp", L"Door");

	m_pFrameKey = L"Door";
}

int CDoor::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	Update_Rect();
	return 0;
}

void CDoor::Late_Update(void)
{
}

void CDoor::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Door");
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

void CDoor::Release(void)
{
}

void CDoor::OnCollision(DIRECTION eDir, CObj* other)
{
	if (eDir == DIR_LEFT)
	{
		CSceneMgr::Get_Instance()->Scene_Change(SC_STAGE2);
		return;
	}
	else if (eDir == DIR_RIGHT)
	{
		CSceneMgr::Get_Instance()->Scene_Change(SC_STAGE);
		CObjMgr::Get_Instance()->Get_Player()->Set_Pos(130, 350);
		return;
	}
}
