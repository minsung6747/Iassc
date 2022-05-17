#include "stdafx.h"
#include "Fly.h"
#include "BmpMgr.h"
CFly::CFly()
{
}

CFly::~CFly()
{
    Release();
}

void CFly::Initialize(void)
{
	m_pTarget = nullptr;
    m_tInfo.fCX = 40;
    m_tInfo.fCY = 30;
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Fly.bmp", L"Fly");
	
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 1;  //����
	m_tFrame.iMotion = 0;    //����
	m_tFrame.dwSpeed = 200;
	m_tFrame.dwTime = GetTickCount();
	m_pFrameKey = L"Fly";
	m_fSpeed = 1;
	
}

int CFly::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;
	if (m_pTarget != nullptr)
	{
		float		fWidth = m_pTarget->Get_Info().fX - m_tInfo.fX;
		float		fHeight = m_pTarget->Get_Info().fY - m_tInfo.fY;

		float		fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);

		float		fRadian = acosf(fWidth / fDiagonal);	// acos������ ���� �� �ִ� ������ ������ 0~180�� ���� ���� �ش��Ѵ�.

		/*if (m_pTarget->Get_Info().fY > m_tInfo.fY)
			fRadian = (2 * PI) - fRadian;*/

			// ���� ���� ��׸��� ġȯ
		m_fAngle = (fRadian * 180.f) / PI;

		if (m_pTarget->Get_Info().fY > m_tInfo.fY)
			m_fAngle *= -1.f;

		m_tInfo.fX += m_fSpeed * cosf((m_fAngle)*PI / 180.f);
		m_tInfo.fY -= m_fSpeed * sinf((m_fAngle)*PI / 180.f);
		
	}
	// �÷��̾ ������ ��� ��۸��� �߻��� ���ɼ��� ���� m_ptarget�� \
	//�÷��̾ �����ǰ� cfly �� ������Ʈ�� ȣ��ƴµ� m_ptarget�� null�� �ƴ�.
	


	
	Update_Rect();


    return 0;
}

void CFly::Late_Update(void)
{
}

void CFly::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);
	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	GdiTransparentBlt(hDC, 					// ���� ����, ���������� �׸��� �׸� DC
		int(m_tRect.left),	// 2,3 ���� :  ������� ��ġ X, Y
		int(m_tRect.top),
		int(m_tInfo.fCX),				// 4,5 ���� : ������� ����, ���� ����
		int(m_tInfo.fCY),
		hMemDC,							// ��Ʈ���� ������ �ִ� DC
		m_tFrame.iFrameStart * (int)m_tInfo.fCX,								// ��Ʈ�� ��� ���� ��ǥ, X,Y
		m_tFrame.iMotion * (int)m_tInfo.fCY,
		(int)m_tInfo.fCX,				// ������ ��Ʈ���� ����, ���� ����
		(int)m_tInfo.fCY,
		RGB(255, 255, 255));			// �����ϰ��� �ϴ� ����
}

void CFly::Release(void)
{
}

void CFly::OnCollision(CObj* other)
{
	Set_Dead();
}
