#pragma once
#include "Scene.h"
#include "ObjMgr.h"
class CStage_Item : public CScene
{
public:
	CStage_Item();
	~CStage_Item();
public:

	void	Initialize(void);
	void	Update(void);
	void	Late_Update(void);
	void	Render(HDC hDC);
	void	Release(void);
private:


};

