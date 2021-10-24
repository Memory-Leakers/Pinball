#ifndef _POLYGONBOING_H_
#define _POLYGONBOING_h_

#include "GameObject.h"
#include "ModulePhysics.h"

class PolygonBoing : public GameObject
{
private:
	Point<int> pos;
	SDL_Texture* texture = nullptr;

public:

	PolygonBoing(std::string name, std::string tag, Application* _app,int x, int y, int* points, int numberPoints);

	~PolygonBoing();

	void PreUpdate() override;

	void Update() override;

	void PostUpdate() override;

	void OnCollision(PhysBody* col) override;

	void setSensor(bool value);

};
#endif // !_POLYGONBOING_H_

