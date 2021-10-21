#pragma once
#include "GameObject.h"
class Flipper : public GameObject
{
public:

	Flipper(std::string name, std::string tag, Application* _app);
		

	void OnCollision(PhysBody* col) override;
};

