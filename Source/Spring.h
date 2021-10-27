#pragma once
#include "GameObject.h"
class Spring : public GameObject
{
private:
	int defaultYPos;

	uint springKey;

public:
	Spring(iPoint pos, std::string name, std::string tag, Application* _app, uint key, bool isInitSprint = true);

	void Start() override;

	void Update() override;

	void PostUpdate() override;
};

