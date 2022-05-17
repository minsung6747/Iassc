#include "stdafx.h"
#include "Stage_Item.h"
#include "BmpMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "Player.h"
#include "AbstractFactory.h"

#include "Fire.h"

CStage_Item::CStage_Item()
{
}

CStage_Item::~CStage_Item()
{
	Release();
}

void CStage_Item::Initialize(void)
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Stage_Item.bmp", L"Stage_Item");
}

void CStage_Item::Update(void)
{
	CObjMgr::Get_Instance()->Update();
}

void CStage_Item::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();

}

void CStage_Item::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Stage_Item");
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY); //그림을 그리는것 이미지를 그리는 함수 
	CObjMgr::Get_Instance()->Render(hDC);
}

void CStage_Item::Release(void)
{
}
