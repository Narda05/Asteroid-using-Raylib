#pragma once
#include "Constants.h"
#include <raylib.h>

#ifndef ROCK_H
#define ROCK_H

using namespace std;

class Rock {
public:
	// Variables
	// Position and speed
	Vector2 position;
	Vector2 speed;

	// Shape and color
	Color color;
	float size;
	int type;

	// Active boolean
	bool active = true;

	//Constructors
	Rock();
	Rock(int type, Vector2 position);

	//Functions
	void Update();
	void Draw();
};

#endif
