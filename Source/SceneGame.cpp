#include "SceneGame.h"
#include "Ball.h"
#include "Flipper.h"
#include "ModuleTextures.h"
#include "ModulePhysics.h"
#include "Boing.h"
#include "PolygonBoing.h"
#include "Sensor.h"
#include "Boss.h"
#include "Spring.h"
#include "PhysLayerL.h"
#include "ScoreSystem.h"
#include "Coins.h"

bool SceneGame::Start()
{
	//Triangle Points
	int TBLEFT[6] = {
		145, 633,
		145, 696,
		183, 726
	};
	int TBRIGHT[6] = {
		436, 640,
		436, 704,
		397, 732
	};

	int BOSSBOING1[24] = {
		368, 291,
		370, 296,
		370, 302,
		369, 308,
		366, 312,
		362, 315,
		357, 317,
		352, 317,
		349, 317,
		352, 310,
		360, 300,
		366, 293
	};
	int BOSSBOING2[22] = {
		342, 364,
		349, 365,
		356, 368,
		360, 376,
		361, 384,
		359, 390,
		354, 395,
		351, 397,
		346, 389,
		342, 381,
		341, 372
	};
	int BOSSBOING3[18] = {
		468, 288,
		465, 294,
		465, 305,
		470, 313,
		480, 316,
		489, 315,
		483, 304,
		474, 292,
		471, 290
	};
	int BOSSBOING4[18] = {
		501, 363,
		492, 365,
		485, 371,
		483, 378,
		483, 385,
		486, 392,
		493, 397,
		502, 398,
		503, 370
	};
	int LONGBOING[22] = {
		160, 475,
		164, 466,
		166, 458,
		164, 447,
		159, 437,
		152, 425,
		145, 414,
		138, 407,
		131, 405,
		123, 405,
		142, 443
	};

	// Create Map
	CreateMap();

	bg = _app->textures->Load("Assets/Images/Game/BG.png");

	physLayer = new PhysLayerL("PhysLayerL", "PhysLayer", _app);

	//pLayerR = _app->textures->Load("Assets/Images/Game/Layer2R.png");

	coin = new Coins("Coin", "Coin", _app, iPoint{ 400,400 });

	// Ball
	player = new Ball("Ball", "Player", _app);

	// Boing
	//LEFT SIDE OF THE SCREEN
	boing[0] = new Boing("Boing", "Boing", _app, 140, 195);
	boing[1] = new Boing("Boing", "Boing", _app, 203, 195);
	boing[2] = new Boing("Boing", "Boing", _app, 164, 358);
	boing[3] = new Boing("Boing", "Boing", _app, 79, 358);
	boing[4] = new Boing("Boing", "Boing", _app, 247, 358);

	

	// PolygonBoing
	triBoing[0] = new PolygonBoing("TriangleBoingLeft", "PolygonBoing", _app, 0, 0, TBLEFT, 6);
	triBoing[1] = new PolygonBoing("TriangleBoingRight", "PolygonBoing", _app, 0, -5, TBRIGHT, 6);

	//BOSS SIDE
	bossBoing[0] = new PolygonBoing("PolygonBoing1", "PolygonBoing", _app, 0, 0, BOSSBOING1, 24);
	bossBoing[1] = new PolygonBoing("PolygonBoing2", "PolygonBoing", _app, -3, 3, BOSSBOING2, 22);
	bossBoing[2] = new PolygonBoing("PolygonBoing3", "PolygonBoing", _app, 2, -2, BOSSBOING3, 18);
	bossBoing[3] = new PolygonBoing("PolygonBoing4", "PolygonBoing", _app, 3, 0, BOSSBOING4, 18);
	//LONG BOING
	bossBoing[4] = new PolygonBoing("PolygonBoing5", "PolygonBoing", _app, 0, 0, LONGBOING, 22);

	// Flipper
	flipper_right = new Flipper("Flipper_right", "Flipper", _app, flipper1, true, SDL_SCANCODE_X);

	flipper_left = new Flipper("Flipper_left", "Flipper", _app, flipper2, false, SDL_SCANCODE_Z);

	// Boss
	boss = new Boss(100000, "Boss", "Boss", _app);

	// Spring
	spring = new Spring(iPoint(513, 827), "Spring", "Spring", _app);

	// Sensor
	sensor = new Sensor({ 200,120,25,25 },1, "Sensor", "Sensor", _app);
	sBallSpring = new Sensor({ 533, 805, 10, 10 }, -1, "SensorBS", "Sensor", _app);
	sTeleportIn = new Sensor({ 90, 415, 10,10 }, -1, "SensorT", "Sensor", _app);

	deathSensor = new Sensor({ 288, 900, 68, 30 }, -1, "DeathSensor", "Sensor", _app);

	// Add gameObjects to the main array
	gameObjects.add(player);
	gameObjects.add(flipper_right);
	gameObjects.add(flipper_left);
	for (int i = 0; i < BOINGCOUNT; i++) gameObjects.add(boing[i]);
	for (int i = 0; i < TRIBOINGCOUNT; i++) gameObjects.add(triBoing[i]);
	for (int i = 0; i < BOSSBOINGCOUNT; i++) gameObjects.add(bossBoing[i]);
	gameObjects.add(sensor);
	gameObjects.add(boss);
	gameObjects.add(spring);
	gameObjects.add(sBallSpring);
	gameObjects.add(deathSensor);
	gameObjects.add(sTeleportIn);
	gameObjects.add(physLayer);
	gameObjects.add(coin);



	// UI
	scoreSystem = ScoreSystem::Instance(_app);

	return true;
}

