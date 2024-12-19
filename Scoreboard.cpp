#include "Scoreboard.h"
#include <raylib.h>

// Get the top scores from the scores.txt file as a list
vector<pair<int, string>> Scoreboard::GetTopScores() {
    vector<pair<int, string>> topScores;

    // Open the scores file
    ifstream scores("scores.txt");

    // If empty or not existent, we return an empty list
    if (!scores.is_open()) {
        return topScores;
    }

    // Variables to extract each score
    int score;
    string playerName;

    // Read all the available scores in the file and add them to the list
    while (scores >> score >> playerName)
        topScores.emplace_back(score, playerName);

    // Close the file and return the list
    scores.close();
    return topScores;
}

// Update the top scores
void Scoreboard::Update(string playerName, int newScore) {
    // Get the current top scores
    vector<pair<int, string>> topScores = GetTopScores();

    // Add the new score
    topScores.emplace_back(newScore, playerName);

    // Sort the scores from greatest to lowest
    sort(begin(topScores), end(topScores));
    reverse(begin(topScores), end(topScores));

    // Open/Create the scores file blank
    ofstream scores("scores.txt");

    // Limit the writing of only the TOP_SCORE_MAX scores
    int topCounter = 0;
    for (auto topScore : topScores) {
        // If the limit is reached, stop adding elements
        if (topCounter == TOP_SCORE_MAX) break;
        // Write the score and player name in the file
        scores << topScore.first << ' ' << topScore.second << '\n';
        topCounter++;
    }

    // Close the file
    scores.close();
}
