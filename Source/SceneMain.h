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
	void OnCollision(PhysBody* b1, PhysBody* b2) override;

public:

	//Variables
	PhysBody* player = nullptr;

	PhysBody* ground = nullptr;

};