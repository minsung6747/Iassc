#pragma once
#include "Obj.h"
class CMonsterBullet :
	public CObj
{
public:
	CMonsterBullet();
	virtual ~CMonsterBullet();

public:
	virtual		void Initialize(void) override;
	virtual		int Update(void) override;
	virtual		void	Late_Update(void);
	virtual		void Render(HDC hDC) override;
	virtual		void Release(void) override;

public:
	virtual void OnCollision(CObj* other);

private:
	int  bCheckBullet;
	int  bDeadEffectTime;

	float fBulletDie_fCX;
	float fBulletDie_fCY;

};

