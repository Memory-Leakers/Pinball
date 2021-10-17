#ifndef _BOING_H_
#define _BOING_H_

#include "Application.h"
#include "GameObject.h"
//#include "Point.h"

class Boing : public GameObject 
{
private:
	Point<int> pos;
	SDL_Texture* texture = nullptr;
	

public:

	Boing(Point<int> pos);

	~Boing();

	void OnCollision(PhysBody* col) override;

};
#endif // !_BOING_H_



