#pragma once

typedef	struct tagInfo
{
	float	fX;
	float	fY;
	float	fCX;
	float	fCY;

}INFO;


typedef struct tagFrame
{
	int		iFrameStart;		// ���ϴ� �������� ��������Ʈ �̹��� ���� ����
	int		iFrameEnd;			// ��������Ʈ�� ������ ������ ����
	int		iMotion;			// ��� �ε���

	DWORD	dwSpeed;			// ��������Ʈ�� ���ư��� �ӵ�
	DWORD	dwTime;				// ��������Ʈ ��ġ�� ����Ǵ� �ð� 

}FRAME;

typedef struct statInfo
{
	int		iHp;
	int		iMaxHp;
	int		iAt;
};
