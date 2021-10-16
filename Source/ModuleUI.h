#ifndef _MODULE_UI_
#define _MODULE_UI_

#include "Module.h"
#include "Globals.h"


#include "SDL/include/SDL.h"

#include <iostream>
#include <vector>
#include <stack>

#define MAX_UI_ITEMS 32

class itemUI
{
public: 
	int totalDigits;
	int x;
	int y;
	std::vector<int> digitVec;

	void ChangeUI(int num);
};

class ModuleUI : public Module
{
public:

	ModuleUI(Application* app, bool start_enabled = true);

	bool Start(); //	Initialize UI system

	UpdateStatus Update();	//	Update current UIs

	UpdateStatus PostUpdate();	//	Print current UIs on screen

	bool CleanUp();

	uint CreateUI(int num, int x, int y);	// Creates a new UI item on the position given

	SDL_Texture* texture;

	itemUI* uiArray[MAX_UI_ITEMS] = { nullptr };

	SDL_Rect numSection[10];

	uint test;

};

#endif
