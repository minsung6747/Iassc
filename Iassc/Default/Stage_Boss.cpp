#include "stdafx.h"
#include "Stage_Boss.h"
#include "BmpMgr.h"
#include "SoundMgr.h"
#include "AbstractFactory.h"
#include "Monstro.h"
CStage_Boss::CStage_Boss()
{
}

CStage_Boss::~CStage_Boss()
{
	Release();
}

void CStage_Boss::Initialize(void)
{
	CSoundMgr::Get_Instance()->StopSound(SOUND_BGM);
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Stage_Boss.bmp", L"Stage_Boss");
	CSoundMgr::Get_Instance()->PlaySoundW(L"BossStart.wav", SOUND_BOSS, g_fSound);

	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTRO, CAbstractFactory<CMonstro>::Create(300, 400));


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
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY); //그림을 그리는것 이미지를 그리는 함수 
	CObjMgr::Get_Instance()->Render(hDC);
}

void CStage_Boss::Release(void)
{
}
