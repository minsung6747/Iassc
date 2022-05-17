#pragma once
#include "Obj.h"
class CDdong : public CObj
{
public:
	CDdong();
	~CDdong();
public:
	virtual		void Initialize(void) override;
	virtual		int Update(void) override;
	virtual		void	Late_Update(void);
	virtual		void Render(HDC hDC) override;
	virtual		void Release(void) override;

public:
	void OnCollision(CObj*);

private:
	float m_DdongDie_fCX;
	float m_DdongDie_fCY;

	bool DdongDieCheck;
};

