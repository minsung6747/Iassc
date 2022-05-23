#pragma once
#include "Obj.h"
class CBackDoorItem_5 : public CObj
{
public:
	CBackDoorItem_5();
	~CBackDoorItem_5();
public:
	virtual		void Initialize(void) override;
	virtual		int Update(void) override;
	virtual		void	Late_Update(void);
	virtual		void Render(HDC hDC) override;
	virtual		void Release(void) override;


public:
	virtual void OnCollision(DIRECTION eDir, CObj* other);
};

