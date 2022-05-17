#pragma once
#include "Obj.h"
class CMack : public CObj
{
public:
	CMack();
	~CMack();

public:
	virtual		void	Initialize(void) override;
	virtual		int		Update(void) override;
	virtual		void	Late_Update(void);
	virtual		void	Render(HDC hDC) override;
	virtual		void	Release(void) override;

public:
	void		Set_Target(CObj* _pTarget) { m_pTarget = _pTarget; }
	CObj*		Create_Bullet();

public:
	void OnCollision(CObj* other);
private:
	int iHowBullet;
	
	
};

