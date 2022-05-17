#include "stdafx.h"
#include "Stage_Boss.h"
#include "BmpMgr.h"
CStage_Boss::CStage_Boss()
{
}

CStage_Boss::~CStage_Boss()
{
	Release();
}

void CStage_Boss::Initialize(void)
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Stage_Boss.bmp", L"Stage_Boss");

}

void CStage_Boss::Update(void)
{
	CObjMgr::Get_Instance()->Update();
}

void CStage_Boss::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CStage_Boss::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Stage_Boss");
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY); //�׸��� �׸��°� �̹����� �׸��� �Լ� 
	CObjMgr::Get_Instance()->Render(hDC);
}

void CStage_Boss::Release(void)
{
}