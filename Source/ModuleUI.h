#ifndef _MODULE_UI_
#define _MODULE_UI_

#include "Module.h"
#include "Globals.h"
#include "Point.h"

#include "SDL/include/SDL.h"

#include <iostream>
#include <vector>
#include <stack>

#define MAX_UI_ITEMS 48

class itemUI
{
public: 
	std::vector<int> digitVec;
	float digitScale;
	int totalDigits;

	bool isDynamic;
	int lifeFrames;
	iPoint speed;

	int x;
	int y;
	int layer;
	float orderInLayer;

	void ChangeUI(int num);
};

class ModuleUI : public Module
{
public:

	ModuleUI(Application* app, bool start_enabled = true);

	bool Start(); //	Initialize UI system

	UpdateStatus Update();	//	Update current UIs

	UpdateStatus PostUpdate();	//	Print current UIs on screen

	// TODO CleanUp Scene
	bool CleanUp();

	uint CreateUI(int num, int x, int y, float scale = 1.0f, int layer = 2, float orderInLayer = 0.1f, bool isDynamic = false, int lifeFrames = 0, iPoint speed = { 0,0 });	// Creates a new UI item on the position given

	void DestroyUI(uint index);			// Deletes an existing UI based on its index

	SDL_Texture* texture;

	itemUI* uiArray[MAX_UI_ITEMS] = { nullptr };

	SDL_Rect numSection[10];

	uint test;

};

#endif

