#pragma once
#include "GameObject.h"
class Flipper : public GameObject
{
public:
	Flipper() {};

	Flipper(std::string name, SDL_Texture* texture) :GameObject(name, texture) {};

	void OnCollision(PhysBody* col) override;
};

