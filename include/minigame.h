#ifndef __MINIGAME__
#define __MINIGAME__

#include <iostream>
#include <string>

using namespace std;

class Minigame{
    public:
        virtual void initialize() = 0;
        virtual void terminate() = 0;
        bool gameOver;
        bool getResult(){
            return gameOver;
        }
};

#endif