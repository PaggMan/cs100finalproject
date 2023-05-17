#include <cstdlib>
#include "../include/character.h"

Character::Character() {
    std::cout << "Character created" << endl;
    grades = 50;
    happiness = 50;
    health = 50;
    name  = "Cole";
}

Character::~Character() {

}

    ~Character();

    //stat accsessors
    string Character::getName() { return name; }
    int Character::getGrades() { return grades; }
    int Character::getHappiness(){ return happiness; }
    int Character::getHealth() { return health; }

    //stat modifiers (algorithm for increase subject to change, maybe increases and decreases)
    void Character::workout(){
        int increase = rand() % 10 + 1;
        health += increase;

        //add 5-10 fun messages based on the value you get


    }

    void Character::studyHarder(){
        int increase = rand() % 10 + 1;
        grades += increase;

        //add 5-10 fun messages based on the value you get
    }
    void Character::hangWithFriends(){
        int increase = rand() % 10 + 1;
        happiness += increase;

        //add 5-10 fun messages based on the value you get
    }
    void Character::sleep(){
        int increase = rand() % 10 + 1;
        health += increase;

        //add 5-10 fun messages based on the value you get
    }
