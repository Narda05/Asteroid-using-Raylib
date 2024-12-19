#include "Rock.h"
#include <raylib.h>
#include <ctime>
#include <iostream>

using namespace std;

Rock::Rock() {
    // Generate a Big, Medium or Small rock
    type = GetRandomValue(1, 3);

    // Generate random positions
    float posx, posy;

    // Validate that the random generated number is within the specified range
    do {
        posx = GetRandomValue(PLAY_AREA_LEFT_LIMIT, PLAY_AREA_RIGHT_LIMIT);
    } while (posx > PLAY_AREA_LEFT_LIMIT + SPAWN_RANGE and posx < PLAY_AREA_RIGHT_LIMIT - SPAWN_RANGE);

    // Validate that the random generated number is within the specified range
    do {
        posy = GetRandomValue(PLAY_AREA_DOWN_LIMIT, PLAY_AREA_UP_LIMIT);
    } while (posy > PLAY_AREA_DOWN_LIMIT + SPAWN_RANGE and posy < PLAY_AREA_UP_LIMIT - SPAWN_RANGE);

    // Spawn new rock at randomly generated position
    position = { posx, posy };

    // Variable to store the new rock speed
    float rockSpeed;

    // Assign specified attributes depending of the generated type
    switch (type) {
        // BIG
    case 1:
        rockSpeed = BIG_ROCK_SPEED;
        color = BIG_ROCK_COLOR;
        size = BIG_ROCK_SIZE;
        break;
        // MEDIUM
    case 2:
        rockSpeed = MEDIUM_ROCK_SPEED;
        color = MEDIUM_ROCK_COLOR;
        size = MEDIUM_ROCK_SIZE;
        break;
        // SMALL
    case 3:
        rockSpeed = SMALL_ROCK_SPEED;
        color = SMALL_ROCK_COLOR;
        size = SMALL_ROCK_SIZE;
        break;
    }

    float speedx;

    // Generate a random percentage for the x speed component
    do {
        speedx = (float)GetRandomValue(0, 100) / 100;
    } while (speedx == 0);

    // Assign speed with the corresponding x and y component percentages
    speed = { rockSpeed * speedx, rockSpeed * (1.0f - speedx) };
}

// Spawn a rock of a specific type in a specific position
Rock::Rock(int type, Vector2 position) : type(type), position(position) {
    float rockSpeed;

    // Assign specified attributes depending of the specified type
    switch (type) {
        // BIG
    case 1:
        rockSpeed = BIG_ROCK_SPEED;
        color = BIG_ROCK_COLOR;
        size = BIG_ROCK_SIZE;
        break;
        // MEDIUM
    case 2:
        rockSpeed = MEDIUM_ROCK_SPEED;
        color = MEDIUM_ROCK_COLOR;
        size = MEDIUM_ROCK_SIZE;
        break;
        // SMALL
    case 3:
        rockSpeed = SMALL_ROCK_SPEED;
        color = SMALL_ROCK_COLOR;
        size = SMALL_ROCK_SIZE;
        break;
    }

    float speedx;

    // Generate a random percentage for the x speed component
    do {
        speedx = (float)GetRandomValue(0, 100) / 100;
    } while (speedx == 0);

    // Assign speed with the corresponding x and y component percentages
    speed = { rockSpeed * speedx, rockSpeed * (1.0f - speedx) };
}

void Rock::Update() {
    // If the current object is not active, we ignore it
    if (not active) return;

    // Update position based on set speed
    position.x += speed.x * GetFrameTime();
    position.y += speed.y * GetFrameTime();

    //Circles play area 
    if (position.x < PLAY_AREA_LEFT_LIMIT) {
        position.x = PLAY_AREA_RIGHT_LIMIT; // Spanws back at the right side
    }
    else if (position.x > PLAY_AREA_RIGHT_LIMIT) {
        position.x = PLAY_AREA_LEFT_LIMIT; // Spawns back at the left side
    }

    if (position.y < PLAY_AREA_DOWN_LIMIT) {
        position.y = PLAY_AREA_UP_LIMIT; // Spawns back at the upper side
    }
    else if (position.y > PLAY_AREA_UP_LIMIT) {
        position.y = PLAY_AREA_DOWN_LIMIT; // Spawns back at the lower side
    }
}

void Rock::Draw() {
    // If the current object is not active, we ignore it
    if (not active) return;

    // Draw the object
    DrawCircleLines(position.x, position.y, size, color);
}
