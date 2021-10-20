#pragma once
#include "Scene.h"
#include "Boss.h"
class SceneDebug2 :
    public Scene
{
public:
    SceneDebug2(Application* app);

	bool Start();
	bool Update();
	bool PostUpdate();
	bool CleanUp() override;

	uint uis[3];

	HealthBar* test = new HealthBar(_app);

	int currentScore = 0;

};

