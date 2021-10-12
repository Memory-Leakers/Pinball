#include "Scene.h"

Scene::Scene(Application* app)
{
	_app = app;
}

Scene::~Scene()
{
}

bool Scene::Start()
{
	return true;
}

bool Scene::PreUpdate()
{
	return true;
}

bool Scene::Update()
{
	return true;
}

bool Scene::PostUpdate()
{
	return true;
}

void Scene::OnCollision(PhysBody* b1, PhysBody* b2)
{
	
}

bool Scene::CleanUp()
{
	return true;
}


