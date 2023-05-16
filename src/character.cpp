#include "../include/character.h"

Character::Character() {
    std::cout << "Character created" << endl;
    grades = 50;
    happiness = 50;
    health = 50;
}

Character::~Character() {

}

string Character::getName() { return name; }
int Character::getGrades() { return grades; }
int Character::getHappiness(){ return happiness; }
int Character::getHealth() { return health; }