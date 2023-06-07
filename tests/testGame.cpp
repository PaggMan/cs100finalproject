#include "gtest/gtest.h"

#include "../include/game.h"

TEST(loadGameTest, testUsername) {
    Game game = new Game();
    game->load();
    ASSERT_EQ(game->getCharacter()->getName(), )
}