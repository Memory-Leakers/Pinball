#pragma once
#include "GameObject.h"
class Cannon : public GameObject
{
public:
	Cannon(std::string name, std::string tag, Application* _app, iPoint pos);

	void Update() override;

	void PostUpdate() override;

	void OnCollision(PhysBody* col) override;

	void ShowCannon();

	int renderState = 0;

	float holeSize = 0.0f;

	float cannonSize = 0.25f;

	float cannonForce = 200.0f;

	bool isPlayerIn = false;

	SDL_Rect holeSection = { 256,0,256,256 };

	void Reset();
};

