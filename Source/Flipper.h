#pragma once
#include "GameObject.h"
class Flipper : public GameObject
{
public:

	b2RevoluteJoint* joint = nullptr;

	Flipper(std::string name, std::string tag, Application* _app,PhysBody* base);
		
	void Update() override;

	void OnCollision(PhysBody* col) override;
};

