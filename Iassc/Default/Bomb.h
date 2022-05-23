#include "Obj.h"
class CBomb : public CObj
{
public:
	CBomb();
	~CBomb();

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
	

};

