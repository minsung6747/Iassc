#include "stdafx.h"
#include "Door2_3.h"
#include "BmpMgr.h"
#include "SceneMgr.h"
CDoor2_3::CDoor2_3()
{
}

CDoor2_3::~CDoor2_3()
{
	Release();
}

void CDoor2_3::Initialize(void)
{
	m_tInfo.fCX = 52;
	m_tInfo.fCY = 102;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Door2_3.bmp", L"Door2_3");

	m_pFrameKey = L"Door2_3";
}

int CDoor2_3::Update(void)
{
	Update_Rect();
	return 0;
}

void CDoor2_3::Late_Update(void)
{
}

void CDoor2_3::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Door2_3");
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

void CDoor2_3::Release(void)
{
}

void CDoor2_3::OnCollision(DIRECTION eDir, CObj* other)
{
	if (eDir == DIR_LEFT)
	{
		CSceneMgr::Get_Instance()->Scene_Change(SC_STAGE3);
		CObjMgr::Get_Instance()->Get_Player()->Set_Pos(130, 350);
		return;
	}
}
