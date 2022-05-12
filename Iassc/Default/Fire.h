#pragma once
#include "Obj.h"
class CFire : public CObj
{
public:
	CFire();
	~CFire();
public:
	virtual		void Initialize(void) override;
	virtual		int Update(void) override;
	virtual		void	Late_Update(void);
	virtual		void Render(HDC hDC) override;
	virtual		void Release(void) override;

public:
	void OnCollision(CObj*);

private:
	float m_FireDie_fCX;
	float m_FireDie_fCY;

	bool FireDieCheck;
};

