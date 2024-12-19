#pragma once
#include "Projectile.h"
#include "Constants.h"
#include <raylib.h>
#include <raymath.h>
#include <vector>

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player {
public:
	//Variable
	// Position and rotation
	Vector2 position;
	float rotation;

	// Shape and color
	Vector2 vertices[3];
	Color color;

	// Shooting
	float fireRate = 0.2f;
	double lastShotTime;

	// Lives
	int lives = 3;

	//Constructor
	Player();

	//Functions
	void Update();
	void Draw();
};

#endif
