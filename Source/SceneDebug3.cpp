#include "SceneDebug3.h"


PhysBody* bg1;
PhysBody* bg2;
PhysBody* bg3;
PhysBody* ball;

SceneDebug3::SceneDebug3(Application* app) : Scene(app) 
{

}

bool SceneDebug3::Start()
{

	ball = _app->physics->CreateCircle(200, 200, 12);
	ball->body->SetType(b2BodyType::b2_dynamicBody);
	ball->body->SetBullet(true);


	// Pivot 0, 0
	/*
	int pin[12] = {
		472, 733,
		442, 733,
		441, 717,
		290, 762,
		291, 800,
		473, 801
	};
	*/
	// Pivot 0, 0
	// Pivot 0, 0
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
	/*int BG2[82] = {
	511, 825,
	511, 316,
	508, 305,
	505, 298,
	502, 289,
	497, 280,
	491, 272,
	483, 265,
	477, 259,
	470, 254,
	462, 249,
	453, 245,
	445, 242,
	436, 240,
	428, 239,
	419, 239,
	412, 239,
	402, 241,
	395, 242,
	387, 245,
	380, 248,
	374, 252,
	369, 256,
	364, 260,
	357, 265,
	352, 271,
	347, 278,
	343, 283,
	340, 289,
	337, 296,
	334, 303,
	332, 312,
	331, 321,
	331, 330,
	331, 340,
	333, 351,
	336, 359,
	340, 368,
	343, 376,
	347, 382,
	353, 387
	};*/
	// Pivot 0, 0
	int BG2[146] = {
		511, 822,
		512, 327,
		511, 321,
		510, 311,
		508, 304,
		505, 296,
		502, 288,
		498, 282,
		492, 274,
		486, 267,
		480, 261,
		470, 254,
		461, 248,
		450, 243,
		437, 240,
		425, 238,
		414, 238,
		403, 240,
		394, 242,
		387, 244,
		380, 248,
		372, 252,
		364, 258,
		356, 264,
		351, 271,
		347, 277,
		343, 283,
		339, 291,
		335, 300,
		333, 308,
		332, 315,
		331, 323,
		330, 334,
		331, 339,
		332, 348,
		335, 357,
		338, 368,
		345, 380,
		352, 390,
		354, 388,
		351, 383,
		344, 373,
		339, 363,
		336, 353,
		334, 343,
		333, 329,
		334, 317,
		337, 306,
		340, 295,
		344, 287,
		348, 279,
		356, 271,
		363, 264,
		372, 257,
		381, 252,
		389, 248,
		400, 244,
		410, 243,
		419, 242,
		427, 241,
		437, 243,
		448, 246,
		455, 248,
		462, 251,
		469, 255,
		476, 261,
		486, 269,
		493, 277,
		499, 288,
		502, 295,
		506, 305,
		509, 314,
		510, 327
	};
	// Pivot 0, 0
	int BG3[42] = {
		259, 391,
		324, 391,
		320, 385,
		316, 379,
		312, 373,
		308, 367,
		305, 361,
		302, 353,
		299, 345,
		298, 336,
		298, 328,
		298, 320,
		299, 312,
		301, 305,
		304, 296,
		307, 290,
		312, 283,
		316, 278,
		320, 273,
		325, 268,
		259, 268
	};

	bg1 = _app->physics->CreateChainObj(0, 0, BG, 110, true);
	bg1->body->SetType(b2BodyType::b2_staticBody);

	bg2 = _app->physics->CreateChainObj(0, 0, BG2, 146, false);
	bg2->body->SetType(b2BodyType::b2_staticBody);

	bg3 = _app->physics->CreateChainObj(-10, 0, BG3, 42, true);
	bg3->body->SetType(b2BodyType::b2_staticBody);

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


	return true;
}