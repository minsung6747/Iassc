#include "stdafx.h"
#include "Bomb.h"
#include "BmpMgr.h"
#include "GameMgr.h"

CBomb::CBomb()
{
}

CBomb::~CBomb()
{
	Release();
}

void CBomb::Initialize(void)
{
	m_tInfo.fCX = 37.f;
	m_tInfo.fCY = 34.f;
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Bomb.bmp", L"Bomb");

	m_pFrameKey = L"Bomb";
}

int CBomb::Update(void)
{

	if (m_bDead)
		return OBJ_DEAD;
	Update_Rect();

	return 0;
}

void CBomb::Late_Update(void)
{
	Move_Frame();
}

void CBomb::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Bomb");
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

void CBomb::Release(void)
{
}

void CBomb::OnCollision(CObj* other)
{
	Set_Dead();
	CGameMgr::Get_Instance()->PlusBomb();
}
