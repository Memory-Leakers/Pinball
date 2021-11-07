#pragma once
#include "Scene.h"
class SceneMainMenu : public Scene
{
public:
	SceneMainMenu(Application* app);

	bool Start() override;

	bool Update() override;
	bool PostUpdate() override;

	bool CleanUp() override;
private:
	iPoint arrowPos;

	void SelectDifficulty();
};

