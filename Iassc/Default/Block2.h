#pragma once
#include "Obj.h"

class CBlock2 : public CObj
{
public:
	CBlock2();
	~CBlock2();

public:
	virtual		void Initialize(void) override;
	virtual		int Update(void) override;
	virtual		void	Late_Update(void);
	virtual		void Render(HDC hDC) override;
	virtual		void Release(void) override;
};