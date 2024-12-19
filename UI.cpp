#include "UI.h"
#include <raylib.h>

using namespace std;

// Draw the start screen UI
void UI::StartScreen() {
    string startGamePrompt = "Press [Enter] to start";
    int fontSize = 40;

    DrawText(startGamePrompt.c_str(),
        SCREEN_WIDTH / 2 -
        MeasureText(startGamePrompt.c_str(), fontSize) / 2,
        SCREEN_HEIGHT / 2 - fontSize, fontSize, WHITE);
}

// Draw the score
void UI::Score(int score) {
    string scorePrompt = "Score\n" + to_string(score);
    int fontSize = 20;

    DrawText(scorePrompt.c_str(),
        SCREEN_WIDTH -
        MeasureText(scorePrompt.c_str(), fontSize) - 30.0f,
        fontSize, fontSize, WHITE);
}

// Draw the lives counter
void UI::Lives(int lives) {
    string livesPrompt = "Lives";
    int fontSize = 20;

    DrawText(livesPrompt.c_str(),
        10.0f,
        fontSize, fontSize, WHITE);

    // Draw player shapes to represent the remaining lives
    for (int i = 0; i < lives; i++) {
        float baseX = MeasureText(livesPrompt.c_str(), fontSize) / 2 - 5.0f;
        float baseY = (fontSize + SIDE_LENGTH + 50.0f) + i * (SIDE_LENGTH + 15.0f);

        Vector2 top = { baseX + SIDE_LENGTH / 2, baseY - SIDE_LENGTH };
        Vector2 left = { baseX, baseY };
        Vector2 right = { baseX + SIDE_LENGTH, baseY };

        DrawTriangleLines(top, left, right, PLAYER_COLOR);
    }
}

// Draw the game over screen
void UI::GameOver() {
    // Get the top scores to display them
    vector<pair<int, string>> scores = scoreboard.GetTopScores();

    // Order the scores from greatest to lowest
    sort(begin(scores), end(scores));
    reverse(begin(scores), end(scores));

    // UI prompts
    string gameOverText = "Game Over";
    string gameOverPrompt = "Press [Enter] to restart\n\t\t\t\tScoreboard\n";

    // Display the top scores with it's top number, name and score
    int topPlace = 1;
    for (auto score : scores) {
        gameOverPrompt += "\t\t\t\t" + to_string(topPlace) + ' ' + score.second + " - " + to_string(score.first) + "\n";
        topPlace++;
    }

    // Draw the game over text and scoreboard
    int gameOverFontSize = 75;
    int fontSize = 20;

    DrawText(gameOverText.c_str(),
        SCREEN_WIDTH / 2 -
        MeasureText(gameOverText.c_str(), gameOverFontSize) / 2,
        SCREEN_HEIGHT / 4 - gameOverFontSize, gameOverFontSize, RED);

    DrawText(gameOverPrompt.c_str(),
        SCREEN_WIDTH / 2 -
        MeasureText(gameOverPrompt.c_str(), fontSize) / 2,
        SCREEN_HEIGHT / 4, fontSize, WHITE);
}

// Draw the gameplay elements
void UI::Draw(int score, int lives) {
    Score(score);
    Lives(lives);
}
