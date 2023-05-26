#ifndef __TYPING_MINIGAME__
#define __TYPING_MINIGAME__
#include <iostream>
#include <string>
#include "minigame.h"

using namespace std;

class TypingMinigame : public Minigame{
    private:
        string targetWord;
        string userInput;
        bool gameOver;
        void disableTerminalEcho();
        void enableTerminalEcho();
    
    public:
        TypingMinigame(string target);
        void initialize() override;
        void terminate() override;


};

#endif