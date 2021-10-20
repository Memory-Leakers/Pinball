#include "Ball.h"

Ball::Ball(SDL_Texture* texture, SDL_Texture* shadowTexture, std::string name, std::string tag)
{
	this->texture = texture;
	this->shadow = shadowTexture;
	this->name = name;
	this->tag = tag;
}


void Ball::PreUpdate()
{
	//pBody->body->GetFixtureList()[0].SetRestitution(0.25f);
}

void Ball::OnCollision(PhysBody* col)
{
	if (col->gameObject && col->gameObject->CompareTag("Boing"))
	{
		//pBody->body->GetFixtureList()[0].SetRestitution(1);
	}

	printf("Col Ball");
}

