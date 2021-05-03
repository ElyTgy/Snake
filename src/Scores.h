#pragma once
#include "Utils.h"
#include <algorithm>
#include <cassert>
#include <vector>

struct Score
{
	Score();
	void operator=(const Score& s);
	char shape;
	int value;
	Pos pos;
};

class Scores
{
public:
	Scores();
	void Draw();
	void Update();
	int GetScoreValAtPos(const Pos& pos);
	void DeleteScoreAtPos(const Pos& deletionPos);
	const std::vector<Score>& GetScores()const;

private:
	std::vector<Score>m_scores;
};