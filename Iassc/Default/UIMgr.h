#pragma once
#pragma once

#include "Include.h"

class CUIMgr
{
public:
	CUIMgr();
	~CUIMgr();

public:
	static		CUIMgr* Get_Instance(void)
	{
		if (!m_pInstance)
		{



			m_pInstance = new CUIMgr;
		}

		return m_pInstance;
	}

	static	void	Destroy_Instance(void)
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

public:
	void SetScore(int iScore) { m_iScore = iScore; }
	void SetLifeCount(int iLifeCount) { m_iLifeCount = iLifeCount; }

public:
	void	Initialize();
	void	Update(void);
	void	Render(HDC hDC);
	void	Release();

public:
	void RenderCoin(int _iCoin);
	void Move_Frame();

private:
	static CUIMgr* m_pInstance;

	
	int		m_iScore;
	int		m_iLifeCount;
	FRAME		m_tFrame;
	
	float UIcount_fCX;
	float UIcount_fCY;

	int		iR;
	int		iG;
	int		iB;
};

