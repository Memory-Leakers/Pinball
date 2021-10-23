#include "Boing.h"
#include <math.h>


Boing::Boing(std::string name,std::string tag, Application* _app, int x, int y) : GameObject(name, tag, _app)
{
    //Crate Boing RenderObject
    renderObjects[0].texture = _app->textures->Load("Assets/Images/Game/Boing.png");
    //renderObjects[1].texture = _app->textures->Load("Assets/Images/Game/BallShadow120.png");

    renderObjects[0].scale = 0.3f;
    renderObjects[0].layer = 0;
    renderObjects[0].orderInLayer = 0.5f;
    renderObjects[0].rotationEnabled = false;
	renderObjects[0].section = new SDL_Rect{ 0, 0, 120, 120 };

	// Create PhysBody
	pBody = _app->physics->CreateCircle(x, y, 18, this);
	pBody->body->SetType(b2BodyType::b2_kinematicBody);
	pBody->body->GetFixtureList()->SetRestitution(1.25f);
}

Boing::~Boing()
{
	
}

void Boing::PreUpdate()
{
}

void Boing::Update() 
{
	
}

void Boing::PostUpdate()
{
	GameObject::PostUpdate();
}

void Boing::OnCollision(PhysBody* col)
{
	if (col->gameObject && col->gameObject->CompareTag("Player"))
	{
		if (renderObjects[0].section != nullptr)
		{
			if(renderObjects[0].section->x == 120)
			{
				renderObjects[0].section->x = 0;
			}
			else
			{
				renderObjects[0].section->x = 120;
			}
		}

	}
}