#include "stdafx.h"
#include "Door1_4.h"
#include "BmpMgr.h"
#include "SceneMgr.h"
#include "ObjMgr.h"
CDoor1_4::CDoor1_4()
{
}

CDoor1_4::~CDoor1_4()
{
}

void CDoor1_4::Initialize(void)
{
	m_tInfo.fCX = 52;
	m_tInfo.fCY = 102;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Door1_4.bmp", L"Door1_4");

	m_pFrameKey = L"Door1_4";
}

int CDoor1_4::Update(void)
{
	Update_Rect();
	
	return 0;
}

void CDoor1_4::Late_Update(void)
{
}

void CDoor1_4::Render(HDC hDC)
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

void CDoor1_4::Release(void)
{
}

void CDoor1_4::OnCollision(DIRECTION eDir, CObj* other)
{
	if (eDir == DIR_RIGHT)
	{
		CSceneMgr::Get_Instance()->Scene_Change(SC_STAGE4);
		CObjMgr::Get_Instance()->Get_Player()->Set_Pos(700, 350);
		return;
	}
	
}
