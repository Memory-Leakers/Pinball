#include "RectObsatcle.h"

RectObstacle::RectObstacle(std::string name, std::string tag, Application* _app, int x, int y, float rotation) :GameObject(name, tag, _app)
{
	//Crate RectObstacle RenderObject
	renderObjects[0].texture = _app->textures->Load("Assets/Images/Game/Rect.png");
	renderObjects[0].scale = 0.25f;
	renderObjects[0].layer = 0;
	renderObjects[0].orderInLayer = 0.5f;
	renderObjects[0].followPhysBody = true;
	renderObjects[0].rotationEnabled = true;

	// Create PhysBody
	pBody = _app->physics->CreateRectangle(x, y, 32, 8);
	pBody->body->SetType(b2BodyType::b2_kinematicBody);
	pBody->body->SetTransform(pBody->body->GetPosition(), DEGTORAD * rotation);
}