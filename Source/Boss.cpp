#include "Boss.h"

Boss::Boss(int health, std::string name, std::string tag, Application* _app) : GameObject(name, tag, _app)
{
	// Score System
	scoreInstance = ScoreSystem::Instance(_app);

	// Create PhysBody
	pBody = _app->physics->CreateCircle(424, 355, 38, this);
	pBody->body->SetType(b2BodyType::b2_kinematicBody);
	pBody->body->GetFixtureList()->SetRestitution(0.7f);

	spriteY = GetDrawPos().y;
	maxSpriteDown = spriteY + 10;

	bossEyeR = { 441, 365, 3, 3 };
	bossEyeL = { 411, 365, 3, 3 };

	for (int i = 0; i < 6; i++)
	{
		if (i < 3)
		{
			bossSections[i].x = 128 * i;
			bossSections[i].y = 0;
		}
		else 
		{
			bossSections[i].x = 128 * (i - 3);
			bossSections[i].y = 128;
		}
	}

	// Create RenderObject
	renderObjects[0].texture = _app->textures->Load("Assets/Images/Game/Boss.png");
	renderObjects[1].texture = _app->textures->Load("Assets/Images/Game/HealthBar.png");

	renderObjects[0].section = new SDL_Rect{ bossSections[0].x, bossSections[0].y, 128, 128};
	renderObjects[0].scale = 0.65f;

	renderObjects[1].renderRect.x = 300;
	renderObjects[1].renderRect.y = 150;
	renderObjects[1].followPhysBody = false;
	renderObjects[1].layer = 3;

	// Create HealthBar
	this->health = health;

	healthBar = new HealthBar(_app, renderObjects[1].renderRect.x + 6, renderObjects[1].renderRect.y + 6, 188, 19, this->health);
}

Boss::~Boss()
{
	if (healthBar != nullptr)
	{
		delete healthBar;
		healthBar = nullptr;
	}
}

void Boss::Update()
{
	healthBar->currentHealth = health;
}

void Boss::PostUpdate()
{
	//GameObject::PostUpdate();

	topPerFrame--;

	if (topPerFrame == 0)
	{
		int speed = 1;
		int temp = GetDrawPos().y;

		if (spriteY == GetDrawPos().y)
		{
			goUp = false;
		}
		if (spriteY == maxSpriteDown)
		{
			goUp = true;
		}

		spriteY = goUp ? spriteY - speed : spriteY + speed;

		topPerFrame = 5;

	}

	// Dibujar texturas

	// Posicion del sprite
	renderObjects[0].renderRect.x = GetDrawPos().x-3;
	renderObjects[0].renderRect.y = spriteY -5;

	iPoint bossEyeBaseR = { 441, spriteY + 42 };
	iPoint bossEyeBaseL = { 408, spriteY + 42 };

	bossEyeR.x = bossEyeBaseR.x + (targetPos.x * 2);
	bossEyeR.y = bossEyeBaseR.y + (targetPos.y * 2);

	bossEyeL.x = bossEyeBaseL.x + (targetPos.x * 2);
	bossEyeL.y = bossEyeBaseL.y + (targetPos.y * 2);

	// Seccion del sprite
	if (healthBar->healthPercentage > 80)
	{
		currentIdleSection.x = bossSections[0].x;
		currentIdleSection.y = bossSections[0].y;

		currentHitSection.x = bossSections[3].x;
		currentHitSection.y = bossSections[3].y;
	}
	else if(healthBar->healthPercentage > 40)
	{

		currentIdleSection.x = bossSections[1].x;
		currentIdleSection.y = bossSections[1].y;

		currentHitSection.x = bossSections[4].x;
		currentHitSection.y = bossSections[4].y;
	}
	else 
	{
		currentIdleSection.x = bossSections[2].x;
		currentIdleSection.y = bossSections[2].y;

		currentHitSection.x = bossSections[5].x;
		currentHitSection.y = bossSections[5].y;
	}
	
	if (isBeingHit)
	{
		renderObjects[0].section->x = currentHitSection.x;
		renderObjects[0].section->y = currentHitSection.y;
	
		isBeingHit = --hitCounter != 0;
	
		hitCounter = isBeingHit ? hitCounter : 30;

	}
	else 
	{
		renderObjects[0].section->x = currentIdleSection.x;
		renderObjects[0].section->y = currentIdleSection.y;
	}

	for (int i = 0; i < 2; i++)
	{
		_app->renderer->AddTextureRenderQueue(renderObjects[i]);
	}

	// Draw boss eyes
	if (health > 0)
	{
		_app->renderer->AddRectRenderQueue(bossEyeR, 0, 0, 0);
		_app->renderer->AddRectRenderQueue(bossEyeL, 0, 0, 0);
	}

	healthBar->PostUpdate();
}

void Boss::OnCollision(PhysBody* col)
{
	if (col->gameObject->tag == "Player")
	{

		_app->ui->CreateUI(scoreInstance->GetScore(), GetDrawPos().x, GetDrawPos().y + 38, 0.6f, 3, true, 120, { 0,-1 });

		health -= scoreInstance->GetScore();

		scoreInstance->ResetCombo();
		scoreInstance->ResetScore();
	
		if (!isBeingHit)
		{
			isBeingHit = true;
		}
	}
}

void Boss::CleanUp()
{
	if (healthBar != nullptr)
	{
		delete healthBar;
		healthBar = nullptr;
	}
}