bool SceneGame::PreUpdate()
{
	for (int i = 0; i < gameObjects.count(); i++)
	{
		if (gameObjects[i] != nullptr)
		{
			if (gameObjects[i]->pendingToDelete)
			{
				// Delete gameOjects
				DestroyGameObject(gameObjects[i]);
			}
			else
			{
				// Update gmeObjects
				gameObjects[i]->PreUpdate();
			}
		}
	}

	if (player->isTeleporting || player->isDeath)
	{
		int tpX = 200, tpY = 150;
		if (player->isDeath)
		{
			tpX = 520;
			tpY = 780;
		}

		player->isTeleporting = false;
		player->isDeath = false;

		// Teleport Player
		Ball* temp = new Ball(*player, b2Vec2(tpX, tpY), false);
		if (player->pBody->body->GetJointList() != nullptr)
		{
			_app->physics->world->DestroyJoint(player->pBody->body->GetJointList()->joint);
		}
		DestroyGameObject(player);
		player = temp;
		gameObjects.add(player);
	}

	return true;
}

bool SceneGame::Update()
{
	//Update ScoreSystem
	scoreSystem->Update();

	// Debug Key
	if (_app->input->GetKey(SDL_SCANCODE_B) == KEY_DOWN)
	{
		// Teleport Player
		Ball* temp = new Ball(*player, b2Vec2(750, 150), true);
		if (player->pBody->body->GetJointList() != nullptr)
		{
			_app->physics->world->DestroyJoint(player->pBody->body->GetJointList()->joint);
		}
		gameObjects.del(gameObjects.At(gameObjects.find(player)));
		player = temp;
		gameObjects.add(player);
	}
	if (_app->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN)
	{
		bg1->body->GetFixtureList()->SetSensor(!bg1->body->GetFixtureList()->IsSensor());
	}
	if (_app->input->GetKey(SDL_SCANCODE_Q) == KEY_REPEAT)
	{
		boss->health -= 1000;
	}
	if (_app->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
	{
		boss->health += 1000;
	}
	if (_app->input->GetKey(SDL_SCANCODE_C) == KEY_REPEAT)
	{
		scoreSystem->AddCombo(1);
	}
	if (_app->input->GetKey(SDL_SCANCODE_V) == KEY_REPEAT)
	{
		scoreSystem->ResetCombo();
	}

	for (int i = 0; i < gameObjects.count(); i++)
	{
		if (gameObjects[i] != nullptr)
		{
			gameObjects[i]->Update();
		}
	}

	//printf("%d,%d\n", _app->input->GetMouseX(), _app->input->GetMouseY());
	return true;
}

bool SceneGame::PostUpdate()
{
	_app->renderer->AddTextureRenderQueue(bg, { 0,0 }, nullptr, 1.0f, 0, 1.0f);

	for (int i = 0; i < gameObjects.count(); i++)
	{
		if (gameObjects[i] != nullptr)
		{
			gameObjects[i]->PostUpdate();
		}
	}

	return true;
}

bool SceneGame::CleanUp()
{
	Scene::CleanUp();

	// Delete Map
	DeleteMap();

	scoreSystem->Release();

	// Clean Up UI
	_app->ui->CleanUp();

	return true;
}

void SceneGame::CreateMap()
{
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
		171, 83,
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
		253, 855,
		253, 935,	//PUNTOS CHAIN abajo centro
		321, 935,	//PUNTOS CHAIN abajo centro
		321, 855,
		476, 808,
		477, 824
	};
	int BG2[98] = {
		518, 824,
		519, 347,
		516, 330,
		510, 318,
		504, 306,
		496, 294,
		483, 280,
		471, 271,
		451, 263,
		429, 260,
		404, 261,
		382, 267,
		361, 278,
		350, 286,
		336, 306,
		331, 320,
		326, 338,
		325, 354,
		329, 387,
		340, 410,
		349, 419,
		354, 419,
		357, 416,
		357, 411,
		354, 405,
		349, 395,
		344, 385,
		342, 375,
		341, 367,
		341, 357,
		341, 347,
		342, 337,
		345, 328,
		348, 320,
		353, 309,
		359, 302,
		367, 293,
		380, 284,
		394, 278,
		414, 275,
		432, 275,
		448, 278,
		464, 284,
		475, 294,
		483, 304,
		489, 315,
		497, 332,
		503, 347,
		503, 824
	};
	int BG3[44] = {
		324, 270,
		258, 270,
		258, 428,
		322, 425,
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
	int FP1[28] = {
		473, 659,
		481, 659,
		480, 726,
		477, 735,
		470, 743,
		462, 748,
		408, 780,
		399, 785,
		392, 784,
		390, 775,
		397, 765,
		408, 758,
		465, 719,
		471, 710
	};
	int FP2[20] = {
		107, 660,
		115, 660,
		114, 709,
		121, 720,
		198, 772,
		195, 782,
		193, 786,
		151, 762,
		107, 736,
		107, 718
	};
	int PM[46] = {
		77, 377,
		88, 379,
		100, 384,
		108, 389,
		116, 397,
		125, 409,
		133, 425,
		144, 446,
		157, 469,
		171, 493,
		184, 510,
		184, 516,
		183, 520,
		177, 519,
		169, 508,
		155, 487,
		142, 462,
		130, 437,
		117, 415,
		109, 404,
		99, 395,
		88, 387,
		77, 386
	};

	bg1 = _app->physics->CreateChainObj(0, 0, BG, 110, true);
	bg1->body->SetType(b2BodyType::b2_staticBody);

	bg2 = _app->physics->CreateChainObj(0, 0, BG2, 98, false);
	bg2->body->SetType(b2BodyType::b2_staticBody);

	bg3 = _app->physics->CreateChainObj(-10, 0, BG3, 42, true);
	bg3->body->SetType(b2BodyType::b2_staticBody);

	smDivider1M = _app->physics->CreateChainObj(-5, 0, SM1, 8, true);
	smDivider1M->body->SetType(b2BodyType::b2_staticBody);

	smDivider2M = _app->physics->CreateChainObj(-5, 0, SM2, 8, true);
	smDivider2M->body->SetType(b2BodyType::b2_staticBody);

	flipper1 = _app->physics->CreateChainObj(-7, 0, FP1, 28, true);
	flipper1->body->SetType(b2BodyType::b2_staticBody);

	flipper2 = _app->physics->CreateChainObj(0, 0, FP2, 20, true);
	flipper2->body->SetType(b2BodyType::b2_staticBody);

	pm = _app->physics->CreateChainObj(0, 0, PM, 46, false);
	pm->body->SetType(b2BodyType::b2_staticBody);
}

void SceneGame::DeleteMap()
{
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
}
