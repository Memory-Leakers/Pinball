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
	UIcurrentCombo = app->ui->CreateUI(1, 500, 70, 0.5f);
}

ScoreSystem::~ScoreSystem()
{
}

void ScoreSystem::Update()
{
	if (changingCombo)
	{
		//Move combo Up
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

	_app->ui->uiArray[UIcurrentCombo]->ChangeUI(currentCombo);
}

void ScoreSystem::ResetScore()
{
	currentScore = 0;

	_app->ui->uiArray[UIcurrentScore]->ChangeUI(currentScore);
}

void ScoreSystem::ResetCombo()
{
	currentCombo = 1;

	_app->ui->uiArray[UIcurrentCombo]->ChangeUI(currentCombo);
}
