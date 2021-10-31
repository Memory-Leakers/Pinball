#include "Coins.h"
#include "PhysLayerR.h"

Coins::Coins(std::string name, std::string tag, Application* _app, iPoint pos) :GameObject(name, tag, _app)
{
	// Animation
	anim.PushBack(SDL_Rect{ 0, 0, 128, 128 });
	anim.PushBack(SDL_Rect{ 128, 0, 128, 128 });
	anim.PushBack(SDL_Rect{ 256, 0, 128, 128 });
	anim.PushBack(SDL_Rect{ 384, 0, 128, 128 });
	anim.PushBack(SDL_Rect{ 512, 0, 128, 128 });
	anim.PushBack(SDL_Rect{ 640, 0, 128, 128 });
	anim.hasIdle = false;
	anim.speed = 0.2f;

	// RenderObject
	renderObjects[0].texture = _app->textures->Load("Assets/Images/Game/Coins.png");
	renderObjects[0].section = new SDL_Rect{ 0, 0, 128, 128 };
	renderObjects[0].scale = 0.125f;
	renderObjects[0].layer = 1;
	renderObjects[0].orderInLayer = 1;

	// PhysBody
	pBody = _app->physics->CreateCircle(pos.x, pos.y, 8, this, true);
	pBody->body->SetType(b2_kinematicBody);

	scoreInstance = ScoreSystem::Instance(_app);
}

void Coins::PostUpdate()
{
	anim.Update();

	renderObjects[0].section->x = anim.GetCurrentFrame().x;

	GameObject::PostUpdate();
}

void Coins::OnCollision(PhysBody* col)
{
	if (!colSwitch) return;
	if (col->gameObject->CompareTag("Player"))
	{
		scoreInstance->AddCombo(1);
		_app->audio->PlayFx(3);
		pendingToDelete = true;
	}
}
