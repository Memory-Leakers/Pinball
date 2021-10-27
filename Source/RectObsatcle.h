#pragma once
#include "GameObject.h"
class RectObstacle : public GameObject
{
public:
	RectObstacle(std::string name, std::string tag, Application* _app, int x, int y, float rotation = 0);
};

