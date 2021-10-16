#include "SceneDebug1.h"
#include "Ball.h"
#include "ModuleTextures.h"
#include "ModulePhysics.h"

PhysBody* ground;

bool SceneDebug1::Start()
{
	SDL_Texture* t = _app->textures->Load("Assets/Images/Game/Ball.png");

	player = new Ball("Ball", t);
	
	player->pBody = _app->physics->CreateCircle(200, 0, 16);

	player->pBody->body->SetBullet(true);

	gameObjects.add(player);



	ground = _app->physics->CreateRectangle(250, 500, 700, 30);

	ground->body->SetType(b2BodyType::b2_staticBody);
	
	return true;
}

bool SceneDebug1::PostUpdate()
{
	iPoint p = player->GetDrawPos();

	float angle = player->pBody->body->GetAngle();

	_app->renderer->Blit(player->texture, p.x, p.y, NULL, 1.0f, angle * 50, SDL_FLIP_VERTICAL);

	return true;
}

bool SceneDebug1::CleanUp()
{
	if (ground != nullptr)
	{
		delete ground;
		ground = nullptr;
	}

	Scene::CleanUp();

	return true;
}