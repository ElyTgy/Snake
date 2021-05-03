#include "Scores.h"


Score::Score() : shape(Settings::scoreInfo::shape), value(Settings::scoreInfo::value)
{
	int xPos = GenerateRandNumberInRange(0, screenWidth);
	int yPos = GenerateRandNumberInRange(0, screenHeight);

	pos = { xPos, yPos };
}

void Score::operator=(const Score& s) 
{
	pos.x = s.pos.x;
	pos.y = s.pos.y;
	value = s.value;
	shape = s.shape;
}


Scores::Scores()
{
	int numOnScreen = GenerateRandNumberInRange(1, Settings::scoreInfo::maxNumOnScreen);

	for (int i = 0; i < numOnScreen; ++i)
	{
		Score score;
		m_scores.push_back(score);
	}
}

void Scores::Draw()
{
	for (auto score : m_scores)
	{
		DrawChar(score.pos.x, score.pos.y, score.shape);
	}
}

void Scores::Update()
{
	if (m_scores.size() < Settings::scoreInfo::regenerateNum)
	{
		int newNumMax = Settings::scoreInfo::maxNumOnScreen - Settings::scoreInfo::regenerateNum;
		int addToScreenNum = GenerateRandNumberInRange(1, newNumMax);

		for (int i = 0; i < addToScreenNum; ++i)
		{
			Score newScore;
			m_scores.push_back(newScore);
		}
	}
}

int Scores::GetScoreValAtPos(const Pos& pos)
{
	for (auto score : m_scores)
	{
		if (score.pos == pos)
		{
			return score.value;
		}
	}
	assert("reached this point :(");
}

void Scores::DeleteScoreAtPos(const Pos& deletionPos)
{
	DrawChar(deletionPos.x, deletionPos.y, ' ');
	
	for (std::vector<Score>::const_iterator iter = m_scores.begin(); iter != m_scores.end(); ++iter)
	{
		if ((*iter).pos == deletionPos)
		{
			m_scores.erase(iter);
			return;
		}
	}
	assert("yo why are u here");
}

const std::vector<Score>& Scores::GetScores()const 
{ 
	return m_scores; 
};