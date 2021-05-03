#include "Utils.h"
#include <string>
#include <random>


bool Pos::operator==(const Pos& pod) const
{
	if (x == pod.x && y == pod.y)
	{
		return true;
	}
	return false;
}

void InitializeCurses(bool noDelay)
{
	initscr();
	noecho();
	curs_set(false);
	nodelay(stdscr, noDelay);
	keypad(stdscr, true);
}

void DrawChar(int x, int y, char character)
{
	std::string str(1, character);
	const char* c = str.c_str();
	mvprintw(y, x, c);
}

void wait(long long int tms)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(tms));
}

///Generates Random number from minim to maxim
///Includes the numbers passed in
int GenerateRandNumberInRange(int minim, int maxim)
{
	const int range_from = minim;
	const int range_to = maxim;
	std::random_device                  rand_dev;
	std::mt19937                        generator(rand_dev());
	std::uniform_int_distribution<int>  distr(range_from, range_to);

	return distr(generator);
}
