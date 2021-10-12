#include "SceneMain.h"

SceneMain::~SceneMain()
{
}

bool SceneMain::Start()
{
	player = _app->physics->CreateCircle(240, 240, 100);

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
	return false;
}
