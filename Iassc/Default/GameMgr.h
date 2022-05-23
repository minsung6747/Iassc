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
	void Set_bTripleShot();
	void Release();

public:
	void PlusCoin();
	void PlusBomb();
	int Set_Coin() { return iCoin; }
	int Set_Bomb() { return iBomb; }
private:
	static CGameMgr* m_pInstance;
	
	int iBomb;
	bool bTripleCheck;
	int iCoin;
	float time;

};
