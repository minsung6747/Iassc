#pragma once
#include "Scene.h"
#include "ObjMgr.h"
class CStage2 : public CScene
{
public:
	CStage2();
	~CStage2();
public:

	void	Initialize(void);
	void	Update(void);
	void	Late_Update(void);
	void	Render(HDC hDC);
	void	Release(void);
private:


};

