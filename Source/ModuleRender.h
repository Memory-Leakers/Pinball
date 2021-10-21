#pragma once
#include "Module.h"
#include "Globals.h"
#include "Point.h"
#include <vector>

using namespace std;

struct RenderObject
{
	SDL_Texture* texture;
	SDL_Rect* section;
	SDL_Rect renderRect;
	SDL_RendererFlip flip;
	float rotation;
	float orderInLayer;
};

class ModuleRender : public Module
{
public:
	ModuleRender(Application* app, bool start_enabled = true);
	~ModuleRender();

	bool Init();
	UpdateStatus PreUpdate();
	UpdateStatus Update();
	UpdateStatus PostUpdate();
	bool CleanUp();

	void AddTextureRenderQueue(SDL_Texture* texture, iPoint pos, SDL_Rect* section = nullptr, int layer = 0, float orderInlayer = 0.0f, bool isFlipH = false, float rotation = 0, float scale = SCREEN_SIZE, float speed = 1.0f);// Speed = 1.0f = Fullscreen camera
	void SortRenderObjects(vector<RenderObject>& obj);

	#pragma region OBSOLETE
	bool Blit(SDL_Texture* texture, int x, int y, float scale = 1, SDL_Rect* section = NULL, float speed = 1.0f, double angle = 0,SDL_RendererFlip flip=SDL_FLIP_NONE,int pivot_x = INT_MAX, int pivot_y = INT_MAX);
	bool DrawQuad(const SDL_Rect& rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255, bool filled = true, bool use_camera = true);
	bool DrawLine(int x1, int y1, int x2, int y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255, bool use_camera = true);
	bool DrawCircle(int x1, int y1, int redius, Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255, bool use_camera = true);
	void CameraMove(iPoint pos);
	#pragma endregion

public:
	SDL_Renderer* renderer;
	SDL_Rect camera;

private:
	float defaultSpeed = 1;

	vector<vector<RenderObject>> layers;

};