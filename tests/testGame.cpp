#include "gtest/gtest.h"

#include "../include/game.h"

/*TEST(loadGameTest, testUsername) {
    Game* game = new Game();
    game->load("../gamedata/game.json");
    ASSERT_EQ(game->getCharacter()->getName(), "cole");
}*/




int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}