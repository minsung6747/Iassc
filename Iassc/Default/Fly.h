#pragma once
#include "Obj.h"
class CFly : public CObj
{
public:
	CFly();
	~CFly();

public:
	virtual		void	Initialize(void) override;
	virtual		int		Update(void) override;
	virtual		void	Late_Update(void);
	virtual		void	Render(HDC hDC) override;
	virtual		void	Release(void) override;

public:
	void		Set_Target(CObj* _pTarget) { m_pTarget = _pTarget; }
public:
	void OnCollision(CObj* other);
};

