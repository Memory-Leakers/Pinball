#include "PhysLayerR.h"

PhysLayerR::PhysLayerR(std::string name, std::string tag, Application* _app) :GameObject(name, tag, _app)
{
	int POINTS[74] = {
		1, 70,
		50, 29,
		63, 18,
		82, 10,
		104, 8,
		150, 8,
		160, 10,
		167, 16,
		173, 23,
		177, 31,
		177, 162,
		174, 170,
		170, 176,
		162, 181,
		152, 187,
		143, 191,
		129, 194,
		115, 196,
		97, 198,
		82, 201,
		72, 207,
		68, 217,
		67, 222,
		55, 217,
		46, 210,
		38, 198,
		41, 108,
		44, 94,
		50, 83,
		62, 71,
		78, 60,
		95, 51,
		89, 51,
		70, 63,
		54, 74,
		39, 89,
		23, 103
	};

	// Create RenderObject
	renderObjects[0].texture = _app->textures->Load("Assets/Images/Game/Layer2R_Part1.png");
	renderObjects[0].layer = 1;
	renderObjects[0].orderInLayer = 1.5f;
	renderObjects[0].rotationEnabled = false;
	renderObjects[0].section = new SDL_Rect{ 0, 0, 182, 226 };

	renderObjects[1].texture = _app->textures->Load("Assets/Images/Game/Layer2R_Part2.png");
	renderObjects[1].layer = 1;
	renderObjects[1].orderInLayer = 0.5f;
	renderObjects[1].rotationEnabled = false;
	renderObjects[1].section = new SDL_Rect{ 0, 0, 182, 226 };

	renderObjects[2].texture = _app->textures->Load("Assets/Images/Game/Layer2R_Part3.png");
	renderObjects[2].layer = 1;
	renderObjects[2].orderInLayer = 1.0f;
	renderObjects[2].rotationEnabled = false;
	renderObjects[2].section = new SDL_Rect{ 0, 0, 182, 226 };
	
	pBody = _app->physics->CreateChainObj(400, 438, POINTS, 74, false);
	pBody->body->SetType(b2BodyType::b2_staticBody);
	pBody->body->GetFixtureList()->SetSensor(true);
	
	//BOING inside
}

void PhysLayerR::Update()
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

void PhysLayerR::setSensor(bool value) 
{
	pBody->body->GetFixtureList()->SetSensor(value);

	if (!value)
	{
		renderObjects[2].layer = 2;		
	}
	else
	{
		renderObjects[2].layer = 1;		
	}
}

void PhysLayerR::swapLowerTexture()
{
	renderObjects[0].orderInLayer = 0.5f;
	renderObjects[1].orderInLayer = 1.5f;
}