#pragma once
#include "GameObject.h"
class Boing;
class PhysLayerL : public GameObject
{
public:
	PhysLayerL(std::string name, std::string tag, Application* _app);

	int timeCount = 0;

	bool showBG = false;

	void Update() override;

	void setSensor(bool value);

	Boing* boing;
};

