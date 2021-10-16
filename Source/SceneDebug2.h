#pragma once
#include "Scene.h"
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

	int currentScore = 0;

};

