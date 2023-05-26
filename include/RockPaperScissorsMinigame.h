#ifndef __ROCKPAPERSCISSORS_MINIGAME__
#define __ROCKPAPERSCISSORS_MINIGAME__
#include <iostream>
#include <string>
#include <cstdlib>
#include "minigame.h"
using namespace std;

class RockPaperScissorsMinigame : public Minigame{
    private:
        int userScore;
        int computerScore;
    public:
        RockPaperScissorsMinigame();
        void initialize() override;
        void terminate() override;
};

#endif