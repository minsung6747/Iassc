#include "stdafx.h"
#include "BackDoor2_1.h"
#include "BmpMgr.h"
#include "SceneMgr.h"

CBackDoor2_1::CBackDoor2_1()
{
}

CBackDoor2_1::~CBackDoor2_1()
{
	Release();
}

void CBackDoor2_1::Initialize(void)
{
	m_tInfo.fCX = 52;
	m_tInfo.fCY = 102;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/BackDoor2_1.bmp", L"BackDoor2_1");

	m_pFrameKey = L"BackDoor2_1";
}

int CBackDoor2_1::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	Update_Rect();
	return 0;
}

void CBackDoor2_1::Late_Update(void)
{
}

void CBackDoor2_1::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"BackDoor2_1");
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

void CBackDoor2_1::Release(void)
{
}

void CBackDoor2_1::OnCollision(DIRECTION eDir, CObj* other)
{
	if (eDir == DIR_RIGHT)
	{
		CSceneMgr::Get_Instance()->Scene_Change(SC_STAGE);
		CObjMgr::Get_Instance()->Get_Player()->Set_Pos(600, 350);


		return;
	}
}