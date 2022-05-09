#pragma once
#include "Obj.h"
#include "Bullet.h"

class CPlayer : public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	void	Set_BulletList(list<CObj*>* pBullet)
	{
		m_pBullet = pBullet;
	}

public:
	virtual void Initialize(void) override;
	virtual int		Update(void) override;
	virtual		void	Late_Update(void);
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	void		Key_Input(void);
	CObj*		Create_Bullet(DIRECTION eDir);


private:
	typedef list<CObj*>		BULLETLIST;
	BULLETLIST*				m_pBullet;
};

/*
1. 몬스터를 생성하여 작은 사각형 안에서 벽에 부딪히면 반대방향으로 이동하는 상태를 만들어라
2. 미사일로 몬스터를 제거하라
힌트) IntersectRect 함수를 이용하라.사각형 충돌을 수행하는 함수,

1인자 : 두 박스 충돌하면서 발생한 렉트의 정보를 저장할 RECT의 주소값
2인자 : 충돌한 첫 번째 RECT의 주소값
3인자 : 충돌한 두 번째 RECT의 주소값

RECT	rc{};
IntersectRect(&rc, &몬스터, &총알);

3. 피타고라스의 정리를 보고와라 c2 = a2 + b2 */