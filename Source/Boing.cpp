#include "Boing.h"
#include <math.h>


Boing::Boing(std::string name,std::string tag, Application* _app) : GameObject(name, tag, _app)
{
	// Create PhysBody
	pBody = _app->physics->CreateCircle(85, 340, 18, this);
	pBody->body->SetType(b2BodyType::b2_kinematicBody);
	pBody->body->GetFixtureList()[0].SetRestitution(1.25f);
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