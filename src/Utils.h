#pragma once
#include <stdint.h>
#include <string>
#include "curses.h"
#include <thread>
#include <chrono>


static constexpr unsigned int screenWidth = 119;
static constexpr unsigned int screenHeight = 29;

namespace Dir
{
	enum Dir
	{
		up = 0,
		right,
		down,
		left,
		NONE
	};
}

namespace State
{
	enum State
	{
		Alive = 0,
		Dead
	};
}

struct Pos
{
	int32_t x, y;
	bool operator==(const Pos& pod) const;
};

namespace Settings
{
	namespace snakeInfo
	{
		constexpr char liveChar = 'o';
		constexpr char liveHeadChar = '@';
		constexpr char deadChar = '+';
		constexpr char deadHeadChar = '*';

		constexpr Dir::Dir startDir = Dir::left;
		constexpr Pos startPos = { screenWidth / 2,screenHeight / 2 };
	}
	
	namespace scoreInfo
	{
		constexpr char shape = '#';
		constexpr int value = 20;
		constexpr int maxNumOnScreen = 7;
		constexpr int regenerateNum = 3; //number at which it starts making Scores again
	}
}

void wait(long long int tms);
void InitializeCurses(bool noDelay);
int GenerateRandNumberInRange(int minim = 0, int maxim = 100);
void DrawChar(int x, int y, char character);