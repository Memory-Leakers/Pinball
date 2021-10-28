#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "ScoreSystem.h"

class Coins : public GameObject
{
private:
	ScoreSystem* scoreInstance;
public:

	Coins(std::string name, std::string tag, Application* _app, iPoint pos);

	Animation anim;

	void PostUpdate() override;

	void OnCollision(PhysBody* col) override;

	bool colSwitch = true; //True == ON | False == OFF
};

