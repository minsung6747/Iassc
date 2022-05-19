#include "Obj.h"
class CCoin : public CObj
{
public:
	CCoin();
	~CCoin();

public:
	virtual		void	Initialize(void) override;
	virtual		int		Update(void) override;
	virtual		void	Late_Update(void);
	virtual		void	Render(HDC hDC) override;
	virtual		void	Release(void) override;

public:
	
	

public:
	void OnCollision(CObj* other);
private:
	int iHowBullet;


};

