#include "Boss.h"

Boss::Boss(int health, std::string name, std::string tag, Application* _app) : GameObject(name, tag, _app)
{
	// Create PhysBody
	pBody = _app->physics->CreateCircle(424, 355, 38, this);
	pBody->body->SetType(b2BodyType::b2_kinematicBody);
	pBody->body->GetFixtureList()->SetRestitution(0.7f);


	// Create RenderObject
	renderObjects[0].texture = _app->textures->Load("Assets/Images/Game/Boss.png");
	renderObjects[1].texture = _app->textures->Load("Assets/Images/Game/HealthBar.png");

	renderObjects[0].section = new SDL_Rect{ 0, 0, 128, 128 };
	renderObjects[0].scale = 0.65f;

	renderObjects[1].renderRect.x = 300;
	renderObjects[1].renderRect.y = 150;
	renderObjects[1].followPhysBody = false;
	renderObjects[1].layer = 3;

	// Create HealthBar
	this->health = health;

	healthBar = new HealthBar(_app, renderObjects[1].renderRect.x + 5, renderObjects[1].renderRect.y + 6, 195, 20, this->health);
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
	GameObject::PostUpdate();

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
