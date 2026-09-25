#pragma once
#include "Common.h"

class WordManager {
private:
    vector<string> words;
    vector<int> usedIndices;
    int shift;

    string decrypt(const string& encrypted) const;

public:
    WordManager(const string& filename, int shift);
    string getRandomWord();
};

