#include "PolygonBoing.h"
#include <math.h>


PolygonBoing::PolygonBoing(std::string name, std::string tag, Application* _app, int x, int y, int* points, int numberPoints,int Id,bool isRight) : GameObject(name, tag, _app)
{
	float scale;
	SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;
	
	if (Id == 1)
	{
		scale = 0.20f;
		Offsetx = 135;
		Offsety = 637;
		
		if (isRight)
		{
			flip = SDL_FLIP_NONE;
			Offsetx = 398;
			Offsety = 642;
			AngularOffset = 0;
		}
	}

	renderObjects[0].texture = _app->textures->Load("Assets/Images/Game/Triangle_Boing.png");
	renderObjects[0].scale = scale;
	renderObjects[0].layer = 0;
	renderObjects[0].orderInLayer = 0.5f;
	renderObjects[0].section = new SDL_Rect{ 0,0,240,462 };
	renderObjects[0].flip = flip;

	

	// PhysBody
	pBody = _app->physics->CreateChainObj(x, y, points, numberPoints, true);
	pBody->body->SetType(b2BodyType::b2_kinematicBody);
	pBody->body->GetFixtureList()->SetRestitution(1.25f);
	pBody->gameObject = this;

}

PolygonBoing::PolygonBoing(std::string name, std::string tag, Application* _app, int x, int y, int* points, int numberPoints,float rotation,iPoint offset,float Scale) : GameObject(name, tag, _app)
{
	SDL_RendererFlip flip = SDL_FLIP_NONE;

	Offsetx = offset.x;
	Offsety = offset.y;

	renderObjects[0].texture = _app->textures->Load("Assets/Images/Game/Boing.png");
	renderObjects[0].section = new SDL_Rect{ 60,0,60,120 };
	renderObjects[0].layer = 0;
	renderObjects[0].orderInLayer = 0.5f;
	renderObjects[0].scale = Scale;
	renderObjects[0].rotationEnabled = false;
	renderObjects[0].rotation = rotation;
	renderObjects[0].followPhysBody = true;

	// PhysBody
	pBody = _app->physics->CreateChainObj(x, y, points, numberPoints, true);
	pBody->body->SetType(b2BodyType::b2_kinematicBody);
	pBody->body->GetFixtureList()->SetRestitution(1.25f);
	pBody->gameObject = this;


}

PolygonBoing::~PolygonBoing()
{

}

void PolygonBoing::PreUpdate()
{
}

void PolygonBoing::Update()
{

	if(count>0)
	{
		count--;
	}
	if(count == 0)
	{
		if (pBody->gameObject->CompareTag("TriangularBoing"))
		{
			renderObjects[0].section->y = 0;
		}
		else
		{
			renderObjects[0].section->x = 60;
		}
	}
}

void PolygonBoing::PostUpdate()
{
	for (int i = 0; i < MAX_GAMEOBJECT_TEXTURES; i++)
	{
		if (renderObjects[i].texture != nullptr)
		{
			if (pBody != nullptr && renderObjects[i].followPhysBody)
			{
				renderObjects[i].renderRect.x = GetDrawPos().x + Offsetx;
				renderObjects[i].renderRect.y = GetDrawPos().y + Offsety;
			}

			_app->renderer->AddTextureRenderQueue(renderObjects[i]);
		}
	}
	
}

void PolygonBoing::OnCollision(PhysBody* col)
{
	if (col->gameObject && col->gameObject->CompareTag("Player"))
	{
		count = 0.1f * FPS;

		if (renderObjects[0].section != nullptr)
		{
			if(pBody->gameObject->CompareTag("TriangularBoing"))
			{
				renderObjects[0].section->y = 462;
			}
			else
			{
				renderObjects[0].section->x = 180;
			}
		}

	}
}

void PolygonBoing::setSensor(bool value) {
	pBody->body->GetFixtureList()->SetSensor(value);
}