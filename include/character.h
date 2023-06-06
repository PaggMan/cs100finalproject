#ifndef __CHARACTER__
#define __CHARACTER__
#include <string>
#include <iostream>
using namespace std;

class Character {
    private:
        string name;
        int grades;
        int happiness;
        int health;
    
    public:
        Character();
        Character(const string&, int, int, int);
        ~Character();

        //stat accsessors
        string getName();
        int getGrades();
        int getHealth();
        int getHappiness();

        //stat modifiers
        void setGrades(int);
        void setHealth(int);
        void setHappiness(int);
        void setName(string);
        void workout();
        void studyHarder();
        void sleep();
        void hangWithFriends();
};
#endif
