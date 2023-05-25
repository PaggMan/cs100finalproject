#ifndef __WORDLE_MINIGAME__
#define __WORDLE_MINIGAME__
#include <iostream>
#include <string>
#include <cstdlib>
#include "minigame.h"
using namespace std;

class WordleMinigame : public Minigame{
    private:
        char attempt1[5][2];
        char attempt2[5][2];
        char attempt3[5][2];
        char attempt4[5][2];
        char attempt5[5][2];
        char attempt6[5][2];
        string arr[20] = {"dream", "guard", "flood", "adult", "sight", "alarm", "force", "wound", "brave", "cable", "panic", "study", "faith", "equal", "grade", "award", "bully", "voice", "drive", "title"};
        int checkInWord[5] = {0, 0, 0, 0, 0};
        void printAttempt(const char (&arr)[5][2]);
    public:
        WordleMinigame();
        void initialize() override;
        void terminate() override;
};

#endif