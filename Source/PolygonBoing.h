#ifndef _POLYGONBOING_H_
#define _POLYGONBOING_h_

#include "GameObject.h"
#include "ModulePhysics.h"

class PolygonBoing : public GameObject
{
private:
	Point<int> pos;
	SDL_Texture* texture = nullptr;
	int Offsetx;
	int Offsety;
	float AngularOffset;
	int count = 0;
	bool norestitution = false;

public:

	PolygonBoing(std::string name, std::string tag, Application* _app,int x, int y, int* points, int numberPoints,int Id,bool isRight);

	PolygonBoing(std::string name, std::string tag, Application* _app, int x, int y, int* points, int numberPoints,float rotation, iPoint offset, float Scale);

	~PolygonBoing();

	void PreUpdate() override;

	void Update() override;

	void PostUpdate() override;

	void OnCollision(PhysBody* col) override;

	void setSensor(bool value);

};
#endif // !_POLYGONBOING_H_

