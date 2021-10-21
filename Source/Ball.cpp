#include "Ball.h"

Ball::Ball(SDL_Texture* texture, SDL_Texture* shadowTexture, std::string name, std::string tag,Application* _app)
    :GameObject(texture,name,tag,_app)
{
	this->shadow = shadowTexture;
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
    int x, y;
    float angle;
    
    
    pBody->GetPosition(x, y);

    if (pBody->RayCast(x, y, velocity.x, velocity.y, normal.x, normal.y) == -1)
    {
        return;
    }
    velocityInvertido = -velocity;
    _app->physics->DotProductAngle(normal, velocityInvertido, angle);

    b2Vec2 vectorReflected;
    

    vectorReflected.x = (velocityInvertido.x * cos(angle*2)) - (velocityInvertido.y * sin(angle*2));
    vectorReflected.y = (velocityInvertido.x * sin(angle*2)) + (velocityInvertido.y * cos(angle*2));

    bool wake = true;
    pBody->body->ApplyForceToCenter(vectorReflected, wake);

	printf("Col Ball");
}

void Ball::PostUpdate()
{
    int x, y;
    velocity = pBody->body->GetLinearVelocity();
    velocity.Normalize();
    printf("%f,%f\n", velocity.x, velocity.y);
    pBody->GetCenterPosition(x, y);
    _app->renderer->DrawLine(x, y,METERS_TO_PIXELS(velocity.x)+x, METERS_TO_PIXELS(velocity.y)+ y , 255, 0, 0);
}

