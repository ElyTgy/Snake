#include "Game.h"
#include "Snake.h"
#include "Scores.h"
#include <cctype>


Game::Game() : snake(), prevDir(snake.GetDir()), scores(), playing(true), highScore(0)
{
}

void Game::Draw(State::State s)
{
	snake.Draw(s);
	scores.Draw();
	snake.DrawScore();
}

void Game::run()
{
	do
	{
		playing = true;
		RestartGame();

		while (playing)
		{
			InitializeCurses(true);
			wait(200);

			Dir::Dir dir = InputEvent();
			if (dir == Dir::NONE)
			{
				dir = prevDir;
			}

			snake.Move(dir);
			scores.Update();


			if (snake.HasCollidedApple(scores))
			{
				snake.AddLength();
				snake.AddScore(scores.GetScoreValAtPos(snake.GetSnakeHeadPos()));
				scores.DeleteScoreAtPos(snake.GetSnakeHeadPos());
			}

			if (snake.HasCollidedSelf() || snake.HasCollidedWall())
			{
				playing = false;
			}

			prevDir = snake.GetDir();

			if (playing) { Draw(State::Alive); }
			else { Draw(State::Dead); }
		}
	
		wait(1000);
		ShowNewHighScore();

	} while (PlayAgain("Do you want to play again?(y/n)"));
	
	endwin();
}


bool Game::PlayAgain(const std::string prompt)
{
	reset_shell_mode();
	curs_set(true);
	nodelay(stdscr, false);

	mvprintw(screenHeight / 2, (screenWidth - prompt.length()) / 2, prompt.c_str());
	char input = getch();
	
	if (std::tolower(input) == 'y')
	{
		clear();
		wait(1000);
		return true;
	}
	return false;
}

void Game::ShowNewHighScore()
{
	clear();
	std::string prompt = "High Score: " + std::to_string(highScore);

	if(snake.GetPoints() > highScore)
	{
		highScore = snake.GetPoints();
		prompt = "New High Score: " + std::to_string(highScore);
	}

	mvprintw((screenHeight / 2) - 1, (screenWidth - prompt.length()) / 2, prompt.c_str());
}


void Game::RestartGame()
{
	snake = Snake();
	prevDir = Settings::snakeInfo::startDir;
}

Dir::Dir Game::InputEvent()
{
	Dir::Dir dir = Dir::NONE;
	int input = getch();

	if (input != ERR)
	{
		switch (input)
		{
		case KEY_DOWN:
			dir = Dir::down;
			break;
		case KEY_UP:
			dir = Dir::up;
			break;
		case KEY_RIGHT:
			dir = Dir::right;
			break;
		case KEY_LEFT:
			dir = Dir::left;
			break;
		}
	}
	return dir;
}
