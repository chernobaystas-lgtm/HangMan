#pragma once
#include "Common.h"

enum class HangmanStage {
    Empty, Rope, Head, Body, LeftArm, RightArm, LeftLeg, RightLeg
};

const array<string, 8> hangmanStages = {
    // Empty
    "\n"
    "\n"
    "\n"
    "\n"
    "\n"
    "\n",

    // Rope
    "  +---+\n"
    "  |   |\n"
    "      |\n"
    "      |\n"
    "      |\n"
    " =========\n",

    // Head
    "  +---+\n"
    "  |   |\n"
    "  O   |\n"
    "      |\n"
    "      |\n"
    " =========\n",

    // Body
    "  +---+\n"
    "  |   |\n"
    "  O   |\n"
    "  |   |\n"
    "      |\n"
    " =========\n",

    // LeftArm
    "  +---+\n"
    "  |   |\n"
    "  O   |\n"
    " /|   |\n"
    "      |\n"
    " =========\n",

    // RightArm
    "  +---+\n"
    "  |   |\n"
    "  O   |\n"
    " /|\\  |\n"
    "      |\n"
    " =========\n",

    // LeftLeg
    "  +---+\n"
    "  |   |\n"
    "  O   |\n"
    " /|\\  |\n"
    " /    |\n"
    " =========\n",

    // RightLeg
    "  +---+\n"
    "  |   |\n"
    "  O   |\n"
    " /|\\  |\n"
    " / \\  |\n"
    " =========\n"
};