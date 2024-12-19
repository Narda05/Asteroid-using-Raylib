#pragma once
#include "Constants.h"
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

#ifndef SCOREBOARD_H
#define SCOREBOARD_H

using namespace std;

class Scoreboard {
public:
	// Functions
	vector<pair<int, string>> GetTopScores();
	void Update(string playerName, int newScore);
};

#endif
