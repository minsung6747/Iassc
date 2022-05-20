#pragma once
#include "Obj.h"
class CBackDoor3_2 : public CObj
{
public:
	CBackDoor3_2();
	~CBackDoor3_2();
public:
	virtual		void Initialize(void) override;
	virtual		int Update(void) override;
	virtual		void	Late_Update(void);
	virtual		void Render(HDC hDC) override;
	virtual		void Release(void) override;


public:
	virtual void OnCollision(DIRECTION eDir, CObj* other);
};

