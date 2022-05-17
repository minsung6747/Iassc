#pragma once
#include "Obj.h"
#include "Bullet.h"

class CPlayer : public CObj
{
public:
	enum STATE { IDLE,	WALK,SHOT_UP,SHOT_DOWN,SHOT_LEFT,SHOT_RIGHT, END };
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
	void		Motion_Change(void);

private:
	typedef list<CObj*>		BULLETLIST;
	BULLETLIST*				m_pBullet;



	STATE					m_ePreState;
	STATE					m_eCurState;
};

/*
1. ���͸� �����Ͽ� ���� �簢�� �ȿ��� ���� �ε����� �ݴ�������� �̵��ϴ� ���¸� ������
2. �̻��Ϸ� ���͸� �����϶�
��Ʈ) IntersectRect �Լ��� �̿��϶�.�簢�� �浹�� �����ϴ� �Լ�,

1���� : �� �ڽ� �浹�ϸ鼭 �߻��� ��Ʈ�� ������ ������ RECT�� �ּҰ�
2���� : �浹�� ù ��° RECT�� �ּҰ�
3���� : �浹�� �� ��° RECT�� �ּҰ�

RECT	rc{};
IntersectRect(&rc, &����, &�Ѿ�);

3. ��Ÿ������ ������ �����Ͷ� c2 = a2 + b2 */