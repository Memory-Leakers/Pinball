#include "SceneGame.h"
#include "Ball.h"
#include "Flipper.h"
#include "ModuleTextures.h"
#include "ModulePhysics.h"
#include "Boing.h"

bool SceneGame::Start()
{
	SDL_Texture* player_texture = _app->textures->Load("Assets/Images/Game/Ball128.png");
	sceneTextures.add(player_texture);

	SDL_Texture* player_Shadowtexture = _app->textures->Load("Assets/Images/Game/BallShadow128.png");
	sceneTextures.add(player_Shadowtexture);

	SDL_Texture* flipper_texture = _app->textures->Load("Assets/Images/Game/FlipperR128.png");
	sceneTextures.add(flipper_texture);

	SDL_Texture* boing_texture = nullptr;

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
	int BG[110] = {
		550, 822,
		550, 316,
		542, 286,
		537, 271,
		531, 260,
		522, 246,
		513, 235,
		498, 223,
		482, 211,
		463, 203,
		442, 197,
		431, 197,
		265, 197,
		263, 187,
		261, 174,
		258, 164,
		255, 154,
		250, 142,
		245, 132,
		240, 122,
		233, 114,
		226, 105,
		219, 98,
		211, 92,
		205, 88,
		198, 86,
		190, 83,
		179, 81,
		171, 80,
		156, 83,
		143, 88,
		134, 94,
		126, 99,
		121, 105,
		115, 111,
		110, 116,
		106, 124,
		101, 131,
		97, 140,
		94, 146,
		91, 155,
		88, 167,
		86, 175,
		85, 184,
		83, 198,
		77, 323,
		80, 825,
		112, 824,
		112, 806,
		254, 854,
		254, 900,
		326, 900,
		325, 855,
		481, 808,
		481, 824
	};
	int BG2[68] = {
		511, 825,
		511, 341,
		508, 329,
		502, 313,
		496, 302,
		486, 291,
		476, 284,
		465, 276,
		455, 270,
		444, 266,
		430, 264,
		417, 264,
		404, 266,
		395, 269,
		385, 273,
		375, 277,
		366, 283,
		356, 292,
		350, 299,
		344, 307,
		340, 315,
		336, 323,
		334, 331,
		332, 339,
		331, 348,
		332, 357,
		332, 366,
		333, 373,
		336, 381,
		338, 389,
		342, 398,
		344, 403,
		348, 408,
		352, 414
	};
	int BG3[44] = {
		324, 269,
		258, 269,
		258, 428,
		324, 428,
		320, 421,
		315, 413,
		310, 404,
		306, 393,
		303, 383,
		300, 372,
		299, 360,
		298, 350,
		298, 340,
		299, 330,
		300, 322,
		302, 313,
		305, 304,
		308, 297,
		312, 288,
		316, 283,
		320, 276,
		324, 271
	};
	int SM1[8] = {
		144, 272,
		136, 272,
		136, 306,
		144, 306
	};
	int SM2[8] = {
		207, 272,
		199, 272,
		199, 306,
		207, 306
	};
	int FP1[12] = {
		482, 661,
		482, 739,
		398, 787,
		391, 772,
		477, 715,
		477, 661
	};
	int FP2[12] = {
		110, 661,
		110, 739,
		194, 787,
		200, 772,
		114, 715,
		114, 661
	};
	int PM[70] = {
		78, 378,
		90, 379,
		99, 381,
		106, 385,
		112, 389,
		116, 398,
		120, 412,
		124, 424,
		127, 432,
		130, 441,
		135, 452,
		141, 460,
		147, 472,
		154, 484,
		159, 492,
		166, 505,
		174, 515,
		179, 520,
		185, 522,
		193, 521,
		198, 520,
		203, 516,
		203, 510,
		198, 505,
		191, 502,
		184, 497,
		176, 491,
		168, 485,
		162, 477,
		154, 464,
		144, 450,
		138, 440,
		131, 428,
		124, 416,
		117, 403
	};

	bg1 = _app->physics->CreateChainObj(0, 0, BG, 110, true);
	bg1->body->SetType(b2BodyType::b2_staticBody);

	bg2 = _app->physics->CreateChainObj(0, 0, BG2, 68, false);
	bg2->body->SetType(b2BodyType::b2_staticBody);

	bg3 = _app->physics->CreateChainObj(-10, 0, BG3, 42, true);
	bg3->body->SetType(b2BodyType::b2_staticBody);

	smDivider1M = _app->physics->CreateChainObj(-5, 0, SM1, 8, true);
	smDivider1M->body->SetType(b2BodyType::b2_staticBody);

	smDivider2M = _app->physics->CreateChainObj(-5, 0, SM2, 8, true);
	smDivider2M->body->SetType(b2BodyType::b2_staticBody);

	flipper1 = _app->physics->CreateChainObj(0, 0, FP1, 12, true);
	flipper1->body->SetType(b2BodyType::b2_staticBody);

	flipper2 = _app->physics->CreateChainObj(0, 0, FP2, 12, true);
	flipper2->body->SetType(b2BodyType::b2_staticBody);

	pm = _app->physics->CreateChainObj(0, 0, PM, 70, false);
	pm->body->SetType(b2BodyType::b2_staticBody);

	//UI
	uis[0] = _app->ui->CreateUI(0, 300, 25);
	uis[1] = _app->ui->CreateUI(2340, 300, 75);
	uis[2] = _app->ui->CreateUI(98320, 300, 125);

	gameObjects.add(player);

	gameObjects.add(flipper);

	gameObjects.add(boing);

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

	delete bg1;
	bg1 = nullptr;
	delete bg2;
	bg2 = nullptr;
	delete bg3;
	bg3 = nullptr;
	delete ball;
	ball = nullptr;
	delete flipper1;
	flipper1 = nullptr;
	delete flipper2;
	flipper2 = nullptr;
	delete smDivider1M;
	smDivider1M = nullptr;
	delete smDivider2M;
	smDivider2M = nullptr;
	delete pm;
	pm = nullptr;

	return true;
}