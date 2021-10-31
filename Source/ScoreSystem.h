#pragma once

#include "Application.h"

class ScoreSystem
{
private:

	ScoreSystem(Application* _app);
	~ScoreSystem();

	static ScoreSystem* sInstance;

	Application* _app;

	int currentScore = 0;
	int currentCombo = 1;
	int totalScore = 0;

	uint UIcurrentScore = 0;
	uint UIcurrentCombo = 0;
	uint UInextCombo = 0;

	int uiX = 0;
	int uiY = 0;

	bool changingCombo = false;
	bool resettingCombo = false;
	int nextCombo;

public:

	static ScoreSystem* Instance(Application* _app);
	static void Release();

	void Update();

	void AddScore(int score, iPoint pos = {-100, -100});
	void AddCombo(int combo);
	void ResetScore();
	void ResetCombo();

	int GetScore()
	{
		return currentScore;
	}

	int GetCombo()
	{
		return currentCombo;
	}

	void SetScore(int score)
	{
		currentScore = score;
	}
	
	void SetCombo(int combo)
	{
		currentCombo = combo;
	}

	int GetTotalScore()
	{
		return totalScore;
	}
	
	void SetTotalScore(int score)
	{
		totalScore = score;
	}
};

