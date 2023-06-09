#ifndef __CHARACTER__
#define __CHARACTER__
#include <string>
#include <iostream>
#include "print.h"
using namespace std;

class Character {
    private:
        string name;


        int grades;
        int happiness;
        int health;

        string output;
        Print outputObject;
    
    public:
        Character();
        Character(const string&, int, int, int);
        ~Character();

        //stat accsessors
        string getName();
        int getGrades();
        int getHealth();
        int getHappiness();
        int getCumulativeScore();
        string getTier();

        //stat modifiers
        void setName(const string&);
        void setGrades(int);
        void setHealth(int);
        void setHappiness(int);     
        void workout();
        void studyHarder();
        void sleep();
        void hangWithFriends();

        void promptForName();
};
#endif
