#include "Boing.h"


Boing::Boing(SDL_Texture* tex,std::string tag)
{
	this->tag = tag;
	this->texture = tex;
}

Boing::~Boing()
{
}

void Boing::OnCollision(PhysBody* col)
{
	if (col->gameObject->CompareTag("Ball")) 
	{
		b2Vec2 velocity;

		velocity = col->body->GetLinearVelocity();

		

		b2Vec2 normal;
		
		

		//Vectorvelocidad.reflected
	}
}