#include "Boss.h"

Boss::Boss(int health, std::string name, std::string tag, Application* _app) : GameObject(name, tag, _app)
{
	this->health = health;
	pBody = _app->physics->CreateCircle(424, 355, 38, this);
	pBody->body->SetType(b2BodyType::b2_kinematicBody);
	pBody->body->GetFixtureList()->SetRestitution(0.7f);

	int x, y;

	pBody->GetPosition(x, y);

	healthBar = new HealthBar(_app, x - 50, y - 60, 150, 20, this->health);
}

Boss::~Boss()
{
	if (healthBar != nullptr)
	{
		delete healthBar;
		healthBar = nullptr;
	}
}

void Boss::Update()
{
	healthBar->currentHealth = health;
}

void Boss::PostUpdate()
{
	healthBar->PostUpdate();
}

void Boss::CleanUp()
{
	if (healthBar != nullptr)
	{
		delete healthBar;
		healthBar = nullptr;
	}
}
