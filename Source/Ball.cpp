#include "Ball.h"

Ball::Ball(SDL_Texture* texture, SDL_Texture* shadowTexture, std::string name, std::string tag)
{
	this->texture = texture;
	this->shadow = shadowTexture;
	this->name = name;
	this->tag = tag;
}

void Ball::OnCollision(PhysBody* col)
{
	printf("Col Ball");
}