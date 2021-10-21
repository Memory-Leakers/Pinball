#include "Flipper.h"

Flipper::Flipper(std::string name, std::string tag, Application* _app) : GameObject(name, tag, _app)
{

	// Create RenderObject 
	renderObjects[0].texture = _app->textures->Load("Assets/Images/Game/FlipperR128.png");
	renderObjects[0].scale = 0.75f;
	renderObjects[0].layer = 1;
	renderObjects[0].orderInLayer = 1.0f;

	// Create physBody
	pBody = _app->physics->CreateRectangle(400, 500, 96, 18);
	pBody->gameObject = this;

}

void Flipper::OnCollision(PhysBody* col)
{
	printf("Col Flliper");
}
