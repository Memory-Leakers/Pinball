#pragma once
#include "Scene.h"
class Ball;
class Flipper;
class Boing;
class PolygonBoing;
class Sensor;
class KeySensor;
class Boss;
class Spring;
class PhysLayerL;
class PhysLayerR;
class ScoreSystem;
class CoinsManager;
class Cannon;
class CannonSensor;
class RectObstacle;

#define BOINGCOUNT 6
#define TRIBOINGCOUNT 4
#define BOSSBOINGCOUNT 5

class SceneGame : public Scene
{
public:
    SceneGame(Application* app) :Scene(app)
    {

    }

    bool Start() override;

    bool PreUpdate() override;

    bool Update() override;

    bool PostUpdate() override;

    bool CleanUp() override;

    void CreateMap();

    void SecondLayer();

    void DeleteMap();

    void GameOver();

    void WinGame();

public:

    uint uis[3];

    Ball* player;

    int playerLifes = 3;

    Boing* boing[BOINGCOUNT];

    PolygonBoing* triBoing[TRIBOINGCOUNT];

    PolygonBoing* bossBoing[BOSSBOINGCOUNT];

    Flipper* flipper_right;
    Flipper* flipper_left;

    Sensor* deathSensor;

    Boss* boss;

    Spring* spring;
    Spring* springR;
    Spring* springL;

    PhysLayerL* physLayer;
    PhysLayerR* physLayer2;

    CoinsManager* coinsManager;

    Cannon* cannon;

    RectObstacle* rectSaveLifeR;
    RectObstacle* rectSaveLifeL;
    Sensor* sBallSpring;
    Sensor* sBallSpringR;
    Sensor* sBallSpringL;
    Sensor* sTeleportIn;
    Sensor* enterPhysLayerL;
    Sensor* exitPhysLayerUpL;
    Sensor* exitPhysLayerL;
    Sensor* exitPhysLayerUpR;
    Sensor* enterPhysLayerR;
    Sensor* exitPhysLayerR;
    KeySensor* rightKey1;
    KeySensor* rightKey2;
    CannonSensor* Cannon1;
    CannonSensor* Cannon2;
    CannonSensor* Cannon3;
    
    // background
    SDL_Texture* bg; 
    // foreground
    SDL_Texture* fg;

    SDL_Texture* gameover;
    SDL_Texture* lifes;
    SDL_Texture* win;
    
    RenderObject* lifeIcons[3];

    iPoint teleportPosition;    //Determines where the player teleports when it hits the teleportIn Sensor

    ScoreSystem* scoreSystem;

    //Map
    PhysBody* bg1;
    PhysBody* bg2;
    PhysBody* bg3;
    PhysBody* ball;
    PhysBody* flipper1;
    PhysBody* flipper2;
    PhysBody* flWallRight;
    PhysBody* flWallLeft;
    PhysBody* doorRight;

    PhysBody* smDivider1M;
    PhysBody* smDivider2M;

    PhysBody* pm;
    PhysBody* treeWall;

    uint teleportSfx;
    uint cannonInSfx;
    uint cannonShootSfx;

    bool isGameOver = false;
    bool isWin = false;
    bool IsCannonShown = false;

    int winImageY = 900;
};
