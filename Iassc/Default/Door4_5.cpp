#include "stdafx.h"
#include "Door4_5.h"
#include "BmpMgr.h"
#include "SceneMgr.h"
#include "ObjMgr.h"

CDoor4_5::CDoor4_5()
{
}

CDoor4_5::~CDoor4_5()
{
    Release();
}

void CDoor4_5::Initialize(void)
{
	m_tInfo.fCX = 102;
	m_tInfo.fCY = 54;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Door4_5.bmp", L"Door4_5");

	m_pFrameKey = L"Door4_5";
}

int CDoor4_5::Update(void)
{
	Update_Rect();
	return 0;
}

void CDoor4_5::Late_Update(void)
{
}

void CDoor4_5::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Door4_5");
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

void CDoor4_5::Release(void)
{
}

void CDoor4_5::OnCollision(DIRECTION eDir, CObj* other)
{
	if (eDir == DIR_DOWN)
	{
		CSceneMgr::Get_Instance()->Scene_Change(SC_STAGE5);
		CObjMgr::Get_Instance()->Get_Player()->Set_Pos(400, 490);
		return;
	}
}
