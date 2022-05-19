#pragma once
#include "Obj.h"

class CMonstro : public CObj
{
public:
	CMonstro();
	~CMonstro();

public:
	virtual		void	Initialize(void) override;
	virtual		int		Update(void) override;
	virtual		void	Late_Update(void);
	virtual		void	Render(HDC hDC) override;
	virtual		void	Release(void) override;

public:
	void Phase_Pattern();
	
	void NormalGun();
	void SpreadGun();

	void MovingMonstro();
	CObj* CreateBossMonsterBullet(float _fTheta, int _fx, int _fy);
	void OnCollision(CObj* other);

private:
	

	float fCooltime1Sec;
	float fCooltime3Sec;

	float fMovingCoolTimeSec;
	float fStopCoolTimeSec;

	bool bStopCheck;


};

