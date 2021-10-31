#include "PhysLayerL.h"
#include "Boing.h"
#include "Coins.h"

PhysLayerL::PhysLayerL(std::string name, std::string tag, Application* _app) :GameObject(name, tag, _app)
{
	int POINTS[66] = {
		100, 3,
		69, 3,
		50, 5,
		37, 10,
		20, 19,
		11, 29,
		6, 39,
		4, 55,
		4, 210,
		6, 218,
		10, 224,
		15, 229,
		24, 233,
		36, 233,
		56, 233,
		63, 231,
		66, 226,
		67, 222,
		96, 222,
		96, 193,
		102, 193,
		102, 221,
		104, 224,
		126, 224,
		147, 82,
		140, 67,
		132, 57,
		123, 49,
		107, 46,
		82, 46,
		67, 47,
		57, 51,
		50, 56
	};

	// Create RenderObject
	renderObjects[0].texture = _app->textures->Load("Assets/Images/Game/Layer2L_Part1.png");
	renderObjects[0].layer = 1;
	renderObjects[0].orderInLayer = 1.5f;
	renderObjects[0].rotationEnabled = false;
	renderObjects[0].section = new SDL_Rect{ 0, 0, 152, 236 };

	renderObjects[1].texture = _app->textures->Load("Assets/Images/Game/Layer2L_Part2.png");
	renderObjects[1].layer = 1;
	renderObjects[1].orderInLayer = 0.5f;
	renderObjects[1].rotationEnabled = false;
	renderObjects[1].section = new SDL_Rect{ 0, 0, 152, 236 };
	
	pBody = _app->physics->CreateChainObj(12, 438, POINTS, 66, false);
	pBody->body->SetType(b2BodyType::b2_staticBody);
	pBody->body->GetFixtureList()->SetSensor(true);

	//BOING inside
	boing = new Boing("Boing", "Boing", _app, 44, 640, 25);
	boing->layer = 2;
}

void PhysLayerL::Update()
{
	if (_app->input->GetKey(SDL_SCANCODE_H) == KEY_DOWN)
	{
		showBG = !showBG;
		if (timeCount == 0)
		{
			timeCount = 255;
		}		
	}

	if (timeCount > 0)
	{
		timeCount = timeCount - 10 < 0 ? 0 : timeCount - 10;

		if (showBG)
		{
			SDL_SetTextureAlphaMod(renderObjects[0].texture, timeCount);
		}
		else
		{
			SDL_SetTextureAlphaMod(renderObjects[0].texture, 255 - timeCount);
		}
	}
}

void PhysLayerL::setSensor(bool value) 
{
	pBody->body->GetFixtureList()->SetSensor(value);
	boing->pBody->body->GetFixtureList()->SetSensor(value);

	if (!value)
	{
		if (!showBG)
		{
			showBG = true;
			timeCount = 255;
			//renderObjects[1].layer = 2;
			boing->setLayer(2);
		}
	}
	else 
	{
		if (showBG)
		{
			showBG = false;
			timeCount = 255;
			//renderObjects[1].layer = 1;
			boing->setLayer(1);
		}
	}
}
