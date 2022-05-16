#pragma once
#include "Obj.h"
class CDoor1_4 : public CObj
{
public:
	CDoor1_4();
	~CDoor1_4();
public:
	virtual		void Initialize(void) override;
	virtual		int Update(void) override;
	virtual		void	Late_Update(void);
	virtual		void Render(HDC hDC) override;
	virtual		void Release(void) override;


public:
	virtual void OnCollision(DIRECTION eDir, CObj* other);
};

