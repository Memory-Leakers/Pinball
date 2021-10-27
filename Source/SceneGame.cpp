#include "SceneGame.h"
#include "Ball.h"
#include "Flipper.h"
#include "ModuleTextures.h"
#include "ModulePhysics.h"
#include "Boing.h"
#include "PolygonBoing.h"
#include "Sensor.h"
#include "KeySensor.h"
#include "CannonSensor.h"
#include "Boss.h"
#include "Spring.h"
#include "PhysLayerL.h"
#include "PhysLayerR.h"
#include "ScoreSystem.h"
#include "CoinsManager.h"
#include "Cannon.h"
#include "RectObsatcle.h"
#include <math.h>

bool SceneGame::Start()
{
	_app->gameOver = false;

	// Create Map
	CreateMap();

	bg = _app->textures->Load("Assets/Images/Game/BG.png");
	gameover = _app->textures->Load("Assets/Images/Game/GameOver.png");
	lifes = _app->textures->Load("Assets/Images/Game/Life_icon.png");


	for (int i = 0; i < 3; i++)
	{
		lifeIcons[i] = new RenderObject();
		lifeIcons[i]->texture = lifes;

		lifeIcons[i]->section = new SDL_Rect({ 0,0,128,128 });

		lifeIcons[i]->renderRect.x = 226 + (i * 50);
		lifeIcons[i]->renderRect.y = 738;

		lifeIcons[i]->scale = 0.3f;
	}

	//LEFTSIDE
	physLayer = new PhysLayerL("PhysLayerL", "PhysLayer", _app);
	physLayer2 = new PhysLayerR("PhysLayerR", "PhysLayer", _app);

	enterPhysLayerL = new Sensor({ 90, 470, 10, 10 }, -1, "ChangeLayerSensor", "PhysLayer", _app);
	exitPhysLayerL = new Sensor({ 118, 650, 50, 10 }, -1, "ChangeLayerSensorSecondLevel", "PhysLayer", _app);

	enterPhysLayerR = new Sensor({ 407, 526, 10, 10 }, -1, "ChangeLayerSensorLockedDoor", "PhysLayer", _app);
	exitPhysLayerR = new Sensor({ 454, 635, 10, 10 }, -1, "ChangeLayerSensorSecondLevel", "PhysLayer", _app);

	rightKey1 = new KeySensor({ 399, 514, 10, 10 }, -1, "KeySensor1", "PhysLayer", _app);
	rightKey2 = new KeySensor({ 416, 541, 10, 10 }, -1, "KeySensor2", "PhysLayer", _app);

	coinsManager = new CoinsManager(_app);

	// Ball
	player = new Ball("Ball", "Player", _app);
	playerLifes = 3;

	// Cannon
	cannon = new Cannon("Cannon", "Cannon", _app, iPoint(285, 600));

	// Boing
	//LEFT SIDE OF THE SCREEN
	boing[0] = new Boing("Boing", "Boing", _app, 140, 195);
	boing[1] = new Boing("Boing", "Boing", _app, 203, 195);
	boing[2] = new Boing("Boing", "Boing", _app, 164, 358);
	boing[3] = new Boing("Boing", "Boing", _app, 79, 358);
	boing[4] = new Boing("Boing", "Boing", _app, 247, 358);

	// Flipper
	flipper_right = new Flipper("Flipper_right", "Flipper", _app, flipper1, true, SDL_SCANCODE_X);

	flipper_left = new Flipper("Flipper_left", "Flipper", _app, flipper2, false, SDL_SCANCODE_Z);

	// Boss
	boss = new Boss(100000, "Boss", "Boss", _app);

	// Rect save life
	rectSaveLifeR = new RectObstacle("RectSaveLifeR", "RectSaveLife", _app, 488, 800, -30);
	rectSaveLifeL = new RectObstacle("RectSaveLifeL", "RectSaveLife", _app, 93, 800, 30);

	// Springs
	spring = new Spring(iPoint(514, 829), "Spring", "Spring", _app, SDL_SCANCODE_SPACE);
	springR = new Spring(iPoint(469, 825), "SpringR", "Spring", _app, SDL_SCANCODE_SPACE, false);
	springL = new Spring(iPoint(74, 825), "SpringL", "Spring", _app, SDL_SCANCODE_SPACE, false);

	// Sensor
	sBallSpring = new Sensor({ 533, 815, 10, 5 }, -1, "SensorBS", "SpringSensor", _app);
	sBallSpringR = new Sensor({ 488, 815, 10, 5 }, -1, "SensorBSR", "SpringSensor", _app);
	sBallSpringL = new Sensor({ 93, 815, 10, 5 }, -1, "SensorBSL", "SpringSensor", _app);

	sTeleportIn = new Sensor({ 90, 415, 10,10 }, -1, "SensorT", "Sensor", _app);
	Cannon1 = new CannonSensor({ 107,288,10,10 }, -1, "SensorC1", "SensorC1", _app);
	Cannon2 = new CannonSensor({ 166,288,10,10 }, -1, "SensorC2", "SensorC2", _app);
	Cannon3 = new CannonSensor({ 227,288,10,10 }, -1, "SensorC3", "SensorC3", _app);

	deathSensor = new Sensor({ 288, 935, 68, 1 }, -1, "DeathSensor", "Sensor", _app);

	#pragma region Add gameObjects to the main array

	gameObjects.add(player);
	gameObjects.add(flipper_right);
	gameObjects.add(flipper_left);
	for (int i = 0; i < BOINGCOUNT; i++) gameObjects.add(boing[i]);
	for (int i = 0; i < TRIBOINGCOUNT; i++) gameObjects.add(triBoing[i]);
	//for (int i = 0; i < BOSSBOINGCOUNT; i++) gameObjects.add(bossBoing[i]);
	gameObjects.add(bossBoing[0]);
	gameObjects.add(bossBoing[1]);
	gameObjects.add(bossBoing[2]);
	gameObjects.add(bossBoing[3]);
	gameObjects.add(boss);
	gameObjects.add(rectSaveLifeR);
	gameObjects.add(rectSaveLifeL);
	gameObjects.add(spring);
	gameObjects.add(springR);
	gameObjects.add(springL);
	gameObjects.add(sBallSpring);
	gameObjects.add(sBallSpringR);
	gameObjects.add(sBallSpringL);
	gameObjects.add(deathSensor);
	gameObjects.add(Cannon1);
	gameObjects.add(Cannon2);
	gameObjects.add(Cannon3);
	gameObjects.add(sTeleportIn);
	gameObjects.add(physLayer->boing);
	gameObjects.add(physLayer);
	gameObjects.add(physLayer2);
	gameObjects.add(enterPhysLayerL);
	gameObjects.add(exitPhysLayerL);
	gameObjects.add(enterPhysLayerR);
	gameObjects.add(exitPhysLayerR);
	gameObjects.add(rightKey1);
	gameObjects.add(rightKey2);
	gameObjects.add(cannon);

	#pragma endregion

	// UI
	scoreSystem = ScoreSystem::Instance(_app);

	gamefinished = false;

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

	if ((player != nullptr) && (player->isTeleporting || player->isDeath))
	{
		int tpX = 190, tpY = 140;
		if (player->isDeath)
		{
			playerLifes--;
			tpX = 535;
			tpY = 780;
		}

		player->isTeleporting = false;
		player->isDeath = false;

		if (playerLifes)
		{
			// Teleport Player
			Ball* temp = new Ball(*player, b2Vec2(tpX, tpY), false);
			if (player->pBody->body->GetJointList() != nullptr)
			{
				_app->physics->world->DestroyJoint(player->pBody->body->GetJointList()->joint);
			}
			DestroyGameObject(player);
			player = temp;
			gameObjects.add(player);

			float randomFloat = -10 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (10 + 10)));

			player->pBody->body->ApplyForceToCenter(b2Vec2(randomFloat, 0), true);
		}
		else
		{
			//Game Over
			printf("\n\nGAME OVER!!\n\n");
			GameOver();
		}
	}

	// PreUpdate Coins Manager
	coinsManager->PreUpdate();

	// Life icons logic
	for (int i = 2; i >= playerLifes; i--)
	{
		lifeIcons[i]->section->x = 128;
	}
	if (Cannon1->CannonSensor1 && Cannon2->CannonSensor2 && Cannon3->CannonSensor3 && !IsCannonShown )
	{
		cannon->ShowCannon();
		IsCannonShown = true;
	}

	return true;
}

