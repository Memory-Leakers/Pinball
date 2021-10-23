#include "PolygonBoing.h"
#include <math.h>


PolygonBoing::PolygonBoing(std::string name, std::string tag, Application* _app, int x, int y, int* points, int numberPoints) : GameObject(name, tag, _app)
{
	
	//renderObjects[0].texture = _app->textures->Load("");

	// PhysBody
	pBody = _app->physics->CreateChainObj(x, y, points, numberPoints, true);
	pBody->body->SetType(b2BodyType::b2_kinematicBody);
	pBody->body->GetFixtureList()->SetRestitution(1.25f);
}

PolygonBoing::~PolygonBoing()
{

}

void PolygonBoing::PreUpdate()
{
}

void PolygonBoing::Update()
{

}

void PolygonBoing::PostUpdate()
{
	GameObject::PostUpdate();
}

void PolygonBoing::OnCollision(PhysBody* col)
{
	if (col->gameObject && col->gameObject->CompareTag("Player"))
	{
		if (renderObjects[0].section != nullptr)
		{
			if (renderObjects[0].section->x == 120)
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