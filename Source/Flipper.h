#pragma once
#include "GameObject.h"
class Flipper : public GameObject
{
public:
	Flipper() {};

	Flipper(SDL_Texture* texture, std::string name = "Default", std::string tag = "Node")
		:GameObject(texture, name, tag) {};

	void OnCollision(PhysBody* col) override;
};

