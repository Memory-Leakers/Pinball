#include "SceneMain.h"

SceneMain::~SceneMain()
{
}

bool SceneMain::Start()
{
	//Provisional
	player = _app->physics->CreateCircle(200, 0, 10);

	player->body->SetBullet(true);
	
	/*
	ground = _app->physics->CreateRectangle(0, 700, 2000, 10);

	ground->body->SetType(b2BodyType::b2_staticBody);*/

	flipper = _app->physics->CreateRectangle(200, 500, 60, 20);

	flipperBase = _app->physics->CreateRectangle(260, 500, 100, 30);

	flipper->body->SetType(b2BodyType::b2_dynamicBody);

	flipperBase->body->SetType(b2BodyType::b2_staticBody);

	b2RevoluteJointDef revoluteDef;

	revoluteDef.Initialize(flipperBase->body, flipper->body, b2Vec2(PIXELS_TO_METER(260), PIXELS_TO_METER(500)));
	revoluteDef.referenceAngle = 0 * DEGTORAD;
	revoluteDef.lowerAngle = -30 * DEGTORAD;
	revoluteDef.upperAngle = 30 * DEGTORAD;
	revoluteDef.enableLimit = true;
	//revoluteDef.motorSpeed = 5000.0f;
	revoluteDef.maxMotorTorque = 0;
	revoluteDef.enableMotor = true;

	joint = (b2RevoluteJoint*)_app->physics->world->CreateJoint(&revoluteDef);


	return false;
}

bool SceneMain::Update()
{
	if (_app->input->GetKey(SDL_SCANCODE_SPACE) == KEY_REPEAT)
	{
		//flipper->body->ApplyForceToCenter(b2Vec2(0, -0.1f), 1);
		joint->SetMaxMotorTorque(-50);
		joint->SetLimits(-30 * DEGTORAD, 30 * DEGTORAD);
	}

	if (_app->input->GetKey(SDL_SCANCODE_SPACE) == KEY_UP)
	{
		joint->SetLimits(-30 * DEGTORAD, -30 * DEGTORAD);
	}
	return false;
}

bool SceneMain::PostUpdate()
{
	return false;
}

bool SceneMain::CleanUp()
{
	delete player;
	delete ground;
	delete flipper;
	delete flipperBase;
	_app->physics->world->DestroyJoint(joint);
	return false;
}
