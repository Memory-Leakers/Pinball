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
	int counter = 0; 
	bool isActive = true;

public:

	Boing(std::string name, std::string tag, Application* _app, int x, int y, int radius = 18);

	~Boing();

	void PreUpdate() override;

	void Update() override;

	void PostUpdate() override;

	void OnCollision(PhysBody* col) override;

	void setLayer(int layer);
};
#endif // !_BOING_H_



