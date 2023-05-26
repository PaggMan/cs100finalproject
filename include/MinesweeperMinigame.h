#ifndef __MINESWEEPER_MINIGAME__
#define __MINESWEEPER_MINIGAME__
#include <iostream>
#include <string>
#include <cstdlib>
#include "minigame.h"
using namespace std;

class MinesweeperMinigame : public Minigame{
    private:
        int grid[8][10] = { 0 };
        int gridToPrint[8][10] = { 0 };
        void generateGrid(int, int);
        bool validMineIndex(int, int, int, int);
        bool validIndex(int, int);
        void revealChoice(int, int);
        void printGrid(bool);
    public:
        MinesweeperMinigame();
        void initialize() override;
        void terminate() override;
};

#endif