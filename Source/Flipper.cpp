#include "Flipper.h"
#include "SceneMain.h"

Flipper::Flipper(std::string name, std::string tag, Application* _app,PhysBody* base, bool isRight,uint key, uint key2) : GameObject(name, tag, _app)
{
	this->key = key;
	this->key2 = key2;

	SDL_RendererFlip flip;
	SDL_Rect rect;
	iPoint anchorA, anchorB, angle;

	// Init valor
	if(isRight)
	{
		this->isRight = 1;
		flip = SDL_FLIP_HORIZONTAL;
		rect = { 355,775,96,18 };
		anchorA = { 48,0 };
		anchorB = { 405,774 };
		angle = { -30,25 };
	}
	else
	{
		this->isRight = -1;
		flip = SDL_FLIP_NONE;
		rect = { 235,775,96,18 };
		anchorA = { -48,0 };
		anchorB = { 185,774 };
		angle = { -25,30 };
	}

	// RenderObject
	renderObjects[0].texture = _app->textures->Load("Assets/Images/Game/Flipper.png");
	renderObjects[0].scale = 0.75f;
	renderObjects[0].layer = 1;
	renderObjects[0].orderInLayer = 1.0f;
	renderObjects[0].flip = flip;

	// PhysBody
	pBody = _app->physics->CreateRectangle(rect.x, rect.y, rect.w, rect.h);
	pBody->gameObject = this;

	// Joint
	b2RevoluteJointDef revoluteDef;
	revoluteDef.bodyA = pBody->body;
	revoluteDef.bodyB = base->body;
	revoluteDef.collideConnected = false;

	//revoluteDef.Initialize(revoluteDef.bodyA, revoluteDef.bodyB, b2Vec2(PIXELS_TO_METER(486), PIXELS_TO_METER(509)));
	revoluteDef.localAnchorA.Set(PIXELS_TO_METER(anchorA.x), PIXELS_TO_METER(anchorA.y));
	revoluteDef.localAnchorB.Set(PIXELS_TO_METER(anchorB.x), PIXELS_TO_METER(anchorB.y));
	revoluteDef.referenceAngle = 0 * DEGTORAD;
	revoluteDef.lowerAngle = angle.x * DEGTORAD;
	revoluteDef.upperAngle = angle.y * DEGTORAD;
	revoluteDef.enableLimit = true;

	joint2 = (b2RevoluteJoint*)_app->physics->world->CreateJoint(&revoluteDef);
}

void Flipper::Update()
{
	if (_app->input->GetKey(key) == KEY_REPEAT || _app->input->GetKey(key2) == KEY_REPEAT)
	{
		pBody->body->SetAngularVelocity(1000 * DEGTORAD * isRight);
	}
	if (_app->input->GetKey(key) == KEY_UP || _app->input->GetKey(key2) == KEY_UP)
	{
		pBody->body->SetAngularVelocity(-1000 * DEGTORAD* isRight);
	}
}

void Flipper::OnCollision(PhysBody* col)
{
	//printf("Col Flliper");
}
