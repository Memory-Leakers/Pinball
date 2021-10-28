#pragma once
#include "GameObject.h"
class RectObstacle : public GameObject
{
public:
	RectObstacle(std::string name, std::string tag, Application* _app, int x, int y, float rotation = 0);

	void OpenSavePoint();

	void CloseSavePoint();

private:

	b2Vec2 defaultPos = { -100,-100 };

	float defaultAngle = 0.0f;
};

