class BowlingGame
{
    static const int MAX_NUMBER_OF_ROLLS = 21;
    int rolls[MAX_NUMBER_OF_ROLLS] = {0x00, 0x00};
    int currentRoll = 0;

public:
    void roll(int pins);
    int getScore();

private:
    bool isSpare(int index);
    bool isStrike(int index);
};
