#include "../include/character.h"

Character::Character() {
    std::cout << "Character created" << endl;
}

Character::~Character() {

}

int Character::getGrades() { return grades; }
int Character::getHappiness(){ return happiness; }
int Character::getHealth() { return health; }