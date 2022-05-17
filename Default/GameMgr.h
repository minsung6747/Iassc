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
	//GameMgr�� �־���� �����?
	//�ð�,����Ʈ
public:
	
	int Get_Time() { return time; }
	void Set_Time(float _time) { time = _time; }

	void Release();

private:
	static CGameMgr* m_pInstance;
	int	m_iScore;
	float time;

};
