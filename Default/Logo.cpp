#include "stdafx.h"
#include "Logo.h"
#include "BmpMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "AbstractFactory.h"
#include "MyButton.h"
#include "ObjMgr.h"


CLogo::CLogo()
{
}

CLogo::~CLogo()
{
	Release();
}

void CLogo::Initialize(void)
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Logo.bmp", L"Logo");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Start.bmp", L"Start");

	CObj* pButton = CAbstractFactory<CMyButton>::Create(390.f, 480.f);
	pButton->Set_FrameKey(L"Start");
	CObjMgr::Get_Instance()->Add_Object(OBJ_BUTTON, pButton);
	//CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CMyButton>::Create(390.f, 400.f));
}

void CLogo::Update(void)
{
	CObjMgr::Get_Instance()->Update();
}

void CLogo::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CLogo::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Logo");
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
	CObjMgr::Get_Instance()->Render(hDC);
}

void CLogo::Release(void)
{
	CObjMgr::Get_Instance()->Delete_ID(OBJ_BUTTON);
	//CObjMgr::Get_Instance()->Delete_ID(OBJ_BLOCK);


}
