#include "Application.h"
#include "Optick/include/optick.h"

Application::Application()
{
	renderer = new ModuleRender(this);
	window = new ModuleWindow(this);
	textures = new ModuleTextures(this);
	input = new ModuleInput(this);
	audio = new ModuleAudio(this, true);
	player = new ModulePlayer(this);
	physics = new ModulePhysics(this);
	scene = new ModuleScene(this);
	ui = new ModuleUI(this);

	// The order of calls is very important!
	// Modules will Init() Start() and Update in this order
	// They will CleanUp() in reverse order

	// Main Modules
	AddModule(window);
	AddModule(physics);

	// Scenes
	AddModule(scene);
	
	AddModule(textures);
	AddModule(input);
	AddModule(audio);
	AddModule(ui);
	
	// Player
	AddModule(player);
	//Render
	AddModule(renderer);
}

Application::~Application()
{
	p2List_item<Module*>* item = list_modules.getLast();

	while(item != NULL)
	{
		delete item->data;
		item = item->prev;
	}
}

bool Application::Init()
{
	bool ret = true;

	// Call Init() in all modules
	p2List_item<Module*>* item = list_modules.getFirst();

	while(item != NULL && ret == true)
	{
		ret = item->data->Init();
		item = item->next;
	}

	// After all Init calls we call Start() in all modules
	LOG("Application Start --------------");
	item = list_modules.getFirst();

	while(item != NULL && ret == true)
	{
		if(item->data->IsEnabled())
			ret = item->data->Start();
		item = item->next;
	}
	
	return ret;
}

// Call PreUpdate, Update and PostUpdate on all modules
UpdateStatus Application::Update()
{
	OPTICK_EVENT();
	UpdateStatus ret = UPDATE_CONTINUE;
	globalTime.Update();
	p2List_item<Module*>* item = list_modules.getFirst();


	while (item != NULL && ret == UPDATE_CONTINUE)
	{
		if (item->data->IsEnabled())
			ret = item->data->PreUpdate();
		item = item->next;
	}

	item = list_modules.getFirst();

	while (item != NULL && ret == UPDATE_CONTINUE)
	{
		if (item->data->IsEnabled())
			ret = item->data->Update();
		item = item->next;
	}

	item = list_modules.getFirst();

	while (item != NULL && ret == UPDATE_CONTINUE)
	{
		if (item->data->IsEnabled())
			ret = item->data->PostUpdate();
		item = item->next;
	}

	deltaTime = globalTime.getDeltaTime();

	if (deltaTime <= FRAME_TIME)
	{
		sleepTime = (FRAME_TIME - deltaTime)* 1000;
		Sleep(sleepTime);
	}

	globalTime.Reset();

	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;
	p2List_item<Module*>* item = list_modules.getLast();

	while(item != NULL && ret == true)
	{
		ret = item->data->CleanUp();
		item = item->prev;
	}
	return ret;
}

void Application::AddModule(Module* mod)
{
	list_modules.add(mod);
}