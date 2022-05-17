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
	m_tFrame.iFrameEnd = 1;  //가로
	m_tFrame.iMotion = 0;    //세로
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

		float		fRadian = acosf(fWidth / fDiagonal);	// acos값으로 나올 수 있는 각도의 범위는 0~180도 사이 값에 해당한다.

		/*if (m_pTarget->Get_Info().fY > m_tInfo.fY)
			fRadian = (2 * PI) - fRadian;*/

			// 라디안 값을 디그리로 치환
		m_fAngle = (fRadian * 180.f) / PI;

		if (m_pTarget->Get_Info().fY > m_tInfo.fY)
			m_fAngle *= -1.f;

		m_tInfo.fX += m_fSpeed * cosf((m_fAngle)*PI / 180.f);
		m_tInfo.fY -= m_fSpeed * sinf((m_fAngle)*PI / 180.f);
		
	}
	// 플레이어가 삭제될 경우 댕글링이 발생할 가능성이 있음 m_ptarget이 \
	//플레이어가 삭제되고 cfly 의 업데이트가 호출됐는데 m_ptarget이 null이 아님.
	


	
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
	GdiTransparentBlt(hDC, 					// 복사 받을, 최종적으로 그림을 그릴 DC
		int(m_tRect.left),	// 2,3 인자 :  복사받을 위치 X, Y
		int(m_tRect.top),
		int(m_tInfo.fCX),				// 4,5 인자 : 복사받을 가로, 세로 길이
		int(m_tInfo.fCY),
		hMemDC,							// 비트맵을 가지고 있는 DC
		m_tFrame.iFrameStart * (int)m_tInfo.fCX,								// 비트맵 출력 시작 좌표, X,Y
		m_tFrame.iMotion * (int)m_tInfo.fCY,
		(int)m_tInfo.fCX,				// 복사할 비트맵의 가로, 세로 길이
		(int)m_tInfo.fCY,
		RGB(255, 255, 255));			// 제거하고자 하는 색상
}

void CFly::Release(void)
{
}

void CFly::OnCollision(CObj* other)
{
	Set_Dead();
}
