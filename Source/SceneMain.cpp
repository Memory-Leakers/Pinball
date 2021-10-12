#include "SceneMain.h"

SceneMain::~SceneMain()
{
}

bool SceneMain::Start()
{
	player = _app->physics->CreateCircle(240, 240, 100);

	player->listenerModule = _app->scene;

	ground = _app->physics->CreateRectangle(0, 700, 2000, 10);

	ground->listenerModule = _app->scene;

	ground->body->SetType(b2BodyType::b2_staticBody);

	return false;
}

bool SceneMain::Update()
{
	return false;
}

bool SceneMain::PostUpdate()
{
	return false;
}

bool SceneMain::CleanUp()
{
	delete player;
	delete ground;
	return false;
}

void SceneMain::OnCollision(PhysBody* b1, PhysBody* b2)
{
	LOG("CollisionIn");
}
