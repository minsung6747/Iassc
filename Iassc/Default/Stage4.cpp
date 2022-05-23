#include "stdafx.h"
#include "Stage4.h"
#include "BmpMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "Player.h"
#include "AbstractFactory.h"
#include "Bullet.h"
#include "Block.h"
#include "Fly.h"
#include "Block.h"
#include "Door.h"
#include "Fire.h"
#include "Hopper.h"
#include "Envy.h"
#include "Mack.h"
#include "Block3.h"
#include "Door4_5.h"
#include "BackDoor4_1.h"
#include "UIMgr.h"

CStage4::CStage4()
{
}

CStage4::~CStage4()
{
	Release();
}

void CStage4::Initialize(void)
{
	CUIMgr::Get_Instance()->Initialize();

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Stage4.bmp", L"Stage4");
	CObjMgr::Get_Instance()->Add_Object(OBJ_DOOR, CAbstractFactory<CDoor4_5>::Create(400, 145));
	CObjMgr::Get_Instance()->Add_Object(OBJ_DOOR, CAbstractFactory<CBackDoor4_1>::Create(760,350));
	if (exIhowMack < 4)
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_MACK, CAbstractFactory<CMack>::Create(100, 200));
		CObjMgr::Get_Instance()->Add_Object(OBJ_MACK, CAbstractFactory<CMack>::Create(100, 500));
		CObjMgr::Get_Instance()->Add_Object(OBJ_MACK, CAbstractFactory<CMack>::Create(700, 500));
		CObjMgr::Get_Instance()->Add_Object(OBJ_MACK, CAbstractFactory<CMack>::Create(700, 200));
	}

	//CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock3>::Create(300, 400));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock3>::Create(300, 450));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock3>::Create(300, 290));
	//CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock3>::Create(300, 240));

	//CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock3>::Create(500, 400));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock3>::Create(500, 450));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock3>::Create(500, 290));
	//CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock3>::Create(500, 240));
	

}

void CStage4::Update(void)
{
	CObjMgr::Get_Instance()->Update();

}

void CStage4::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CStage4::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Stage4");
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY); //그림을 그리는것 이미지를 그리는 함수 
	CObjMgr::Get_Instance()->Render(hDC);
	CUIMgr::Get_Instance()->RenderCoin(hDC);
	CUIMgr::Get_Instance()->RenderArrows(hDC,false);


}

void CStage4::Release(void)
{
	CObjMgr::Get_Instance()->Delete_ID(OBJ_BLOCK);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_DOOR);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_MACK);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_MBULLET);
	//CObjMgr::Get_Instance()->Delete_ID(OBJ_OBSTACLE);
}
