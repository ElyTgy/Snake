#pragma once
#include "Snake.h"
#include "Scores.h"
#include <string>


class Game
{
private:
	Snake snake;
	Scores scores;

	int highScore;
	bool playing;
	Dir::Dir prevDir;
	
	Dir::Dir InputEvent();
	bool PlayAgain(const std::string prompt);
	void ShowNewHighScore();
	void Draw(State::State playerState);
	void RestartGame();

public:
	void run();
	Game();
};