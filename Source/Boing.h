#ifndef _BOING_H_
#define _BOING_H_

#include "GameObject.h"
#include "ModulePhysics.h"

//#include "Point.h"

class Boing : public GameObject 
{
private:
	Point<int> pos;
	SDL_Texture* texture = nullptr;
	

public:

	Boing(SDL_Texture* tex, std::string tag);

	~Boing();

	void OnCollision(PhysBody* col) override;

};
#endif // !_BOING_H_



