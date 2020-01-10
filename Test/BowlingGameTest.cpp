#include "gtest/gtest.h"

#include "BowlingGame.h"

class BowlingGameTest : public ::testing::Test
{
protected:
    BowlingGame* game;

    void SetUp()
    {
        game = new BowlingGame();
    }

    void TearDown()
    {
        delete game;
    }

    void rollLoop(int num, int pins)
    {
        for (int i = 0; i < num; ++i)
        {
            game->roll(pins);
        }
    }

    void rollSpare(int pinsOnce, int pinsNext)
    {
        game->roll(pinsOnce);
        game->roll(pinsNext);
    }

    void rollStrike()
    {
        game->roll(10);
    }
};

TEST_F(BowlingGameTest, TestAllGutterGames)
{
    rollLoop(20, 0);
    EXPECT_EQ(0, game->getScore());
}

TEST_F(BowlingGameTest, TestAllOnePinGames)
{
    rollLoop(20, 1);
    EXPECT_EQ(20, game->getScore());
}

TEST_F(BowlingGameTest, TestOneSpare)
{
    rollSpare(8, 2);
    game->roll(4);
    rollLoop(17, 0);
    EXPECT_EQ(18, game->getScore());
}

TEST_F(BowlingGameTest, TestOneStrike)
{
    rollStrike();
    game->roll(5);
    game->roll(2);
    rollLoop(16, 0);
    EXPECT_EQ(24, game->getScore());
}

TEST_F(BowlingGameTest, TestFullStrikeGame)
{
    rollLoop(12, 10);
    EXPECT_EQ(300, game->getScore());
}

TEST_F(BowlingGameTest, TestFullSpareGame)
{
    rollLoop(21, 5);
    EXPECT_EQ(150, game->getScore());
}

TEST_F(BowlingGameTest, TestStrikeSpareGame)
{
    rollStrike();
    rollSpare(8, 2);
    rollStrike();
    EXPECT_EQ(50, game->getScore());
}
