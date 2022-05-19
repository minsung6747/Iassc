#include "Include.h"
#include "Obj.h"

class CGameMgr
{
public:
	CGameMgr();
	~CGameMgr();

public:
	static		CGameMgr* Get_Instance(void)
	{
		if (!m_pInstance)
		{
			m_pInstance = new CGameMgr;
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
	//GameMgr이 있어야할 기능은?
	//시간,포인트
public:
	
	int Get_Time() { return time; }
	void Set_Time(float _time) { time = _time; }

	void Release();

public:
	void PlusCoin();
private:
	static CGameMgr* m_pInstance;
	
	int iCoin;
	float time;

};
