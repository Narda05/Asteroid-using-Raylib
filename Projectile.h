#pragma once
#include <raylib.h>
#include <raymath.h>

#ifndef PROJECTILE_H
#define PROJECTILE_H

using namespace std;

#define PROJECTILE_SPEED 500.0f
#define PROJECTILE_SIZE 10.0f
#define PROJECTILE_COLOR WHITE

class Projectile {
public:
	// Variables
	// Position, direction and speed
	Vector2 position;
	Vector2 direction;
	float speed;

	bool active = true;

	// Constructor
	Projectile();
	Projectile(Vector2 playerPosition, float playerRotation);

	// Functions
	void Update();
	void Draw();
};

// Functions
#endif
#pragma once
