#include "Flipper.h"
#include "SceneMain.h"

Flipper::Flipper(std::string name, std::string tag, Application* _app,PhysBody* base) : GameObject(name, tag, _app)
{

	// Create RenderObject 
	renderObjects[0].texture = _app->textures->Load("Assets/Images/Game/Flipper.png");
	renderObjects[0].scale = 0.75f;
	renderObjects[0].layer = 1;
	renderObjects[0].orderInLayer = 1.0f;
	renderObjects[0].flip = SDL_FLIP_HORIZONTAL;

	

	

	// Create physBody
	pBody = _app->physics->CreateRectangle(355, 775, 96, 18);
	pBody->gameObject = this;
	
	

	b2RevoluteJointDef revoluteDef;
	revoluteDef.bodyA = pBody->body;
	revoluteDef.bodyB = base->body;
	revoluteDef.collideConnected = false;
	
	revoluteDef.localAnchorA.Set(PIXELS_TO_METER(48), PIXELS_TO_METER(0));
	//revoluteDef.Initialize(revoluteDef.bodyA, revoluteDef.bodyB, b2Vec2(PIXELS_TO_METER(486), PIXELS_TO_METER(509)));
	revoluteDef.localAnchorB.Set(PIXELS_TO_METER(401), PIXELS_TO_METER(776));
	revoluteDef.referenceAngle = 0 * DEGTORAD;
	revoluteDef.lowerAngle = -30* DEGTORAD;
	revoluteDef.upperAngle = 25 * DEGTORAD;
	revoluteDef.enableLimit = true;
	//revoluteDef.motorSpeed = 5000.0f;
	revoluteDef.maxMotorTorque = 0;
	revoluteDef.enableMotor = true;

	joint = (b2RevoluteJoint*)_app->physics->world->CreateJoint(&revoluteDef);

}

void Flipper::OnCollision(PhysBody* col)
{
	//printf("Col Flliper");
}
