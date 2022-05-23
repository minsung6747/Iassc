#include "Obj.h"
class CTripleShot : public CObj
{
public:
	CTripleShot();
	~CTripleShot();

public:
	virtual		void	Initialize(void) override;
	virtual		int		Update(void) override;
	virtual		void	Late_Update(void);
	virtual		void	Render(HDC hDC) override;
	virtual		void	Release(void) override;




public:
	void OnCollision(CObj* other);
private:


};

