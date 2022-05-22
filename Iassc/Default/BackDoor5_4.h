#pragma once
#include "Obj.h"
class CBackDoor5_4 : public CObj
{
public:
	CBackDoor5_4();
	~CBackDoor5_4();
public:
	virtual		void Initialize(void) override;
	virtual		int Update(void) override;
	virtual		void	Late_Update(void);
	virtual		void Render(HDC hDC) override;
	virtual		void Release(void) override;


public:
	virtual void OnCollision(DIRECTION eDir, CObj* other);
};

