#pragma once

#include "p2List.h"
#include "Globals.h"
#include "Module.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"
#include "ModulePhysics.h"
#include "ModuleScene.h"
#include "ModuleUI.h"

#include "Timer.h"

#define FPS 75

class Application
{
public:
	ModuleRender* renderer;
	ModuleWindow* window;
	ModuleTextures* textures;
	ModuleInput* input;
	ModuleAudio* audio;
	ModulePlayer* player;
	ModulePhysics* physics;
	ModuleScene* scene;
	ModuleUI* ui;

	Timer globalTime;

	bool isDebug = true;

	bool gameOver = false;

private:

	p2List<Module*> list_modules;

public:

	Application();
	~Application();

	bool Init();
	UpdateStatus Update();
	bool CleanUp();

	bool FullScreenDesktop = true;

private:

	void AddModule(Module* mod);
};