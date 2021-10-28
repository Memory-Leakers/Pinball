#pragma once

#include "GameObject.h"

class CannonSensor : public GameObject
{
public:

	CannonSensor(SDL_Rect rect, int layer, std::string name, std::string tag, Application* _app);

	void OnCollision(PhysBody* col) override;

	void Reset();

	bool CannonSensor1 = false;
	bool CannonSensor2 = false;
	bool CannonSensor3 = false;

	void PostUpdate() override;

	int offsetx_collider_sensor = 2;
};

