#include "SceneDebug1.h"
#include "Ball.h"
#include "Flipper.h"
#include "ModuleTextures.h"
#include "ModulePhysics.h"

PhysBody* ground;

bool SceneDebug1::Start()
{
	/*SDL_Texture* player_texture = _app->textures->Load("Assets/Images/Game/Ball128.png");
	sceneTextures.add(player_texture);

	SDL_Texture* player_Shadowtexture = _app->textures->Load("Assets/Images/Game/BallShadow128.png");
	sceneTextures.add(player_Shadowtexture);

	SDL_Texture* flipper_texture = _app->textures->Load("Assets/Images/Game/FlipperR128.png");
	sceneTextures.add(flipper_texture);

	//Ball
	player = new Ball(player_texture, player_Shadowtexture, "Ball", "Player",_app);

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
