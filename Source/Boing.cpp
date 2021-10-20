#include "Boing.h"


Boing::Boing(SDL_Texture* tex, std::string name,std::string tag)
{
	this->tag = tag;
	this->texture = tex;
	this->name = name;
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