#include "Snake.h"
#include <string>
#include "Utils.h"
#include "Scores.h"



Snake::Snake() : m_currentHeadPos(Settings::snakeInfo::startPos),
m_score(0),
m_isAlive(true),
m_currentDir(Settings::snakeInfo::startDir),
m_snake({ {m_currentHeadPos}, {m_currentHeadPos.x + 1, m_currentHeadPos.y}
,{ m_currentHeadPos.x + 2, m_currentHeadPos.y }, {m_currentHeadPos.x+3, m_currentHeadPos.y} })
{}

const Pos& Snake::GetSnakeHeadPos() const 
{ 
	return m_snake.front(); 
}

void Snake::Draw(State::State state) const
{
	char head = Settings::snakeInfo::liveHeadChar;
	char body = Settings::snakeInfo::liveChar;

	if (state == State::Dead) { head = Settings::snakeInfo::deadHeadChar; body = Settings::snakeInfo::deadChar; } 

	for (std::list<Pos>::const_iterator iter = m_snake.begin(); iter != m_snake.end(); ++iter)
	{
		char c = body;
		if (m_currentHeadPos == (*iter)) { c = head; }
		DrawChar((*iter).x, (*iter).y, c);
	}

	refresh();
}

void Snake::Move(Dir::Dir newMoveDir)
{
	if (m_isAlive)
	{
		m_currentDir = newMoveDir;
		switch (m_currentDir)
		{
		case Dir::right:
			m_currentHeadPos = { m_currentHeadPos.x + 1, m_currentHeadPos.y };
			break;
		case Dir::left:
			m_currentHeadPos = { m_currentHeadPos.x - 1, m_currentHeadPos.y };
			break;
		case Dir::up:
			m_currentHeadPos = { m_currentHeadPos.x, m_currentHeadPos.y - 1 };
			break;
		case Dir::down:
			m_currentHeadPos = { m_currentHeadPos.x, m_currentHeadPos.y + 1 };
			break;
		}
		
		mvprintw(m_snake.back().y, m_snake.back().x, " ");
		m_snake.pop_back();
		m_snake.push_front(m_currentHeadPos);
	}
}

void Snake::AddScore(int score)
{
	m_score += score;
}

void Snake::AddLength()
{
	auto elementToAddBefore = ++m_snake.begin();
	Pos pos;
	switch (m_currentDir)
	{
	case Dir::right:
		pos = { m_currentHeadPos.x - 1, m_currentHeadPos.y };
		break;
	case Dir::left:
		pos = { m_currentHeadPos.x + 1, m_currentHeadPos.y };
		break;
	case Dir::up:
		pos = { m_currentHeadPos.x, m_currentHeadPos.y + 1 };
		break;
	case Dir::down:
		pos = { m_currentHeadPos.x, m_currentHeadPos.y - 1 };
		break;
	}
	
	m_snake.insert(elementToAddBefore, pos);
}

bool Snake::HasCollidedSelf()
{
	std::list<Pos>::const_iterator iter;
	iter = ++m_snake.begin();

	for (iter = ++m_snake.begin(); iter != m_snake.end(); ++iter)
	{
		if (m_currentHeadPos == (*iter))
		{
			return true;;
		}
	}
	return false;
}

bool Snake::HasCollidedWall()
{
	if (m_currentHeadPos.x < 0 || m_currentHeadPos.x > screenWidth
		|| m_currentHeadPos.y < 0 || m_currentHeadPos.y > screenHeight)
	{
		return true;
		const char* c = "DEAD";
		mvprintw(0, 0, c);
	}
	return false;
}

bool Snake::HasCollidedApple(const Scores& scores) const
{
	for (const auto score : scores.GetScores())
	{
		if (score.pos == m_currentHeadPos)
		{
			return true;
		}
	}
	return false;
}

void Snake::DrawScore()const
{
	mvprintw(0, 0, std::to_string(m_score).c_str());
}