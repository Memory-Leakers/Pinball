#include "Boss.h"

Boss::Boss(int health, SDL_Texture* texture, std::string name, std::string tag, Application* _app) : GameObject(texture, name, tag, _app)
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
