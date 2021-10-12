#pragma once

#include "Scene.h"

class SceneMain : public Scene
{
public:

	//Methods
	SceneMain(Application* app) : Scene(app)
	{}
	~SceneMain();

	bool Start();
	bool Update();
	bool PostUpdate();
	bool CleanUp();

public:

	//Variables
	PhysBody* player = nullptr;

};