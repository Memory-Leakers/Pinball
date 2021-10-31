#include "ModuleScene.h"
#include <time.h>
#include "SceneGame.h"

ModuleScene::ModuleScene(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleScene::~ModuleScene()
{
}

bool ModuleScene::Start()
{
	scenes[0] = new SceneGame(App);

	currentScene = scenes[index];

	bool ret = true;

	if (currentScene == nullptr)
	{
		return ret;
	}

	currentScene->Start();

	return ret;
}

UpdateStatus ModuleScene::PreUpdate()
{
	if (currentScene == nullptr)
	{
		return UpdateStatus::UPDATE_CONTINUE;
	}

	currentScene->PreUpdate();

	return UpdateStatus::UPDATE_CONTINUE;
}

UpdateStatus ModuleScene::Update()
{
	if (App->isDebug)
	{
		if (App->input->GetKey(SDL_SCANCODE_F5) == KEY_DOWN)
		{
			ChangeCurrentScene(0, 0);
		}
	}

	if (currentScene == nullptr)
	{
		return UpdateStatus::UPDATE_CONTINUE;
	}

	currentScene->Update();

	return UpdateStatus::UPDATE_CONTINUE;
}

UpdateStatus ModuleScene::PostUpdate()
{
	if (currentScene == nullptr)
	{
		return UpdateStatus::UPDATE_CONTINUE;
	}

	currentScene->PostUpdate();

	return UpdateStatus::UPDATE_CONTINUE;
}

//CleanUp current scene, change current scene (index), Start current Scene
bool ModuleScene::ChangeCurrentScene(uint index, int frames)
{
	this->index = index;
	currentScene->CleanUp();
	currentScene = scenes[index];
	currentScene->Start();

	return true;
}



bool ModuleScene::CleanUp()
{
	for (int i = 0; i < SCENES_NUM; i++)
	{
		if (scenes[i] != nullptr)
		{
			scenes[i]->CleanUp();	//CleanUp all scenes (in case the Application is shut down)
			delete scenes[i];
			scenes[i] = nullptr;
		}
	}

	return true;
}
