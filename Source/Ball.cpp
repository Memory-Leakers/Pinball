#include "Ball.h"

Ball::Ball(std::string name, SDL_Texture* t) :GameObject(name)
{
	this->texture = t;
}