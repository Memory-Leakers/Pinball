#include "Sensor.h"

Sensor::Sensor(SDL_Rect rect, int layer, std::string name, std::string tag, Application* _app) : GameObject(name, tag, _app)
{
	pBody = _app->physics->CreateRectangleSensor(iPoint(rect.x, rect.y), rect.w, rect.h);
	pBody->gameObject = this;
}


void Sensor::OnCollision(PhysBody* col)
{
	//printf("SensorCol\n");
}
