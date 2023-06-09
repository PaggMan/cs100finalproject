#ifndef __UNSCRAMBLE_MINIGAME__
#define __UNSCRAMBLE_MINIGAME__
#include <iostream>
#include <string>
#include "minigame.h"

using namespace std;

class UnscrambleMinigame : public Minigame{
    private:
        int word;
        string userInput;
        string possibleWords[10] = {"googletest", "kanban" , "scrum" , "solid" , "computer" , "testing", "github", "develop", "ethics", "optimize"};
        string scrambledWords[10] = {"eloogesgtt", "abnakn", "cmurs", "lidso", "cpmoteur", "tetsign", "hgtiub", "vdelepo", "etcish", "imopitze"};
    public:
        UnscrambleMinigame();
        void initialize() override;
        void terminate() override;
};

#endif