#include "SceneMainMenu.h"

SceneMainMenu::SceneMainMenu(Application* app) : Scene(app)
{

}


bool SceneMainMenu::Start()
{
    SDL_Texture* mainMenu = _app->textures->Load("Assets/Images/Game/MainMenu.png");
    SDL_Texture* arrow = _app->textures->Load("Assets/Images/Game/MenuArrow.png");

    arrowPos = { 107, 342 };

    sceneTextures.add(mainMenu);
    sceneTextures.add(arrow);

    return true;
}

bool SceneMainMenu::Update()
{
    if (_app->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN || _app->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN)
    {
        arrowPos.y = arrowPos.y == 642 ? 342 : arrowPos.y + 150;
    }
    if (_app->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN || _app->input->GetKey(SDL_SCANCODE_W) == KEY_DOWN)
    {
        arrowPos.y = arrowPos.y == 342 ? 642 : arrowPos.y - 150;
    }

    if (_app->input->GetKey(SDL_SCANCODE_RETURN) == KEY_DOWN || _app->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)
    {
        SelectDifficulty();
    }

    return false;
}

bool SceneMainMenu::PostUpdate()
{
    _app->renderer->AddTextureRenderQueue(sceneTextures[0], { 0,0,});
    _app->renderer->AddTextureRenderQueue(sceneTextures[1], arrowPos, nullptr, 1, 1 );

    return false;
}

bool SceneMainMenu::CleanUp()
{
    return false;
}

void SceneMainMenu::SelectDifficulty()
{
    _app->scene->currentDifficulty = arrowPos.y == 342 ? 1 : arrowPos.y == 492 ? 2 : arrowPos.y == 642 ? 3 : 1;

    _app->scene->ChangeCurrentScene(0, 0);

}
