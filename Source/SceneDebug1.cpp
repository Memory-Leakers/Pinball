#include "SceneDebug1.h"
#include "Ball.h"
#include "Flipper.h"
#include "ModuleTextures.h"
#include "ModulePhysics.h"

PhysBody* ground;

bool SceneDebug1::Start()
{
	SDL_Texture* player_texture = _app->textures->Load("Assets/Images/Game/Ball.png");
	SDL_Texture* player_Shadowtexture = _app->textures->Load("Assets/Images/Game/BallShadow.png");

	SDL_Texture* flipper_texture = _app->textures->Load("Assets/Images/Game/Flipper.png");

	//Ball
	player = new Ball(player_texture, player_Shadowtexture, "Ball", "Player");

	player->pBody = _app->physics->CreateCircle(200, 200, 16, player);

	player->pBody->body->SetBullet(true);

	//Flipper
	flipper = new Flipper(flipper_texture, "Flipper");

	flipper->pBody = _app->physics->CreateCircle(200, 0, 16, flipper);


	gameObjects.add(player);

	gameObjects.add(flipper);

	/*
	ground = _app->physics->CreateRectangle(250, 500, 700, 30);

	ground->body->SetType(b2BodyType::b2_staticBody);

	*/
	return true;
}

bool SceneDebug1::PostUpdate()
{
	iPoint p = player->GetDrawPos();

	float angle = player->pBody->body->GetAngle();

	_app->renderer->Blit(player->texture, p.x, p.y, 0.25f, NULL, 1.0f, angle * 50, SDL_FLIP_VERTICAL);

	_app->renderer->Blit(player->shadow, p.x, p.y, 0.25f);


	iPoint p2 = flipper->GetDrawPos();

	_app->renderer->Blit(flipper->texture, p2.x, p2.y, 0.3f);

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
