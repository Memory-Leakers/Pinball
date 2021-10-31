#pragma once
#include "GameObject.h"
#define COINNUM 15

class Boing;
class Coins;

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

