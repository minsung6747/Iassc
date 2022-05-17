#pragma once
#include "Obj.h"
class CDoor3_Boss : public CObj
{
public:
	CDoor3_Boss();
	~CDoor3_Boss();
public:
	virtual		void Initialize(void) override;
	virtual		int Update(void) override;
	virtual		void	Late_Update(void);
	virtual		void Render(HDC hDC) override;
	virtual		void Release(void) override;


public:
	virtual void OnCollision(DIRECTION eDir, CObj* other);
};

