#pragma once
#include <windows.h>
#include <stdint.h>
#include <list>
#include "Utils.h"

class Scores;

class Snake
{
public:
	Snake();
	const Pos& GetSnakeHeadPos() const;
	const int GetPoints()const { return  m_score; }
	void Draw(State::State state) const;
	void DrawScore()const;
	void Move(Dir::Dir moveDir);
	void AddLength();
	bool HasCollidedApple(const Scores& score) const;
	inline bool IsAlive() const { return m_isAlive; };
	inline void SetDir(Dir::Dir dir) { m_currentDir = dir; }
	inline Dir::Dir GetDir() const { return m_currentDir; }
	bool HasCollidedSelf();
	bool HasCollidedWall();
	void AddScore(int score);
private:

	Pos m_currentHeadPos;
	Dir::Dir m_currentDir;
	bool m_isAlive;
	int m_score;

	std::list<Pos> m_snake;

};