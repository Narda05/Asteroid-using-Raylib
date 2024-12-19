#include "Asteroids.h"
#include "Player.h"
#include <raylib.h>
#include <raymath.h>
#include <cmath>
#include <iostream>

using namespace std;

// Main game logic
void Asteroids::Main() {
    // Get the random seed for number generation
    SetRandomSeed(time(0));

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Asteroids");
    SetTargetFPS(60);

    Start();

    while (!WindowShouldClose()) {
        Update();

        BeginDrawing();
        ClearBackground(BLACK);

        Draw();

        EndDrawing();
    }

    CloseWindow();
}

// Initialize objects and lists
void Asteroids::Start() {
    player.position = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
    player.lives = 3;
    totalRockCount = 0;
    score = 0;
    rocks.clear();
    projectiles.clear();
}

// Restart the game to initial options
void Asteroids::Restart() {
    Start();
    gameOver = false;
}

// Update game objects
void Asteroids::Update() {
    // If game hasn't started
    if (not startGame) {
        Interaction();
        return;
    }

    // Check for collisions between all active objects
    CheckCollisions();

    // If game is over
    if (gameOver) {
        Interaction();
        return;
    }

    // Bounce player
    if (player.position.y >= PLAY_AREA_UP_LIMIT) {
        player.position.y = PLAY_AREA_DOWN_LIMIT;
    }
    else if (player.position.y <= PLAY_AREA_DOWN_LIMIT) {
        player.position.y = PLAY_AREA_UP_LIMIT;
    }

    if (player.position.x >= PLAY_AREA_RIGHT_LIMIT) {
        player.position.x = PLAY_AREA_LEFT_LIMIT;
    }
    else if (player.position.x <= PLAY_AREA_LEFT_LIMIT) {
        player.position.x = PLAY_AREA_RIGHT_LIMIT;
    }

    if (totalRockCount < MAX_ROCKS) {
        rocks.push_back(Rock());
        totalRockCount++;
    }

    // Update player
    player.Update();

    // Update all active rock elements
    for (Rock& r : rocks) {
        r.Update();
    }

    // Update all active projectile elements
    for (Projectile& p : projectiles) {
        p.Update();
    }

    // Process player input
    Interaction();
}

// Process player input
void Asteroids::Interaction()
{
    // Wait for Enter key to start the game
    if (not startGame and IsKeyPressed(KEY_ENTER)) {
        startGame = true;
        startTime = GetFrameTime();
    }

    // Wait for Enter key to restart the game
    if (gameOver and IsKeyPressed(KEY_ENTER)) {
        Restart();
    }

    // If game is not over, shoot based on the player's fire rate
    if (not gameOver and IsMouseButtonDown(MOUSE_BUTTON_LEFT) and GetTime() - player.lastShotTime >= player.fireRate) {
        // Spawn new projectile
        projectiles.push_back(Projectile(player.position, player.rotation));
        // Update fire timings
        player.lastShotTime = GetTime();
    }
}

// Draw elements
void Asteroids::Draw()
{
    // Display start game screen
    if (not startGame) {
        ui.StartScreen();
        return;
    }

    // Display game over screen
    if (gameOver) {
        ui.GameOver();
        return;
    }

    // Draw game objects
    player.Draw();

    for (Rock r : rocks) {
        r.Draw();
    }

    for (Projectile p : projectiles) {
        p.Draw();
    }

    // Draw rectangles to prevent objects being seen outside of the play area
    DrawRectangle(0, 0, (SCREEN_WIDTH - PLAY_AREA_WIDTH) / 2.0f, SCREEN_HEIGHT, BLACK);
    DrawRectangle(PLAY_AREA_WIDTH + (SCREEN_WIDTH - PLAY_AREA_WIDTH) / 2.0f, 0,
        (SCREEN_WIDTH - PLAY_AREA_WIDTH) / 2.0f + 10.0f, SCREEN_HEIGHT, BLACK);
    DrawRectangle(0, 0, SCREEN_WIDTH, (SCREEN_HEIGHT - PLAY_AREA_HEIGHT) / 2.0f, BLACK);
    DrawRectangle(0, PLAY_AREA_HEIGHT + (SCREEN_HEIGHT - PLAY_AREA_HEIGHT) / 2.0f,
        SCREEN_WIDTH, (SCREEN_HEIGHT - PLAY_AREA_HEIGHT) / 2.0f, BLACK);

    // Draw play area lines
    DrawRectangleLines((SCREEN_WIDTH - PLAY_AREA_WIDTH) / 2.0f,
        (SCREEN_HEIGHT - PLAY_AREA_HEIGHT) / 2.0f,
        PLAY_AREA_WIDTH,
        PLAY_AREA_HEIGHT,
        WHITE);

    // Draw current score and lives
    ui.Draw(score, player.lives);
}

// Check the collision between two objects
bool Asteroids::CheckCollision(Vector2 pos1, float radius1, Vector2 pos2, float radius2) {
    float dx = pos2.x - pos1.x;
    float dy = pos2.y - pos1.y;
    float distance = sqrt(dx * dx + dy * dy);
    return distance <= (radius1 + radius2);
}

// Check the collision with all active objects
void Asteroids::CheckCollisions() {
    // Check if game is not over
    if (gameOver) return;

    // Check all rock objects
    for (Rock& r : rocks) {
        // If it's not active, we ignore it
        if (not r.active) continue;

        // Update player lives and remove rock that hit the player
        if (CheckCollision(player.position, SIDE_LENGTH, r.position, r.size)) {
            player.lives--;
            r.active = false;
            totalRockCount--;
        }

        // If player doesn't have lives left, stop the game
        if (not player.lives) {
            // Update score if any points were made
            if (score > 0)
                scoreboard.Update("Score", score);
            gameOver = true;
            break;
        }

        // Check collisions with projectiles
        for (Projectile& p : projectiles) {
            // If projectile is not active, or there's no collision, we skip the current object
            if (not p.active or not CheckCollision(p.position, PROJECTILE_SIZE, r.position, r.size)) continue;

            // We disable both objects and update the rock count
            p.active = false;
            r.active = false;
            totalRockCount--;

            // Split asteroid into a smaller size if possible and update score
            switch (r.type) {
            case 1:
                rocks.push_back(Rock(2, r.position));
                rocks.push_back(Rock(2, r.position));
                totalRockCount += 2;
                score += BIG_ROCK_POINTS;
                break;
            case 2:
                rocks.push_back(Rock(3, r.position));
                rocks.push_back(Rock(3, r.position));
                totalRockCount += 2;
                score += MEDIUM_ROCK_POINTS;
                break;
            case 3:
                score += SMALL_ROCK_POINTS;
                break;
            }
        }
    }
}
