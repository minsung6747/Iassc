#pragma once
#include "Scene.h"
#include "ObjMgr.h"
class CStage5 : public CScene
{
public:
	CStage5();
	~CStage5();
public:

	void	Initialize(void);
	void	Update(void);
	void	Late_Update(void);
	void	Render(HDC hDC);
	void	Release(void);
private:


};

