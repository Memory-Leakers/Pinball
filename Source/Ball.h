#pragma once
#include "GameObject.h"

class Ball :  public GameObject
{
public:
	Ball() {};

	Ball(std::string name,SDL_Texture* t);
};

