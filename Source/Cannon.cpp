#include "Cannon.h"

Cannon::Cannon(std::string name, std::string tag, Application* _app, iPoint pos):GameObject(name, tag, _app)
{
	// RenderObject
	renderObjects[0].texture = _app->textures->Load("Assets/Images/Game/Cannons.png");
	renderObjects[0].scale = 0.0f;
	renderObjects[0].layer = 1;
	renderObjects[0].orderInLayer = 1.0f;
	renderObjects[0].section = new SDL_Rect{ 0,0,256,256 };
	renderObjects[0].rotationEnabled = false;
	renderObjects[0].pivot.y = 10;

	renderObjects[0].name = name;

	// PhysBody
	pBody = _app->physics->CreateCircle(pos.x, pos.y, 32, this, true);
	pBody->body->SetType(b2_kinematicBody);
}


void Cannon::Update()
{
	//renderObjects[0].rotation += 2;

	if (_app->input->GetKey(SDL_SCANCODE_I) == KEY_DOWN)renderState = 1;

	switch (renderState)
	{
	case 0:
		break;
	case 1:
		// pause physic
		if(!_app->physics->GetPause())
		_app->physics->Pause();
		// Hole add scale
		holeSize += 0.002f;
		if (holeSize >= cannonSize) renderState++;
		break;
	case 2:
		// Cannon add scale
		renderObjects[0].scale += 0.002f;
		if (renderObjects[0].scale >= cannonSize)
		{
			renderState++;
			// restart physic
			if (_app->physics->GetPause())
			_app->physics->Pause();
		}
		break;
	case 4:
		// Cannon rotate
		renderObjects[0].rotation += 2.0f;
		break;
	}
}

void Cannon::PostUpdate()
{
	// Animation hole change scale need center pivot
	iPoint centerDrawPos = GetDrawPos();

	// 128 is circle rad
	centerDrawPos.x = centerDrawPos.x + 128 * cannonSize - (128 * holeSize);
	centerDrawPos.y = centerDrawPos.y + 128 * cannonSize - (128 * holeSize);

	switch (renderState)
	{
	case 0:
		break;
	case 1:
		_app->renderer->AddTextureRenderQueue
		(renderObjects[0].texture, centerDrawPos, &holeSection, holeSize, 1, 0.6f, 0.0f, SDL_FLIP_NONE, { 200,200 });
		break;
	case 2:
	case 3:
	case 4:
		_app->renderer->AddTextureRenderQueue
		(renderObjects[0].texture, centerDrawPos, &holeSection, holeSize, 1, 0.6f, 0.0f, SDL_FLIP_NONE, { 200,200 });
		// Dibujar texturas
		for (int i = 0; i < MAX_GAMEOBJECT_TEXTURES; i++)
		{
			if (renderObjects[i].texture != nullptr)
			{
				if (pBody != nullptr && renderObjects[i].followPhysBody)
				{
					renderObjects[i].renderRect.x = GetDrawPos().x;
					renderObjects[i].renderRect.y = GetDrawPos().y;

					renderObjects[i].renderRect.x = renderObjects[i].renderRect.x + 128 * cannonSize - (128 * renderObjects[i].scale);
					// offset y = -10
					renderObjects[i].renderRect.y = renderObjects[i].renderRect.y + 128 * cannonSize - (128 * renderObjects[i].scale) - 10;

					if (renderObjects[i].rotationEnabled)
					{
						renderObjects[i].rotation = GetDegreeAngle();
					}
				}

				_app->renderer->AddTextureRenderQueue(renderObjects[i]);
			}
		}
		break;
	}
}

void Cannon::OnCollision(PhysBody* col)
{
	if (col->gameObject->CompareTag("Player") && renderState == 3)
	{
		renderState = 4;

		isPlayerIn = true;
	}
}

void Cannon::ShowCannon()
{
	renderState = 1;
}

void Cannon::Reset()
{
	renderObjects[0].rotation = 0;
	renderObjects[0].scale = 0.0f;
	renderState = 0;
	isPlayerIn = false;
}
