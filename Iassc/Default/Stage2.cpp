#include "stdafx.h"
#include "Stage2.h"
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
#include "Door.h"
#include "Door2_3.h"
#include "BackDoor2_1.h"


CStage2::CStage2()
{
}

CStage2::~CStage2()
{
	Release();
}

void CStage2::Initialize(void)
{
	

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Stage2.bmp", L"Stage2");
	CObjMgr::Get_Instance()->Get_Player()->Set_Pos(150, 350);
	
	/*statInfo FlyStat = { 2,0,1 };*/
	
	
	CObjMgr::Get_Instance()->Add_Object(OBJ_DOOR, CAbstractFactory<CDoor2_3>::Create(760, 350));
	CObjMgr::Get_Instance()->Add_Object(OBJ_DOOR, CAbstractFactory<CBackDoor2_1>::Create(50, 350));


	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock2>::Create(100, 200));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(100, 500));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock2>::Create(700, 500));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(700, 200));

	CObjMgr::Get_Instance()->Add_Object(OBJ_OBSTACLE, CAbstractFactory<CDdong>::Create(400,350));
	
	/*for (int i = 0; i < 4; ++i)
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_FLY, CAbstractFactory<CFly>::Create(100+20*i, 230));

	}
	for (int i = 0; i < 4; ++i)
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_FLY, CAbstractFactory<CFly>::Create(700 - 20 * i, 230));

	}
	for (int i = 0; i < 4; ++i)
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_FLY, CAbstractFactory<CFly>::Create(100 + 20 * i, 470));

	}
	for (int i = 0; i < 4; ++i)
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_FLY, CAbstractFactory<CFly>::Create(700 - 20 * i, 470));
	}*/
	if (exIhowfly < 16)
	{
		for (int i = 0; i < 4; ++i)
		{
			CObjMgr::Get_Instance()->Add_Object(OBJ_FLY, CAbstractFactory<CFly>::Create(100 + 20 * i, 230));

		}
		for (int i = 0; i < 4; ++i)
		{
			CObjMgr::Get_Instance()->Add_Object(OBJ_FLY, CAbstractFactory<CFly>::Create(700 - 20 * i, 230));

		}
		for (int i = 0; i < 4; ++i)
		{
			CObjMgr::Get_Instance()->Add_Object(OBJ_FLY, CAbstractFactory<CFly>::Create(100 + 20 * i, 470));

		}
		for (int i = 0; i < 4; ++i)
		{
			CObjMgr::Get_Instance()->Add_Object(OBJ_FLY, CAbstractFactory<CFly>::Create(700 - 20 * i, 470));

		}
		/*for (auto& iter : *CObjMgr::Get_Instance()->Get_List(OBJ_FLY))
		{
			iter->Set_StatInfo(FlyStat);
		}*/

		for (auto& iter : *CObjMgr::Get_Instance()->Get_List(OBJ_FLY))
		{
			iter->Set_Target(CObjMgr::Get_Instance()->Get_Player());          //STAGE OBJLIST

		}


	}
	

}

void CStage2::Update(void)
{
	CObjMgr::Get_Instance()->Update();
}

void CStage2::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CStage2::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Stage2");
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY); //그림을 그리는것 이미지를 그리는 함수 
	CObjMgr::Get_Instance()->Render(hDC);
}

void CStage2::Release(void)
{
	CObjMgr::Get_Instance()->Delete_ID(OBJ_BLOCK);
	//CObjMgr::Get_Instance()->Delete_ID(OBJ_DOOR);
	//CObjMgr::Get_Instance()->Delete_ID(OBJ_FLY);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_OBSTACLE);



}
