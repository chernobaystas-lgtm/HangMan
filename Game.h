#pragma once
#include "Common.h"
#include "HangmanArt.h"

class Game {
private:
    string secretWord;
    vector<char> guessedLetters;
    vector<char> wrongLetters;
    int mistakes;
    int maxMistakes;
    chrono::steady_clock::time_point startTime;

public:
    Game(const string& word);

    void showWordProgress() const;
    bool isLetterGuessed(char letter) const;
    bool isWordGuessed() const;
    void drawHangman() const;

    void play();
    void printStats() const;
};