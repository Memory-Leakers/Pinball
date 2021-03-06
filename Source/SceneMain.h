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
	bool CleanUp() override;

public:

	//Variables
	PhysBody* player = nullptr;

	PhysBody* ground = nullptr;

	PhysBody* flipper = nullptr;
	PhysBody* flipperBase = nullptr;

	b2RevoluteJoint* joint = nullptr;

};