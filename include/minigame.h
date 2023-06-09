#ifndef __MINIGAME__
#define __MINIGAME__

#include <iostream>
#include <string>
#include "print.h"
using namespace std;

class Minigame{
    protected:
        bool userWon;
        string output;
        Print outputObject;
    public:
        virtual void initialize() = 0;
        virtual void terminate() = 0;
        bool getResult(){
            return userWon;
        }
};

#endif