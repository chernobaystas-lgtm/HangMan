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

    bool isLetterGuessed(char letter) const;
    bool isWordGuessed() const;
    void showWordProgress() const;
    void drawHangman() const;

public:
    Game(const string& word);

    void showWordProgress(char letter)const;
    bool isLetterGuessed()const;
    bool isWordGuessed()const;
    void drawHangman()const;

    void play();
    void printStats() const;

    Game(const string& word) : secretWord(word), mistakes(0) {
        maxMistakes = static_cast<int>(hangmanStages.size()) - 1;
        startTime = chrono::steady_clock::now();
    }
};

