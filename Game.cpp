#include "Game.h"
#include "Common.h"

void Game::showWordProgress() const {
    for (char c : secretWord) {
        bool found = false;
        for (char g : guessedLetters) {
            if (g == c) {
                found = true;
                break;
            }
        }
        cout << (found ? c : '_') << ' ';
    }
    cout << "\n";
}