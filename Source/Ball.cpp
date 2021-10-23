#include "Ball.h"

Ball::Ball(Ball& ball, b2Vec2 pos, bool getVelocity) : GameObject(ball.name, ball.tag, ball._app)
{
    //Crate Ball RenderObject
    renderObjects[0].texture = _app->textures->Load("Assets/Images/Game/Ball120.png");
    renderObjects[1].texture = _app->textures->Load("Assets/Images/Game/BallShadow120.png");

    renderObjects[0].scale = 0.2f;
    renderObjects[0].layer = 1;
    renderObjects[0].orderInLayer = 1.0f;

    renderObjects[1].scale = 0.2f;
    renderObjects[1].layer = 1;
    renderObjects[1].orderInLayer = 1.1f;
    renderObjects[1].rotationEnabled = false;

    //Create PhysBody
    pBody = _app->physics->CreateCircle(pos.x, pos.y, 12, this);
    pBody->body->SetBullet(true);
    pBody->body->GetFixtureList()[0].SetRestitution(0.3f);

    if (!getVelocity) return;

    pBody->body->SetLinearVelocity(ball.pBody->body->GetLinearVelocity());
    pBody->body->SetAngularVelocity(ball.pBody->body->GetAngularVelocity());

}

Ball::Ball(std::string name, std::string tag,Application* _app)
    :GameObject(name,tag,_app)
{
    //Crate Ball RenderObject
    renderObjects[0].texture = _app->textures->Load("Assets/Images/Game/Ball120.png") ;
    renderObjects[1].texture = _app->textures->Load("Assets/Images/Game/BallShadow120.png");

    renderObjects[0].scale = 0.2f;
    renderObjects[0].layer = 1;
    renderObjects[0].orderInLayer = 1.0f;

    renderObjects[1].scale = 0.2f;
    renderObjects[1].layer = 1;
    renderObjects[1].orderInLayer = 1.1f;
    renderObjects[1].rotationEnabled = false;

    //Create PhysBody
    pBody = _app->physics->CreateCircle(520, 780, 12, this);
    pBody->body->SetBullet(true);
    pBody->body->GetFixtureList()[0].SetRestitution(0.25f);

    //  Create instance of the Score System

    scoreInstance = ScoreSystem::Instance(_app);

}

void Ball::Start()
{
    
}

void Ball::PreUpdate()
{
	//pBody->body->GetFixtureList()[0].SetRestitution(0.25f);
}

void Ball::Update()
{
    if (_app->input->GetKey(SDL_SCANCODE_SPACE) == KEY_REPEAT)
    {
        impulseForce+= impulseForce >= 1200 ? 0 : 20;
        //printf("%d", impulseForce);
    }
    if (_app->input->GetKey(SDL_SCANCODE_SPACE) == KEY_UP)
    {
        if (initialSpring && abs(pBody->body->GetLinearVelocity().y) <= 0.2f)
        {
            pBody->body->ApplyForceToCenter(b2Vec2(0, impulseForce), true);
            initialSpring = false;
        }
        impulseForce = 200;  
    }
}

void Ball::PostUpdate()
{
   /* int x, y;
    velocity = pBody->body->GetLinearVelocity();
    velocity.Normalize();
    printf("%f,%f\n", velocity.x, velocity.y)
    pBody->GetCenterPosition(x, y);;
    _app->renderer->DrawLine(x, y, METERS_TO_PIXELS(velocity.x) + x, METERS_TO_PIXELS(velocity.y) + y, 255, 0, 0);*/

    GameObject::PostUpdate();
}

void Ball::OnCollision(PhysBody* col)
{
    if (col->gameObject == nullptr) return;

    if (col->gameObject->name == "SensorBS")
    {
        initialSpring = true;
    }

    if (col->gameObject->name == "SensorT")
    {
        isTeleporting = true;
    }

    if (col->gameObject->tag == "Boing")
    {
        scoreInstance->AddScore(100);
    }


	/*if (col->gameObject && col->gameObject->CompareTag("Boing"))
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
    pBody->body->ApplyForceToCenter(vectorReflected, wake);*/
}


