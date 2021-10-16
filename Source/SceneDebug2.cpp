#include "SceneDebug2.h"

SceneDebug2::SceneDebug2(Application* app) : Scene(app)
{
}

bool SceneDebug2::Start()
{
	uis[0] = _app->ui->CreateUI(currentScore, 0, 0);
	uis[1] = _app->ui->CreateUI(2340, 0, 200);
	uis[2] = _app->ui->CreateUI(98320, 0, 400);

	return true;
}

bool SceneDebug2::Update()
{
	if (_app->input->GetKey(SDL_SCANCODE_Q) == KEY_DOWN)
	{
		currentScore++;
		_app->ui->uiArray[uis[0]]->ChangeUI(currentScore);
	}
	return true;
}

bool SceneDebug2::PostUpdate()
{
	return true;
}

bool SceneDebug2::CleanUp()
{
	_app->ui->CleanUp();
	return true;
}
