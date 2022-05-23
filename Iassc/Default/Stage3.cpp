#include "stdafx.h"
#include "Stage3.h"
#include "BmpMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "Player.h"
#include "AbstractFactory.h"
#include "Bullet.h"
#include "Block.h"
#include "Fly.h"
#include "Block2.h"
#include "Ddong.h"
#include "BackDoor3_2.h"
#include "Envy.h"
#include "Door3_Boss.h"
#include "UIMgr.h"
CStage3::CStage3()
{
}

CStage3::~CStage3()
{
	Release();
}

void CStage3::Initialize(void)
{
	CUIMgr::Get_Instance()->Initialize();

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Stage3.bmp", L"Stage3");
	CObjMgr::Get_Instance()->Add_Object(OBJ_DOOR, CAbstractFactory<CDoor3_Boss>::Create(760, 350));
	CObjMgr::Get_Instance()->Add_Object(OBJ_DOOR, CAbstractFactory<CBackDoor3_2>::Create(50, 350));

	if (exIhowEnvy < 4)
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_ENVY, CAbstractFactory<CEnvy>::Create(300, 300));
		CObjMgr::Get_Instance()->Add_Object(OBJ_ENVY, CAbstractFactory<CEnvy>::Create(350, 350));
		CObjMgr::Get_Instance()->Add_Object(OBJ_ENVY, CAbstractFactory<CEnvy>::Create(400, 400));
		CObjMgr::Get_Instance()->Add_Object(OBJ_ENVY, CAbstractFactory<CEnvy>::Create(450, 450));
	}
	
}

void CStage3::Update(void)
{
	CObjMgr::Get_Instance()->Update();
}

void CStage3::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CStage3::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Stage3");
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY); //그림을 그리는것 이미지를 그리는 함수 
	CObjMgr::Get_Instance()->Render(hDC);
	CUIMgr::Get_Instance()->RenderCoin(hDC);
	CUIMgr::Get_Instance()->RenderArrows(hDC,false);


}

void CStage3::Release(void)
{
	CObjMgr::Get_Instance()->Delete_ID(OBJ_ENVY);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_DOOR);

}
