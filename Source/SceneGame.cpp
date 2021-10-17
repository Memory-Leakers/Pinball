#include "SceneGame.h"
#include "Ball.h"
#include "Flipper.h"
#include "ModuleTextures.h"
#include "ModulePhysics.h"
#include "Boing.h"

bool SceneGame::Start()
{
	SDL_Texture* player_texture = _app->textures->Load("Assets/Images/Game/Ball128.png");
	SDL_Texture* player_Shadowtexture = _app->textures->Load("Assets/Images/Game/BallShadow128.png");
	SDL_Texture* boing_texture = nullptr;
	SDL_Texture* flipper_texture = _app->textures->Load("Assets/Images/Game/FlipperR128.png");

	//Ball
	player = new Ball(player_texture, player_Shadowtexture, "Ball", "Player");
	player->pBody = _app->physics->CreateCircle(200,200, 16, player);
	player->pBody->body->SetBullet(true);

	//Boing
	boing = new Boing(boing_texture,"Boing");
	boing->pBody = _app->physics->CreateCircle(85, 340, 18, boing);
	boing->pBody->body->SetType(b2BodyType::b2_staticBody);

	//Flipper
	flipper = new Flipper(flipper_texture, "Flipper");

	flipper->pBody = _app->physics->CreateRectangle(400, 500, 96, 18);

	//Map

	//UI

	uis[0] = _app->ui->CreateUI(0, 300, 25);
	uis[1] = _app->ui->CreateUI(2340, 300, 75);
	uis[2] = _app->ui->CreateUI(98320, 300, 125);

	gameObjects.add(player);

	gameObjects.add(flipper);

	return true;
}

bool SceneGame::PreUpdate()
{
	return true;
}

bool SceneGame::Update() 
{

	return true;
}

bool SceneGame::PostUpdate()
{
	iPoint p = player->GetDrawPos();

	_app->renderer->Blit(player->texture, p.x, p.y, 0.25f, NULL, 1.0f, player->GetDegreeAngle(), SDL_FLIP_VERTICAL);

	_app->renderer->Blit(player->shadow, p.x, p.y, 0.25f);


	iPoint p2 = flipper->GetDrawPos();

	_app->renderer->Blit(flipper->texture, p2.x, p2.y, 0.75f, NULL, 1.0f, flipper->GetDegreeAngle() , SDL_FLIP_VERTICAL);

	return true;
}

bool SceneGame::CleanUp() 
{
	Scene::CleanUp();

	delete boing;
	boing = nullptr;

	return true;
}