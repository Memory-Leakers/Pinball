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

	Boing(std::string name, std::string tag, Application* _app);

	~Boing();

	void PreUpdate() override;

	void Update() override;

	void PostUpdate() override;

	void OnCollision(PhysBody* col) override;
};
#endif // !_BOING_H_



