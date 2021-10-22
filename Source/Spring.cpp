#include "Spring.h"

Spring::Spring(iPoint pos, std::string name, std::string tag, Application* _app) : GameObject(name, tag, _app)
{
	// Create RenderObject
	renderObjects[0].texture = _app->textures->Load("Assets/Images/Game/Spring.png");
	renderObjects[0].renderRect.x = pos.x;
	renderObjects[0].renderRect.y = pos.y;
	renderObjects[0].scale = 0.65f;
	renderObjects[0].layer = 1;
	

	defaultYPos = pos.y;
}

void Spring::Start()
{
}

void Spring::Update()
{
	if (_app->input->GetKey(SDL_SCANCODE_SPACE) == KEY_REPEAT)
	{
		renderObjects[0].renderRect.y += renderObjects[0].renderRect.y >= defaultYPos+30 ? 0 : 1;
	}
	if (_app->input->GetKey(SDL_SCANCODE_SPACE) == KEY_UP)
	{
		renderObjects[0].renderRect.y = defaultYPos;
	}
}

void Spring::PostUpdate()
{
	_app->renderer->AddTextureRenderQueue(renderObjects[0]);
}
