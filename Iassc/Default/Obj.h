#pragma once

#include "Include.h"

class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	void		Set_Pos(float _fX, float _fY)
	{
		m_tInfo.fX = _fX;
		m_tInfo.fY = _fY;
	}
	void		Set_Dir(DIRECTION eDir) { m_eDir = eDir; }
	void		Set_Dead() { m_bDead = true; }
	void		Set_Angle(float _fAngle) { m_fAngle = _fAngle; }
	virtual void		Set_Target(CObj* _pTarget) { m_pTarget = _pTarget; }
	void		Set_StatInfo(statInfo _tInfo) { m_tStatInfo = _tInfo; }

	void		Set_PosX(float _fX) { m_tInfo.fX += _fX; }
	void		Set_PosY(float _fY) { m_tInfo.fY += _fY; }
	void		Set_Theta(float _fTheta) { m_fTheta = _fTheta; }

	void		Set_FrameKey(TCHAR* pFrameKey) { m_pFrameKey = pFrameKey; }

	bool		Get_Dead() { return m_bDead; }


	const INFO& Get_Info(void) const { return m_tInfo; }
	const RECT& Get_Rect(void) const { return m_tRect; }
	statInfo& Get_StatInfo(void) { return m_tStatInfo; }

	

public:
	virtual		void	Initialize(void)	PURE;
	virtual		int		Update(void)		PURE;
	virtual		void	Late_Update(void)	PURE;
	virtual		void	Render(HDC hDC)		PURE;
	virtual		void	Release(void)		PURE;
	
public:
	virtual void OnCollision() {};
	virtual void OnCollision(DIRECTION eDir) {};
	virtual void OnCollision(CObj* other) {};
	virtual void OnCollision(DIRECTION eDir, CObj* other) {};

protected:
	void		Update_Rect(void);
	void		Move_Frame(void);

protected:
	INFO		m_tInfo;
	RECT		m_tRect;
	FRAME		m_tFrame;
	statInfo	m_tStatInfo;
	float		m_fSpeed;
	float		m_fAngle;
	float		m_fTheta;
	DIRECTION	m_eDir;
	bool		m_bDead;

	CObj* m_pTarget;
	TCHAR* m_pFrameKey;

	float		m_fDelay;
	float	    m_fOldTime;

};

