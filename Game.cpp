#include "Game.h"
#include "Common.h"


Game::Game(const string& word) : secretWord(word), mistakes(0) {
    maxMistakes = static_cast<int>(hangmanStages.size()) - 1;
    startTime = chrono::steady_clock::now();
}

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

bool Game::isLetterGuessed(char letter) const {
    for (char c : guessedLetters) {
        if (c == letter) {
            return true;
        }
    }
    for (char c : wrongLetters) {
        if (c == letter) {
            return true;
        }
    }
    return false;
}

bool Game::isWordGuessed() const {
    for (char c : secretWord) {
        if (isLetterGuessed(c)) {

        }
        else {
            return false; 
        }
    }
    return true;
}


void Game::drawHangman() const {
    cout << hangmanStages[mistakes] << "\n";
}

void Game::play() {
    while (mistakes < maxMistakes && !isWordGuessed()) {
        system("cls");
        drawHangman();
        showWordProgress();

        cout << "Wrong letters: ";
        for (char c : wrongLetters) cout << c << ' ';
        cout << "\n";

        cout << "Enter a letter: ";
        char letter;
        cin >> letter;

        if (!isalpha(letter)) {
            cout << "Please enter a letter, not a digit or symbol!\n";
            continue;
        }

        letter = tolower(letter);

        if (isLetterGuessed(letter)) {
            cout << "You already tried this letter!\n";
            continue;
        }

        bool found = false;
        for (char c : secretWord) {
            if (c == letter) {
                found = true;
                break;
            }
        }

        if (found) {
            guessedLetters.push_back(letter);
        }
        else {
            wrongLetters.push_back(letter);
            mistakes++;
        }
    }

    drawHangman();

    if (isWordGuessed()) {
        cout << "\nYou won! The word was: " << secretWord << "\n";
    }
    else {
        cout << "\nYou lost! The word was: " << secretWord << "\n";
    }

    printStats();
}


void Game::printStats() const {
    auto endTime = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(endTime - startTime);

    cout << "\n--- Statistics ---\n";
    cout << "Time: " << duration.count() << " seconds\n";
    cout << "Tries:    " << guessedLetters.size() + wrongLetters.size() << endl;
    cout << secretWord << endl;
    cout << "All guessed Letters: ";
    for (char c : guessedLetters) {
        cout << c << " , ";
    }
    cout << endl;
    cout << "All wrong Letters: ";
    for (char c : wrongLetters) {
        cout << c << " , ";
    }
    cout << endl;
}