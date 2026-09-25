#include "WordManager.h"
#include "Common.h"

WordManager::WordManager(const string& filename, int shift) : shift(shift) {
    ifstream file(filename);
    string line;

    while (std::getline(file, line)) {
        if (!line.empty()) {
            words.push_back(decrypt(line));
        }
    }

    file.close();
}

string WordManager::decrypt(const string& encrypted) const {
   string result = encrypted;

    for (char& c : result) {
        if (c >= 'a' && c <= 'z') {
            c = 'a' + (c - 'a' - shift + 26) % 26;
        }
        else if (c >= 'A' && c <= 'Z') {
            c = 'A' + (c - 'A' - shift + 26) % 26;
        }
    }

    return result;
}

string WordManager::getRandomWord() {
    if (usedIndices.size() >= words.size()) {
        usedIndices.clear();
    }

    int index;
    bool alreadyUsed;

    do {
        index = rand() % words.size();
        alreadyUsed = false;

        for (int usedIndex : usedIndices) {
            if (usedIndex == index) {
                alreadyUsed = true;
                break;
            }
        }
    } while (alreadyUsed);

    usedIndices.push_back(index);
    return words[index];
}