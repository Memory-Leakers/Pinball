#include "Flipper.h"
#include "SceneMain.h"

Flipper::Flipper(std::string name, std::string tag, Application* _app,PhysBody* base, bool isRight,uint key) : GameObject(name, tag, _app)
{
	this->key = key;
	//CreatePhysBodys
	if (isRight) {

		this->isRight = 1;

		// Create RenderObject 
		renderObjects[0].texture = _app->textures->Load("Assets/Images/Game/Flipper.png");
		renderObjects[0].scale = 0.75f;
		renderObjects[0].layer = 1;
		renderObjects[0].orderInLayer = 1.0f;
		renderObjects[0].flip = SDL_FLIP_HORIZONTAL;

		pBody = _app->physics->CreateRectangle(355, 775, 96, 18);
		pBody->gameObject = this;

		b2RevoluteJointDef revoluteDef;
		revoluteDef.bodyA = pBody->body;
		revoluteDef.bodyB = base->body;
		revoluteDef.collideConnected = false;

		revoluteDef.localAnchorA.Set(PIXELS_TO_METER(48), PIXELS_TO_METER(0));
		//revoluteDef.Initialize(revoluteDef.bodyA, revoluteDef.bodyB, b2Vec2(PIXELS_TO_METER(486), PIXELS_TO_METER(509)));
		revoluteDef.localAnchorB.Set(PIXELS_TO_METER(405), PIXELS_TO_METER(774));
		revoluteDef.referenceAngle = 0 * DEGTORAD;
		revoluteDef.lowerAngle = -30 * DEGTORAD;
		revoluteDef.upperAngle = 25 * DEGTORAD;
		revoluteDef.enableLimit = true;
		//revoluteDef.motorSpeed = 5000.0f;
		revoluteDef.maxMotorTorque = 0;
		revoluteDef.enableMotor = true;

		joint = (b2RevoluteJoint*)_app->physics->world->CreateJoint(&revoluteDef);
	}
	else
	{
		this->isRight = -1;

		renderObjects[1].texture = _app->textures->Load("Assets/Images/Game/Flipper.png");
		renderObjects[1].scale = 0.75f;
		renderObjects[1].layer = 1;
		renderObjects[1].orderInLayer = 1.0f;
		renderObjects[1].flip = SDL_FLIP_NONE;

		pBody = _app->physics->CreateRectangle(200, 575, 96, 18);
		pBody->gameObject = this;

		b2RevoluteJointDef revoluteDef2;
		revoluteDef2.bodyA = pBody->body;
		revoluteDef2.bodyB = base->body;
		revoluteDef2.collideConnected = false;

		revoluteDef2.localAnchorA.Set(PIXELS_TO_METER(-48), PIXELS_TO_METER(0));
		//revoluteDef.Initialize(revoluteDef.bodyA, revoluteDef.bodyB, b2Vec2(PIXELS_TO_METER(486), PIXELS_TO_METER(509)));
		revoluteDef2.localAnchorB.Set(PIXELS_TO_METER(185), PIXELS_TO_METER(774));
		revoluteDef2.referenceAngle = 0 * DEGTORAD;
		revoluteDef2.lowerAngle = -25 * DEGTORAD;
		revoluteDef2.upperAngle = 30 * DEGTORAD;
		revoluteDef2.enableLimit = true;
		//revoluteDef.motorSpeed = 5000.0f;
		revoluteDef2.maxMotorTorque = 0;
		revoluteDef2.enableMotor = true;

		joint2 = (b2RevoluteJoint*)_app->physics->world->CreateJoint(&revoluteDef2);
	}
}

void Flipper::Update()
{
	if (_app->input->GetKey(key) == KEY_REPEAT)
	{
		pBody->body->SetAngularVelocity(600 * DEGTORAD * isRight);
	}
	if (_app->input->GetKey(key) == KEY_UP)
	{
		pBody->body->SetAngularVelocity(-600 * DEGTORAD* isRight);
	}
}

void Flipper::OnCollision(PhysBody* col)
{
	//printf("Col Flliper");
}
