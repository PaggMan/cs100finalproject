#ifndef __TICTACTOE_MINIGAME__
#define __TICTACTOE_MINIGAME__
#include <iostream>
#include <string>
#include <cstdlib>
#include "minigame.h"
#include "print.h"
using namespace std;

class TicTacToeMinigame : public Minigame{
    private:
        char arr[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
        int winner;
    public:
        TicTacToeMinigame();
        void initialize() override;
        void terminate() override;
};

#endif