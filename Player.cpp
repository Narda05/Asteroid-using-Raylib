#pragma once
#include "Player.h"
#include <raylib.h>
#include <raymath.h>
#include <cmath>


// Create the instance
Player::Player() {
    position = { 0.0f, 0.0f };
    rotation = 0.0f;
    color = PLAYER_COLOR;
    lastShotTime = GetTime();
}

void Player::Update() {
    // Get the cursor position
    Vector2 mousePosition = GetMousePosition();

    // Stop updating the player's position if it's within some range of the cursor
    if (abs(mousePosition.x - position.x) <= CURSOR_RANGE and
        abs(mousePosition.y - position.y) <= CURSOR_RANGE)
        return;

    // Get the new rotation of the player based on it's position and the position of the cursor
    rotation = atan2(mousePosition.y - position.y,
        mousePosition.x - position.x);

    // Get the new direction of the player, normalizing the vector to get values from [-1, 1]
    Vector2 direction = Vector2Normalize({ mousePosition.x - position.x,
                                          mousePosition.y - position.y });

    // Update the player's position based on the direction and speed
    position.x += direction.x * SPEED * GetFrameTime();
    position.y += direction.y * SPEED * GetFrameTime();
}

void Player::Draw() {
    // Generate the three vertices of the player shape based on it's rotation
    for (int i = 0; i < 3; i++) {
        float angle = rotation + i * (2.0f * PI / 3.0f);
        vertices[i] = {
          position.x + SIDE_LENGTH * cos(angle),
          position.y + SIDE_LENGTH * sin(angle)
        };
    }

    // Draw the player
    DrawTriangleLines(vertices[0], vertices[1], vertices[2], color);
}
