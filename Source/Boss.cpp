#include "Boss.h"

Boss::Boss(int health, std::string name, std::string tag, Application* _app) : GameObject(name, tag, _app)
{
	this->health = health;
	pBody = new PhysBody(this);
}

void Boss::CleanUp()
{
	if (healthBar != nullptr)
	{
		delete healthBar;
		healthBar = nullptr;
	}
}
