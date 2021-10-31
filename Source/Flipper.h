#pragma once
#include "GameObject.h"
class Flipper : public GameObject
{
public:

	b2RevoluteJoint* joint = nullptr;
	b2RevoluteJoint* joint2 = nullptr;
	int isRight = 1;
	uint key;
	uint key2;
		
	void Update() override;

	Flipper(std::string name, std::string tag, Application* _app, PhysBody* base, bool isRight, uint key, uint key2);

	void OnCollision(PhysBody* col) override;
};

