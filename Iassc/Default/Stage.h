#pragma once
#include "Scene.h"
#include "ObjMgr.h"
class CStage : public CScene
{
public:
	CStage();
	virtual ~CStage();
public:

	void	Initialize(void);
    void	Update(void);
	void	Late_Update(void);
	void	Render(HDC hDC);
	void	Release(void);
private:
	
	
};

