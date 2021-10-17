#pragma once
#include "Scene.h"
#include "ModulePhysics.h"


class SceneDebug3 :
    public Scene
{
public:
	SceneDebug3(Application* app);

	bool Start();
	bool Update();
	bool PostUpdate();
	bool CleanUp() override;
};

