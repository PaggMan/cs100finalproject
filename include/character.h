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
        ~Character();
};

#endif