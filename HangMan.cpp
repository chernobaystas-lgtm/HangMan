#include "Common.h"


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
        "monitor", "elephant", "guitar", "library", "window"
    };

    ofstream file(filename);

    for (const auto& word : words) {
        file << encrypt(word, shift) << "\n";
    }

    file.close();
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    generateWordsFile("Words.txt", 3);
    cout << "File generated!\n";

    return 0;
}

