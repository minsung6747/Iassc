#pragma once
#include "Obj.h"

class CBlock3 : public CObj
{
public:
	CBlock3();
	~CBlock3();

public:
	virtual		void Initialize(void) override;
	virtual		int Update(void) override;
	virtual		void	Late_Update(void);
	virtual		void Render(HDC hDC) override;
	virtual		void Release(void) override;
};