#include "Common.h"
#include "WordManager.h"
#include "Game.h"


string encrypt(const string& word, int shift) {
    string result = word;

    for (char& c : result) {
        if (c >= 'a' && c <= 'z') {
            c = 'a' + (c - 'a' + shift) % 26;
        }
        else if (c >= 'A' && c <= 'Z') {
            c = 'A' + (c - 'A' + shift) % 26;
        }
    }

    return result;
}

void generateWordsFile(const string& filename, int shift) {
    vector<string> words = {
        "apple", "banana", "orange", "computer", "keyboard",
        "monitor", "elephant", "guitar", "library", "window",
        "bottle", "picture", "mountain", "bicycle", "chocolate",
        "airport", "hospital", "language", "notebook", "calendar",
        "umbrella", "sandwich", "triangle", "dinosaur", "adventure"
    };

    ofstream file(filename);

    for (const auto& word : words) {
        file << encrypt(word, shift) << "\n";
    }

    file.close();
}

int main() {
    srand(time(nullptr));

    WordManager wordManager("Words.txt", 3);
    string word = wordManager.getRandomWord();

    Game game(word);
    game.play();

    return 0;
}
