#include "Boing.h"
#include <math.h>


Boing::Boing(SDL_Texture* tex, std::string name,std::string tag)
{
	this->tag = tag;
	this->texture = tex;
	this->name = name;
}

Boing::~Boing()
{
	
}

void Boing::Update() 
{
	
}




void Boing::OnCollision(PhysBody* col)
{
	
}