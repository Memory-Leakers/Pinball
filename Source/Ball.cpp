#include "Ball.h"

Ball::Ball(SDL_Texture* texture, SDL_Texture* shadowTexture, std::string name, std::string tag)
{
	this->texture = texture;
	this->shadow = shadowTexture;
	this->name = name;
	this->tag = tag;
}


void Ball::PreUpdate()
{
	//pBody->body->GetFixtureList()[0].SetRestitution(0.25f);
}

void Ball::OnCollision(PhysBody* col)
{
	if (col->gameObject && col->gameObject->CompareTag("Boing"))
	{
		//pBody->body->GetFixtureList()[0].SetRestitution(1);
	}
    //Try boing
    /*int x, y;
    float angle;
    b2Vec2 velocity;
    b2Vec2 velocityInvertido;
    b2Vec2 normal;
    velocity = pBody->body->GetLinearVelocity();
    pBody->GetPosition(x, y);

    if (pBody->RayCast(x, y, velocity.x, velocity.y, normal.x, normal.y) == -1)
    {
        return;
    }

    _app->physics->DotProductAngle(normal, -velocity, angle);

    b2Vec2 vectorReflected;
    velocityInvertido = -velocity;

    vectorReflected.x = (velocityInvertido.x * cos(angle)) - (velocityInvertido.y * sin(angle));
    vectorReflected.y = (velocityInvertido.x * sin(angle)) + (velocityInvertido.y * cos(angle));

    bool wake = true;
    pBody->body->ApplyForceToCenter(vectorReflected, wake);*/

	printf("Col Ball");
}

