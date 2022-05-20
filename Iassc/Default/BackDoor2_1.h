#pragma once
#include "Obj.h"
class CBackDoor2_1 : public CObj
{
public:
	CBackDoor2_1();
	~CBackDoor2_1();
public:
	virtual		void Initialize(void) override;
	virtual		int Update(void) override;
	virtual		void	Late_Update(void);
	virtual		void Render(HDC hDC) override;
	virtual		void Release(void) override;


public:
	virtual void OnCollision(DIRECTION eDir, CObj* other);
};

