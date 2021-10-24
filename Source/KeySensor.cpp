#include "KeySensor.h"

KeySensor::KeySensor(SDL_Rect rect, int layer, std::string name, std::string tag, Application* _app) : GameObject(name, tag, _app)
{
	
	//CREATE RenderObject
	renderObjects[0].texture = _app->textures->Load("Assets/Images/Game/KeyLocked.png");
	renderObjects[0].layer = 1;
	renderObjects[0].orderInLayer = 0.9f;
	renderObjects[0].rotationEnabled = false;
	renderObjects[0].section = new SDL_Rect{ 0, 0, 10, 10 };

	renderObjects[1].texture = _app->textures->Load("Assets/Images/Game/KeyUnlocked.png");
	renderObjects[1].layer = 1;
	renderObjects[1].orderInLayer = 0.8f;
	renderObjects[1].rotationEnabled = false;
	renderObjects[1].section = new SDL_Rect{ 0, 0, 10, 10 };
	
	pBody = _app->physics->CreateRectangleSensor(iPoint(rect.x, rect.y), rect.w, rect.h);
	pBody->gameObject = this;
}

void KeySensor::OnCollision(PhysBody* col)
{
	
	if (col->gameObject->name == "Ball")
	{
		unlocked = true;
		renderObjects[1].orderInLayer = 0.9f;
		renderObjects[0].orderInLayer = 0.8f;
		printf("UNLOCKED");
	}
}
