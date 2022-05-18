#include "stdafx.h"
#include "Stage.h"
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
#include "Door1_4.h"
#include "Monstro.h"
CStage::CStage()
{
}

CStage::~CStage()
{
	Release();
}

void CStage::Initialize(void)
{
	

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Stage.bmp", L"Stage");

	//CObj* pBullet = CAbstractFactory<CBullet>::Create();
	if (!CObjMgr::Get_Instance()->IsPlayer())
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create());

	}
	CObjMgr::Get_Instance()->Add_Object(OBJ_DOOR, CAbstractFactory<CDoor>::Create(762, 350));
	CObjMgr::Get_Instance()->Add_Object(OBJ_DOOR, CAbstractFactory<CDoor1_4>::Create(100, 350));

	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTRO, CAbstractFactory<CMonstro>::Create(300, 400));
	//CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create());
	
	//CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(300, 400));
	//for (int i = 0; i < 2; ++i)
	//{
	//	CObjMgr::Get_Instance()->Add_Object(OBJ_FLY, CAbstractFactory<CFly>::Create(500 + 10 * i, 400));
	//}//OBJMGR

	//CObjMgr::Get_Instance()->Add_Object(OBJ_FIRE, CAbstractFactory<CFire>::Create(600, 350));
	//CObjMgr::Get_Instance()->Add_Object(OBJ_HOPPER, CAbstractFactory<CHopper>::Create(400, 350));


	//CObjMgr::Get_Instance()->Add_Object(OBJ_ENVY, CAbstractFactory<CEnvy>::Create(500, 350));
	//CObjMgr::Get_Instance()->Add_Object(OBJ_MACK, CAbstractFactory<CMack>::Create(500, 300));




	//for (auto& iter : *CObjMgr::Get_Instance()->Get_List(OBJ_FLY))
	//{
	//	iter->Set_Target(CObjMgr::Get_Instance()->Get_Player());          //STAGE OBJLIST

	//}
	//for (auto& iter : *CObjMgr::Get_Instance()->Get_List(OBJ_HOPPER))
	//{
	//	iter->Set_Target(CObjMgr::Get_Instance()->Get_Player());          //STAGE OBJLIST

	//}
	//for (auto& iter : *CObjMgr::Get_Instance()->Get_List(OBJ_MACK))
	//{
	//	iter->Set_Target(CObjMgr::Get_Instance()->Get_Player());          //STAGE OBJLIST

	//}
	//CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, pBullet);
	//m_ObjList[OBJ_PLAYER].push_back(CAbstractFactory<CPlayer>::Create(200.f,400.f));
	//dynamic_cast<CPlayer*>(pPlayer)->Set_BulletList(&m_ObjList[OBJ_BULLET]);

}

void CStage::Update(void)
{
	CObjMgr::Get_Instance()->Update();
}

void CStage::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CStage::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Stage");
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY); //그림을 그리는것 이미지를 그리는 함수 
	CObjMgr::Get_Instance()->Render(hDC);
}

void CStage::Release(void)
{
	/*CObjMgr::Get_Instance()->Delete_ID(OBJ_BLOCK);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_FLY);*/
	//CObjMgr::Get_Instance()->Delete_ID(OBJ_HOPPER);
	/*CObjMgr::Get_Instance()->Delete_ID(OBJ_FIRE);*/
	CObjMgr::Get_Instance()->Delete_ID(OBJ_DOOR);
	
	
}
