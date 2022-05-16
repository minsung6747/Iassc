#pragma once
#include "Obj.h"
class CDoor4_5 : public CObj
{
public:
	CDoor4_5();
	~CDoor4_5();
public:
	virtual		void Initialize(void) override;
	virtual		int Update(void) override;
	virtual		void	Late_Update(void);
	virtual		void Render(HDC hDC) override;
	virtual		void Release(void) override;


public:
	virtual void OnCollision(DIRECTION eDir, CObj* other);
};

