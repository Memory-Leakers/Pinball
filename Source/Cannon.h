#pragma once
#include "GameObject.h"
class Cannon : public GameObject
{
public:
	Cannon(std::string name, std::string tag, Application* _app, iPoint pos);

	void Update() override;

	void PostUpdate() override;

	void OnCollision(PhysBody* col) override;

	int renderState = 0;

	float holeSize = 0.0f;

	float cannonSize = 0.25f;

	SDL_Rect holeSection = { 256,0,256,256 };
};

