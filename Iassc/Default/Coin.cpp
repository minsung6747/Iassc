#include "stdafx.h"
#include "Coin.h"
#include "BmpMgr.h"
#include "GameMgr.h"
CCoin::CCoin()
{
}

CCoin::~CCoin()
{
	Release();
}

void CCoin::Initialize(void)
{
	m_tInfo.fCX = 40.f;
	m_tInfo.fCY = 22.f;


	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Coin.bmp", L"Coin");
	
	m_pFrameKey = L"Coin";
	
}

int CCoin::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;



	Update_Rect();


	return 0;
}

void CCoin::Late_Update(void)
{
	Move_Frame();
}

void CCoin::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Coin");
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

void CCoin::Release(void)
{
}

void CCoin::OnCollision(CObj* other)
{
	Set_Dead();
	CGameMgr::Get_Instance()->PlusCoin();
}
