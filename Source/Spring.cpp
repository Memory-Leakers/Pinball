#include "Spring.h"

Spring::Spring(iPoint pos, std::string name, std::string tag, Application* _app, uint key, bool isInitSprint) : GameObject(name, tag, _app)
{
	// Create RenderObject
	if(isInitSprint)
	{
		renderObjects[0].texture = _app->textures->Load("Assets/Images/Game/Spring.png");
	}
	else
	{
		renderObjects[0].texture = _app->textures->Load("Assets/Images/Game/Spring2.png");
	}	

	renderObjects[0].renderRect.x = pos.x;
	renderObjects[0].renderRect.y = pos.y;
	renderObjects[0].scale = 0.65f;
	renderObjects[0].layer = 1;
	
	defaultYPos = pos.y;

	springKey = key;
}

void Spring::Start()
{
}

void Spring::Update()
{
	if (_app->input->GetKey(springKey) == KEY_REPEAT)
	{
		renderObjects[0].renderRect.y += renderObjects[0].renderRect.y >= defaultYPos + 40 ? 0 : 1;
	}
	if (_app->input->GetKey(springKey) == KEY_UP)
	{
		renderObjects[0].renderRect.y = defaultYPos;
	}
}

void Spring::PostUpdate()
{
	_app->renderer->AddTextureRenderQueue(renderObjects[0]);
}
