#include <iostream>
#include "BowlingGame.h"

int main()
{
    BowlingGame game;
    game.roll(2);
    std::cout << "Score is: " << game.getScore() << std::endl;
}
