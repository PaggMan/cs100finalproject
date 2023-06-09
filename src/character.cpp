#include <cstdlib>
#include "../include/character.h"
Character::Character() {

    grades = 50;
    happiness = 50;
    health = 50;
    name  = "";
}
Character::~Character() {
}
    //stat accsessors
    string Character::getName() { return name; }
    int Character::getGrades() { return grades; }
    int Character::getHappiness(){ return happiness; }
    int Character::getHealth() { return health; }

    

    void Character::setName(const string& name) {
        this->name = name;
    }

    void Character::setGrades(int grades) {
        this->grades = grades;
    }
    void Character::setHappiness(int happiness) {
        this->happiness = happiness;
    }
    void Character::setHealth(int health) {
        this->health = health;
    }


    //stat modifiers (algorithm for increase subject to change, maybe increases and decreases)
    void Character::workout(){
        int increase = rand() % 10 + 1;
        health += increase;

        if(increase <= 2){
            cout << "You trip and fall over a loose dumbell. +" << increase; 
        }
        else if(increase > 2 or increase <= 4){
            cout << "You feel lazy, so you just do cardio. +" << increase;
        }
        else if(increase > 4 or increase <= 6){
            cout << "You have a good workout and feel sore the next day. +" << increase;
        }
        else if(increase > 6 or increase <= 8){
            cout << "You have an amazing workout and get a new record on some of your sets. +" << increase;
        }
        else if(increase > 8 or increase <= 10){
            cout << "You PR on everything you try and get some reputaton at the gym. +" << increase;
        }

        cout << endl;   

    }

    void Character::studyHarder(){
        int increase = rand() % 5 + 1;
        grades += increase;

        if(increase <= 1){
            cout << "You get distracted by your phone. +" << increase; 
        }
        else if(increase > 1 or increase <= 2){
            cout << "You study a little bit. +" << increase;
        }
        else if(increase > 2 or increase <= 3){
            cout << "You join a study group and are ready for your test. +" << increase;
        }
        else if(increase > 3 or increase <= 4){
            cout << "You study for a while. Maybe you can help teach class next time. +" << increase;
        }
        else if(increase >  4 or increase <= 5){
            cout << "You master the subject. It is impossible to fail your exam. +" << increase;
        }
        cout << endl;   
    }
void Character::hangWithFriends(){
        int increase = rand() % 10 + 1;
        happiness += increase;
        if(increase <= 2){
            cout << "You get forgotten and don't get picked up. +" << increase; 
        }
        else if(increase > 2 or increase <= 4){
            cout << "You get McDonalds with your friend. +" << increase;
        }
        else if(increase > 4 or increase <= 6){
            cout << "You go see a movie with your friends. +" << increase;
        }
        else if(increase > 6 or increase <= 8){
            cout << "You go to an amusement park with your friends. +" << increase;
        }
        else if(increase > 8 or increase <= 10){
            cout << "You travel the world with your friends. +" << increase;
        }
        cout << endl;  
    }


    void Character::promptForName() {
        string username;
        cin >> username;
        name = username;
    }
