// Constants files
#ifndef CONSTANTS_H
#define CONSTANTS_H

// Screen
#define SCREEN_WIDTH 1215
#define SCREEN_HEIGHT 900

// Play area
#define PLAY_AREA_WIDTH (SCREEN_WIDTH * 0.8f)
#define PLAY_AREA_HEIGHT (SCREEN_HEIGHT * 0.85f)

#define PLAY_AREA_UP_LIMIT (SCREEN_HEIGHT - (SCREEN_HEIGHT - PLAY_AREA_HEIGHT) / 2.0f)
#define PLAY_AREA_DOWN_LIMIT ((SCREEN_HEIGHT - PLAY_AREA_HEIGHT) - (SCREEN_HEIGHT - PLAY_AREA_HEIGHT) / 2.0f)
#define PLAY_AREA_LEFT_LIMIT ((SCREEN_WIDTH - PLAY_AREA_WIDTH) - (SCREEN_WIDTH - PLAY_AREA_WIDTH) / 2.0f)
#define PLAY_AREA_RIGHT_LIMIT (SCREEN_WIDTH - (SCREEN_WIDTH - PLAY_AREA_WIDTH) / 2.0f)

// Player
#define PLAYER_COLOR PURPLE
#define SIDE_LENGTH 30.0f
#define SPEED 300.0f
#define ROTATION_SPEED 90.0f
#define CURSOR_RANGE 5.0f

// Rock
#define SPAWN_RANGE 100.0f
#define MAX_ROCKS 10

// BIG Rock
#define BIG_ROCK_SPEED 250.0f
#define BIG_ROCK_COLOR SKYBLUE
#define BIG_ROCK_SIZE 50.0f
#define BIG_ROCK_POINTS 2

// MEDIUM ROCK 
#define MEDIUM_ROCK_SPEED 330.0f
#define MEDIUM_ROCK_COLOR ORANGE
#define MEDIUM_ROCK_SIZE 30.0f
#define MEDIUM_ROCK_POINTS 4

// SMALL ROCK 
#define SMALL_ROCK_SPEED 400.0f
#define SMALL_ROCK_COLOR PINK
#define SMALL_ROCK_SIZE 20.0f
#define SMALL_ROCK_POINTS 8

// SCOREBOARD
#define TOP_SCORE_MAX 5

#endif
