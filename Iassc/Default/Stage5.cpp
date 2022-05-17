#include "stdafx.h"
#include "Stage5.h"
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
#include "Ddong.h"
#include "DoorItem.h"
CStage5::CStage5()
{
}

CStage5::~CStage5()
{
	Release();
}

void CStage5::Initialize(void)
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Stage5.bmp", L"Stage5");
	CObjMgr::Get_Instance()->Add_Object(OBJ_DOOR, CAbstractFactory<CDoorItem>::Create(40, 350));

	
	CObjMgr::Get_Instance()->Add_Object(OBJ_OBSTACLE, CAbstractFactory<CDdong>::Create(100, 200));
	CObjMgr::Get_Instance()->Add_Object(OBJ_OBSTACLE, CAbstractFactory<CDdong>::Create(100, 500));
	CObjMgr::Get_Instance()->Add_Object(OBJ_OBSTACLE, CAbstractFactory<CDdong>::Create(700, 500));
	CObjMgr::Get_Instance()->Add_Object(OBJ_OBSTACLE, CAbstractFactory<CDdong>::Create(700, 200));

	CObjMgr::Get_Instance()->Add_Object(OBJ_FLY, CAbstractFactory<CFly>::Create(400, 300));

	CObjMgr::Get_Instance()->Add_Object(OBJ_HOPPER, CAbstractFactory<CHopper>::Create(200, 300));
	CObjMgr::Get_Instance()->Add_Object(OBJ_HOPPER, CAbstractFactory<CHopper>::Create(400, 300));

	for (auto& iter : *CObjMgr::Get_Instance()->Get_List(OBJ_FLY))
	{
		iter->Set_Target(CObjMgr::Get_Instance()->Get_Player());          //STAGE OBJLIST

	}

	for (auto& iter : *CObjMgr::Get_Instance()->Get_List(OBJ_HOPPER))
	{
		iter->Set_Target(CObjMgr::Get_Instance()->Get_Player());          //STAGE OBJLIST

	}

}

void CStage5::Update(void)
{
	CObjMgr::Get_Instance()->Update();

}

void CStage5::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();
}


void CStage5::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Stage5");
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY); //그림을 그리는것 이미지를 그리는 함수 
	CObjMgr::Get_Instance()->Render(hDC);
}


void CStage5::Release(void)
{
	CObjMgr::Get_Instance()->Delete_ID(OBJ_DOOR);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_OBSTACLE);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_FLY);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_HOPPER);

}
