#pragma once
#include "Scene.h"
#include "ObjMgr.h"
class CStage_Boss : public CScene
{
public:
	CStage_Boss();
	~CStage_Boss();
public:

	void	Initialize(void);
	void	Update(void);
	void	Late_Update(void);
	void	Render(HDC hDC);
	void	Release(void);
private:


};

