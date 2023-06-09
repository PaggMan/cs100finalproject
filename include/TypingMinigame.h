#ifndef __TYPING_MINIGAME__
#define __TYPING_MINIGAME__
#include <iostream>
#include <string>
#include "minigame.h"
using namespace std;

class TypingMinigame : public Minigame{
    private:
        string targetWord;
        string possibleWords[5] = {"The fox jumps over the lazy dog", "CS100 is the best class", "CS Student simulator is Game of the Year", "I think the developers should get a raise", "How much wood would a woodchuck chuck if a woodchuck could chuck wood"};
        string userInput;
        void disableTerminalEcho();
        void enableTerminalEcho();
    
    public:
        TypingMinigame();
        void initialize() override;
        void terminate() override;


};

#endif