#include "PhysLayerL.h"

PhysLayerL::PhysLayerL(std::string name, std::string tag, Application* _app) :GameObject(name, tag, _app)
{
	// Create RenderObject
	renderObjects[0].texture = _app->textures->Load("Assets/Images/Game/Layer2L_Part1.png");
	renderObjects[0].layer = 1;
	renderObjects[0].orderInLayer = 1.5f;
	renderObjects[0].rotationEnabled = false;

	renderObjects[1].texture = _app->textures->Load("Assets/Images/Game/Layer2L_Part2.png");
	renderObjects[1].layer = 1;
	renderObjects[1].orderInLayer = 0.5f;
	renderObjects[1].rotationEnabled = false;
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
