#pragma once
#include "GameObject.h"

class Ball :  public GameObject
{
public:
	Ball() {};

	Ball(SDL_Texture* texture, SDL_Texture* shadowTexture, std::string name = "Default", std::string tag = "None");

	void OnCollision(PhysBody* col) override;

	SDL_Texture* shadow;
};

