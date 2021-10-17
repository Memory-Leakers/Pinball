#pragma once
#include "GameObject.h"

class Ball :  public GameObject
{
public:
	Ball() {};

	Ball(SDL_Texture* texture, std::string name = "Default", std::string tag = "None") :
		GameObject(texture, name, tag) {};

	void OnCollision(PhysBody* col) override;
};

