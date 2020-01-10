#include <iostream>

#include "BowlingGame.h"

#define FRAMES 10
#define MAX_PINS 10

void BowlingGame::roll(int pins)
{
    rolls[currentRoll++] = pins;
}

int BowlingGame::getScore()
{
    int score = 0;
    int index = 0;
    for (int frame = 0; frame < FRAMES; ++frame)
    {
        if (isStrike(index))
        {
            score += + MAX_PINS + rolls[index + 1] + rolls[index + 2];
            ++index;
        }
        else if (isSpare(index))
        {
            score += + MAX_PINS + rolls[index + 2];
            index += 2;
        }
        else
        {
            score += + rolls[index] + rolls[index + 1];
            index += 2;
        }
    }
    return score;
}

bool BowlingGame::isSpare(int index)
{
    return (rolls[index] + rolls[index + 1] == MAX_PINS);
}

bool BowlingGame::isStrike(int index)
{
    return rolls[index] == MAX_PINS;
}
