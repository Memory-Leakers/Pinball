#include "ScoreSystem.h"

ScoreSystem* ScoreSystem::sInstance = NULL;

ScoreSystem* ScoreSystem::Instance(Application* _app)
{
	if (sInstance == NULL)
	{
		sInstance = new ScoreSystem(_app);
	}

	return sInstance;
}

void ScoreSystem::Release()
{
	if (sInstance != NULL)
	{
		delete sInstance;
		sInstance = nullptr;
	}
}


ScoreSystem::ScoreSystem(Application* app)
{
	this->_app = app;

	uiX = 300;
	uiY = 125;

	UIcurrentScore = app->ui->CreateUI(0, uiX, uiY, 0.4f);
	UIcurrentCombo = app->ui->CreateUI(1, 500, 70, 0.5f, 0);
	UInextCombo = app->ui->CreateUI(1, 500, 110, 0.5f, 0);
}

ScoreSystem::~ScoreSystem()
{
}

void ScoreSystem::Update()
{
	_app->ui->uiArray[UIcurrentCombo]->x = currentCombo >= 10 ? 495 : 500;
	_app->ui->uiArray[UInextCombo]->x = nextCombo >= 10 ? 495 : 500;

	if (changingCombo)
	{
		if (_app->ui->uiArray[UIcurrentCombo]->y > 30)
		{
			_app->ui->uiArray[UIcurrentCombo]->y -= 16;

			_app->ui->uiArray[UInextCombo]->y -= 16;

			//	Si nos hemos pasado, lo asignamos a 30 / 70. Si no continuamos
			_app->ui->uiArray[UIcurrentCombo]->y = _app->ui->uiArray[UIcurrentCombo]->y < 30 ? 30 : _app->ui->uiArray[UIcurrentCombo]->y;

			_app->ui->uiArray[UInextCombo]->y = _app->ui->uiArray[UInextCombo]->y < 70 ? 70 : _app->ui->uiArray[UInextCombo]->y;
		}
		else 
		{
			SetCombo(nextCombo);
			_app->ui->uiArray[UIcurrentCombo]->y = _app->ui->uiArray[UInextCombo]->y;
			_app->ui->uiArray[UIcurrentCombo]->ChangeUI(currentCombo);
			_app->ui->uiArray[UInextCombo]->y = 110;
			changingCombo = false;
		}
	}
	if (resettingCombo)
	{
		if (_app->ui->uiArray[UIcurrentCombo]->y < 110 || _app->ui->uiArray[UInextCombo]->y < 70)
		{
			_app->ui->uiArray[UIcurrentCombo]->y += 16;

			_app->ui->uiArray[UInextCombo]->y += 16;

			//	Si nos hemos pasado, lo asignamos a 110 / 70. Si no continuamos
			_app->ui->uiArray[UIcurrentCombo]->y = _app->ui->uiArray[UIcurrentCombo]->y > 110 ? 110 : _app->ui->uiArray[UIcurrentCombo]->y;

			_app->ui->uiArray[UInextCombo]->y = _app->ui->uiArray[UInextCombo]->y > 70 ? 70 : _app->ui->uiArray[UInextCombo]->y;
		}
		else
		{
			SetCombo(nextCombo);
			_app->ui->uiArray[UIcurrentCombo]->y = _app->ui->uiArray[UInextCombo]->y;
			_app->ui->uiArray[UIcurrentCombo]->ChangeUI(currentCombo);
			_app->ui->uiArray[UInextCombo]->y = 110;
			resettingCombo = false;
		}
	}
}

void ScoreSystem::AddScore(int score)
{
	currentScore += currentCombo * score;

	_app->ui->uiArray[UIcurrentScore]->ChangeUI(currentScore);
}

void ScoreSystem::AddCombo(int combo)
{
	nextCombo = currentCombo + combo;

	_app->ui->uiArray[UInextCombo]->ChangeUI(nextCombo);

	changingCombo = true;
}

void ScoreSystem::ResetScore()
{
	currentScore = 0;

	_app->ui->uiArray[UIcurrentScore]->ChangeUI(currentScore);
}

void ScoreSystem::ResetCombo()
{
	nextCombo = 1;

	_app->ui->uiArray[UInextCombo]->ChangeUI(nextCombo);
	_app->ui->uiArray[UInextCombo]->y = 30;

	resettingCombo = true;
}
