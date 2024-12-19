#pragma once
#include "Constants.h"
#include "Scoreboard.h"
#include <raylib.h>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

#ifndef UI_H
#define UI_H

using namespace std;

class UI {
public:
	// Scoreboard
	Scoreboard scoreboard;

	// Functions
	void StartScreen();
	void Score(int score);
	void Lives(int lives);
	void GameOver();
	void Draw(int score, int lives);
};

#endif
