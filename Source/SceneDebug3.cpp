#include "SceneDebug3.h"

PhysBody* bg1;
PhysBody* bg2;
PhysBody* bg3;
PhysBody* ball;
PhysBody* flipper1;
PhysBody* flipper2;

PhysBody* smDivider1M;
PhysBody* smDivider2M;

PhysBody* pm;

PhysBody* upperLeft;
PhysBody* upperRight;

SceneDebug3::SceneDebug3(Application* app) : Scene(app)
{

}

bool SceneDebug3::Start()
{
	ball = _app->physics->CreateCircle(300, 300, 12);
	ball->body->SetType(b2BodyType::b2_dynamicBody);
	ball->body->SetBullet(true);

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
		502, 350,
		503, 822
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

	int UPPERLEFT[120] = {
		158, 541,
		106, 495,
		95, 487,
		87, 484,
		80, 480,
		77, 487,
		90, 492,
		100, 495,
		113, 504,
		127, 515,
		134, 524,
		139, 534,
		141, 544,
		141, 567,
		141, 647,
		137, 652,
		132, 657,
		125, 657,
		117, 655,
		111, 648,
		108, 640,
		104, 632,
		97, 628,
		91, 627,
		82, 625,
		74, 625,
		67, 625,
		56, 625,
		48, 624,
		41, 624,
		34, 622,
		27, 618,
		20, 612,
		15, 607,
		12, 569,
		12, 549,
		12, 534,
		11, 521,
		11, 510,
		12, 495,
		12, 482,
		14, 470,
		20, 460,
		27, 453,
		33, 448,
		40, 445,
		48, 442,
		55, 440,
		62, 438,
		70, 438,
		79, 439,
		87, 440,
		96, 445,
		107, 449,
		119, 461,
		134, 473,
		154, 488,
		168, 497,
		185, 508,
		210, 525
	};
	int UPPERRIGHT[92] = {
		388, 523,
		416, 504,
		445, 484,
		460, 472,
		476, 459,
		488, 450,
		497, 444,
		512, 440,
		526, 440,
		542, 441,
		555, 444,
		566, 451,
		575, 457,
		581, 471,
		583, 488,
		583, 516,
		585, 561,
		583, 596,
		580, 611,
		570, 619,
		564, 621,
		553, 624,
		544, 625,
		524, 625,
		508, 625,
		496, 627,
		488, 636,
		485, 648,
		479, 654,
		470, 657,
		461, 654,
		454, 647,
		454, 638,
		454, 545,
		456, 535,
		459, 526,
		465, 517,
		477, 505,
		490, 497,
		508, 490,
		519, 485,
		518, 478,
		508, 481,
		479, 501,
		455, 522,
		438, 538
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

	flipper1 = _app->physics->CreateChainObj(0, 0, FP1, 12, true);
	flipper1->body->SetType(b2BodyType::b2_staticBody);

	flipper2 = _app->physics->CreateChainObj(0, 0, FP2, 12, true);
	flipper2->body->SetType(b2BodyType::b2_staticBody);

	pm = _app->physics->CreateChainObj(0, 0, PM, 70, false);
	pm->body->SetType(b2BodyType::b2_staticBody);

	/*
	upperLeft = _app->physics->CreateChainObj(0, 0, UPPERLEFT, 120, false);
	upperLeft->body->SetType(b2BodyType::b2_staticBody);

	upperRight = _app->physics->CreateChainObj(0, 0, UPPERRIGHT, 92, false);
	upperRight->body->SetType(b2BodyType::b2_staticBody);
	*/
	return true;
}

bool SceneDebug3::Update()
{

	return true;
}

bool SceneDebug3::PostUpdate()
{

	return true;
}

bool SceneDebug3::CleanUp()
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

	delete upperLeft;
	upperLeft = nullptr;
	delete upperRight;
	upperRight = nullptr;

	//Clean up UIs
	_app->ui->CleanUp();

	return true;
}
