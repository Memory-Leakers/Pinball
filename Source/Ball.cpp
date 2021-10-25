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

    //  Create instance of the Score System

    scoreInstance = ScoreSystem::Instance(_app);

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
    b2Vec2 velocity = pBody->body->GetLinearVelocity();
    int maxVelocity = 20;

    if (velocity.x > maxVelocity)
    {
        velocity.x = maxVelocity;
    }
    if (velocity.y > maxVelocity)
    {
        velocity.y = maxVelocity;
    }
    if (velocity.x < -maxVelocity)
    {
        velocity.x = -maxVelocity;
    }
    if (velocity.y < -maxVelocity)
    {
        velocity.y = -maxVelocity;
    }
    if (abs(velocity.x) > maxVelocity || abs(velocity.y) > maxVelocity)
    {
        printf("Velocidad por encima de limite !!!!");
    }

    pBody->body->SetLinearVelocity(velocity);
    
    }

void Ball::Update()
{
    if (_app->input->GetKey(SDL_SCANCODE_SPACE) == KEY_REPEAT)
    {
        impulseForce+= impulseForce >= 1200 ? 0 : 20;
        //printf("%d", impulseForce);
    }
    else if (_app->input->GetKey(SDL_SCANCODE_SPACE) == KEY_UP)
    {
        if (initialSpring && abs(pBody->body->GetLinearVelocity().y) <= 0.2f)
        {
            pBody->body->ApplyForceToCenter(b2Vec2(0, impulseForce), true);
            initialSpring = false;
        }
        impulseForce = 200;
    }

    if (_app->input->GetKey(SDL_SCANCODE_F) == KEY_DOWN)
    {
        b2Vec2 v = pBody->body->GetLinearVelocity();

        if (v.x == 0 && v.y == 0)
        {
            float randomFloat = -10 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (10 + 10)));

            pBody->body->ApplyForceToCenter(b2Vec2(randomFloat, 20), true);
        }
    }

    if (topLayer)
    {
        renderObjects[0].layer = 3;
        renderObjects[1].layer = 3;
    }
    else 
    {
        renderObjects[0].layer = 1;
        renderObjects[1].layer = 1;
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

    if (col->gameObject->tag == "Boing" || col->gameObject->tag == "PolygonBoing")
    {
        scoreInstance->AddScore(100);
    }

    if (col->gameObject->name == "DeathSensor")
    {
        isDeath = true;
    }

    if (col->gameObject->tag == "Coin")
    {
        scoreInstance->AddCombo(1);
    }

    //SECOND LAYERS
    if (col->gameObject->name == "ChangeLayerSensor" || col->gameObject->name == "ChangeLayerSensorUnlockedDoor") 
    {//ENTER LEFT OR RIGHT
        topLayer = !topLayer;
    }

    if (topLayer == true && col->gameObject->name == "ChangeLayerSensorSecondLevel") //EXIT LEFT and RIGHT
    {
        topLayer = !topLayer;
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
