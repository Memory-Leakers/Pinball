#include "CannonSensor.h"


CannonSensor::CannonSensor(SDL_Rect rect, int layer, std::string name, std::string tag, Application* _app) : GameObject(name, tag, _app)
{

	renderObjects[0].texture = _app->textures->Load("Assets/Images/Game/Cannons_sensor.png");
	renderObjects[0].section = new SDL_Rect({ 0, 0, 128, 128 });
	renderObjects[0].layer = 1;
	renderObjects[0].scale = 0.2f;

	pBody = _app->physics->CreateCircleSensor(iPoint(rect.x, rect.y), rect.w + offsetx_collider_sensor);
	pBody->gameObject = this;
}

void CannonSensor::OnCollision(PhysBody* col)
{
	printf("SensorCol");
	if (pBody->gameObject->CompareTag("SensorC1"))
	{
		renderObjects[0].section->x = 128;

		if (!isSensorOn1) _app->audio->PlayFx(7);

		isSensorOn1 = true;
	}
	if (pBody->gameObject->CompareTag("SensorC2"))
	{
		renderObjects[0].section->x = 128;

		if (!isSensorOn2) _app->audio->PlayFx(8);

		isSensorOn2 = true;
	}
	if(pBody->gameObject->CompareTag("SensorC3"))
	{
		renderObjects[0].section->x = 128;

		if (!isSensorOn3) _app->audio->PlayFx(9);

		isSensorOn3 = true;
	}
}

void CannonSensor::Reset()
{
	
	renderObjects[0].section->x = 0;
	
	isSensorOn1 = false;
	isSensorOn2 = false;
	isSensorOn3 = false;
	
}

void CannonSensor::PostUpdate()
{
	for (int i = 0; i < MAX_GAMEOBJECT_TEXTURES; i++)
	{
		if (renderObjects[i].texture != nullptr)
		{
			if (pBody != nullptr && renderObjects[i].followPhysBody)
			{
				renderObjects[i].renderRect.x = GetDrawPos().x;
				renderObjects[i].renderRect.y = GetDrawPos().y;

				if (renderObjects[i].rotationEnabled)
				{
					renderObjects[i].rotation = GetDegreeAngle();
				}
			}

			_app->renderer->AddTextureRenderQueue(renderObjects[i]);
		}
	}
}