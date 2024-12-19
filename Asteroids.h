#pragma once
#include "Player.h"
#include "Rock.h"
#include <raylib.h>
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include "UI.h"
#include "Projectile.h"
#include "Constants.h"

#ifndef ASTEROIDS_H
#define ASTEROIDS_H

using namespace std;

class Asteroids {
public:
	//Variables
	bool startGame = false;
	double startTime;
	bool gameOver = false;
	int totalRockCount = 0;
	int score = 0;

	//Objects
	Scoreboard scoreboard;
	UI ui;
	Player player;
	vector<Rock> rocks;
	vector<Projectile> projectiles;

	//Functions
	void Main();
	void Start();
	void Update();
	void Draw();
	void Interaction();
	void Restart();
	bool CheckCollision(Vector2 pos1, float radius1, Vector2 pos2, float radius2);
	void CheckCollisions();
};

#endif
