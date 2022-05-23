#include "stdafx.h"
#include "TripleShot.h"
#include "BmpMgr.h"
#include "Player.h"
#include "GameMgr.h"
CTripleShot::CTripleShot()
{
}

CTripleShot::~CTripleShot()
{
	Release();
}

void CTripleShot::Initialize(void)
{
	m_tInfo.fCX = 41;
	m_tInfo.fCY = 41;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Tripleshotitem.bmp", L"Tripleshotitem");

	m_pFrameKey = L"Tripleshotitem";
}

int CTripleShot::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	Update_Rect();


	return 0;
}

void CTripleShot::Late_Update(void)
{
	Move_Frame();
}

void CTripleShot::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Tripleshotitem");
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

void CTripleShot::Release(void)
{
}

void CTripleShot::OnCollision(CObj* other)
{
	Set_Dead();
	dynamic_cast<CPlayer*>(other)->Set_tripleShot();
	CGameMgr::Get_Instance()->Set_bTripleShot();
}