bool SceneGame::Update()
{
	//Update ScoreSystem
	scoreSystem->Update();

	#pragma region Debug Key
	if (_app->input->GetKey(SDL_SCANCODE_B) == KEY_DOWN)
	{
		// Teleport Player
		Ball* temp = new Ball(*player, b2Vec2(550, 150), true);
		DestroyGameObject(player);
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
	if (_app->input->GetKey(SDL_SCANCODE_V) == KEY_DOWN)
	{
		scoreSystem->ResetCombo();
	}
	if (_app->input->GetKey(SDL_SCANCODE_L) == KEY_DOWN)
	{
		GameOver();
	}
	if (_app->input->GetKey(SDL_SCANCODE_R) == KEY_DOWN && gamefinished)
	{
		_app->scene->ChangeCurrentScene(4, 0);
	}
	#pragma endregion

	for (int i = 0; i < gameObjects.count(); i++)
	{
		if (gameObjects[i] != nullptr)
		{
			gameObjects[i]->Update();
		}
	}

	//printf("%d,%d\n", _app->input->GetMouseX(), _app->input->GetMouseY());

	// Update Coins Manager
	coinsManager->Update();

	//Manages Layer Switch
	SecondLayer();

	//Manages Right Upper Layer Texture Swutch
	if (rightKey1->unlocked && rightKey2->unlocked && enterPhysLayerR->name == "ChangeLayerSensorLockedDoor")
	{
		physLayer2->swapLowerTexture();
		enterPhysLayerR->name = "ChangeLayerSensorUnlockedDoor";
	}

	// Player in Cannon
	if (cannon->isPlayerIn)
	{
		if (player !=  nullptr);
		{
			DestroyGameObject(player);
			player = nullptr;
		}

		if (_app->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)
		{
			printf("%f",cannon->renderObjects[0].rotation);

			// angle
			int angle = (int)cannon->renderObjects[0].rotation % 360;

			// vector velocity
			float y = -cos(DEGTORAD * angle);
			float x = sin(DEGTORAD * angle);

			// center cannon
			iPoint centerCannon;
			centerCannon.x = cannon->GetDrawPos().x;
			centerCannon.y = cannon->GetDrawPos().y;
			centerCannon.x = centerCannon.x + 128 * cannon->cannonSize - (128 * cannon->renderObjects[0].scale);
			centerCannon.y = centerCannon.y + 128 * cannon->cannonSize - (128 * cannon->renderObjects[0].scale);

			fPoint offset = { 16 * x, 16 * y };
			centerCannon.x += offset.x;
			centerCannon.y += offset.y;

			Ball* temp = new Ball("Player", "Player", _app, centerCannon);
			player = temp;
			player->pBody->body->ApplyForceToCenter(b2Vec2(x * cannon->cannonForce, y * cannon->cannonForce), true);
			gameObjects.add(player);

			cannon->Reset();

			// TODO: Close Cannon Sensor
			if (IsCannonShown)
			{
				Cannon1->Reset();
				Cannon2->Reset();
				Cannon3->Reset();
				IsCannonShown = false;
			}
		}
	}

	return true;
}

bool SceneGame::PostUpdate()
{
	if(!gamefinished)
	{
		//BackGround
		_app->renderer->AddTextureRenderQueue(bg, { 0,0 }, nullptr, 1.0f, 0, 1.0f);

		// GameObjects
		for (int i = 0; i < gameObjects.count(); i++)
		{
			if (gameObjects[i] != nullptr)
			{
				gameObjects[i]->PostUpdate();
			}
		}

		// Lifes
		for (int i = 0; i < 3; i++)
		{
			_app->renderer->AddTextureRenderQueue(*lifeIcons[i]);
		}

		// Coins Manager
		coinsManager->PostUpdate();
	}
	else
	{
		_app->gameOver = true;
		_app->renderer->AddTextureRenderQueue(gameover, { 0,0 }, nullptr, 1.0f, 3, 1.0f);
	}

	return true;
}

bool SceneGame::CleanUp()
{
	Scene::CleanUp();

	// Delete Map
	DeleteMap();

	scoreSystem->Release();

	if(coinsManager != nullptr)
	{
		delete coinsManager;
		coinsManager = nullptr;
	}

	for (int i = 0; i < 3; i++)
	{
		if (lifeIcons[i] != nullptr && lifeIcons[i]->section != nullptr)
		{
			delete lifeIcons[i]->section;
			lifeIcons[i]->section = nullptr;

			delete lifeIcons[i];
			lifeIcons[i] = nullptr;
		}
	}

	return true;
}

void SceneGame::SecondLayer()
{
	if (player && player->topLayer)
	{
		//FIRST LAYER OFF
		bg1->body->GetFixtureList()->SetSensor(true);
		bg2->body->GetFixtureList()->SetSensor(true);
		bg3->body->GetFixtureList()->SetSensor(true);
		smDivider1M->body->GetFixtureList()->SetSensor(true);
		smDivider2M->body->GetFixtureList()->SetSensor(true);
		flipper1->body->GetFixtureList()->SetSensor(true);
		flipper2->body->GetFixtureList()->SetSensor(true);
		pm->body->GetFixtureList()->SetSensor(true);
		triBoing[0]->setSensor(true);
		triBoing[1]->setSensor(true);

		//SECOND LAYER ON
		physLayer->setSensor(false);
		physLayer2->setSensor(false);
	}
	else
	{
		//FIRST LAYER ON
		bg1->body->GetFixtureList()->SetSensor(false);
		bg2->body->GetFixtureList()->SetSensor(false);
		bg3->body->GetFixtureList()->SetSensor(false);
		smDivider1M->body->GetFixtureList()->SetSensor(false);
		smDivider2M->body->GetFixtureList()->SetSensor(false);
		flipper1->body->GetFixtureList()->SetSensor(false);
		flipper2->body->GetFixtureList()->SetSensor(false);
		pm->body->GetFixtureList()->SetSensor(false);
		triBoing[0]->setSensor(false);
		triBoing[1]->setSensor(false);

		//SECOND LAYER OFF
		physLayer->setSensor(true);
		physLayer2->setSensor(true);
	}
}
void SceneGame::GameOver()
{
	if (!gamefinished)
	{
		gamefinished = true;
	}
	else
	{
		gamefinished = false;
	}
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

	// Boing

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
	//int LONGBOING[22] = {
	//	160, 475,
	//	164, 466,
	//	166, 458,
	//	164, 447,
	//	159, 437,
	//	152, 425,
	//	145, 414,
	//	138, 407,
	//	131, 405,
	//	123, 405,
	//	142, 443
	//};

	// PolygonBoing
	triBoing[0] = new PolygonBoing("TriangleBoingLeft", "TriangularBoing", _app, 0, -5, TBLEFT, 6, 1, false);
	triBoing[1] = new PolygonBoing("TriangleBoingRight", "TriangularBoing", _app, 0, -8, TBRIGHT, 6, 1, true);

	//BOSS SIDE
	bossBoing[0] = new PolygonBoing("PolygonBoing1", "PolygonBoing", _app, 0, 0, BOSSBOING1, 24, 32.0f, iPoint(352, 286), 0.3f);
	bossBoing[1] = new PolygonBoing("PolygonBoing2", "PolygonBoing", _app, -3, 3, BOSSBOING2, 22, -10.0f, iPoint(344, 361), 0.3f);
	bossBoing[2] = new PolygonBoing("PolygonBoing3", "PolygonBoing", _app, 2, -2, BOSSBOING3, 18, 155.0f, iPoint(463, 286), 0.3f);
	bossBoing[3] = new PolygonBoing("PolygonBoing4", "PolygonBoing", _app, 3, 0, BOSSBOING4, 18, 180.0f, iPoint(483, 363), 0.3f);
	////LONG BOING
	//bossBoing[4] = new PolygonBoing("PolygonBoing5", "PolygonBoing", _app, 0, 0, LONGBOING, 22,3,false);
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
