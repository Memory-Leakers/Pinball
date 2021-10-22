#pragma once
#include "GameObject.h"
class Spring : public GameObject
{
private:
	int defaultYPos;

public:
	Spring(iPoint pos, std::string name, std::string tag, Application* _app);

	void Start() override;

	void Update() override;

	void PostUpdate() override;
};

