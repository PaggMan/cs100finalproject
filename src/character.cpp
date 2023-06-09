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

    int Character::getCumulativeScore() {
        double gradesWeight = .4;  // Weight for grades (adjust as needed)
        double happinessWeight = .3;  // Weight for happiness
        double healthWeight = .3;  // Weight for health

        double weightedGrades = gradesWeight * (grades / 100.0);
        double weightedHappiness = happinessWeight * (happiness / 100.0);
        double weightedHealth = healthWeight * (health / 100.0);

        double overallScore = weightedGrades + weightedHappiness + weightedHealth;

        return static_cast<int>(overallScore * 100);
    }

    string Character::getTier() {
    int scaledScore = getCumulativeScore();

    if (scaledScore > 90) {
        return "legendary";
    } else if (scaledScore > 80) {
        return "epic";
    } else if (scaledScore > 60) {
        return "good";
    } else if (scaledScore > 40) {
        return "satisfactory";
    } else {
        return "poor";
    }

}

    

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
        if(health == 100){
            cout << "You ego-lift without a spotter, and it falls on your face. -15 health" << endl;
            health -= 15; 
            return;
        }
        health += increase;
        if(increase <= 2){
            cout << "You trip and fall over a loose dumbell. +" << increase << " health"; 
        }
        else if(increase > 2 and increase <= 4){
            cout << "You feel lazy, so you just do cardio. +" << increase << " health";
        }
        else if(increase > 4 and increase <= 6){
            cout << "You have a good workout and feel sore the next day. +" << increase << " health";
        }
        else if(increase > 6 and increase <= 8){
            cout << "You have an amazing workout and get a new record on some of your sets. +" << increase << " health";
        }
        else if(increase > 8 and increase <= 10){
            cout << "You PR on everything you try and get some reputaton at the gym. +" << increase << " health";
        }

        cout << "   -3 grades";
        grades -= 3;

        if(grades < 0){
            grades = 0;
        }
        cout << endl;   
        if(health > 100){
            health = 100;
        }

    }

    void Character::studyHarder(){
        if(grades == 100){
            cout << "You get burnt out, fall asleep at your desk, and miss your midterm. -10 grades" << endl;
            grades -= 10; 
            return;
        }
        int increase = rand() % 5 + 1;
        grades += increase;

        if(increase <= 1){
            cout << "You get distracted by your phone. +" << increase << " grades"; 
        }
        else if(increase > 1 and increase <= 2){
            cout << "You study a little bit. +" << increase << " grades";
        }
        else if(increase > 2 and increase <= 3){
            cout << "You join a study group and are ready for your test. +" << increase << " grades";
        }
        else if(increase > 3 and increase <= 4){
            cout << "You study for a while. Maybe you can help teach class next time. +" << increase << " grades";
        }
        else if(increase >  4 and increase <= 5){
            cout << "You master the subject. It is impossible to fail your exam. +" << increase << " grades" ;
        }

        cout << "   -1 health   -1 happiness";
        health--;
        happiness--;
        if(grades > 100){
            grades = 100;
        }
        if(health < 0){
            health = 0;
        }
        if(happiness < 0){
            happiness = 0;
        }
        cout << endl;   
    }
    void Character::hangWithFriends(){
        if(happiness == 100){
                cout << "You get into an argument with your friends on the way back home. -15 happiness" << endl;
                happiness -= 10; 
                return;
            }
        int increase = rand() % 10 + 1;
        happiness += increase;
        if(increase <= 2){
            cout << "You get forgotten and don't get picked up. +" << increase << " happiness"; 
        }
        else if(increase > 2 and increase <= 4){
            cout << "You get McDonalds with your friend. +" << increase << " happiness";
        }
        else if(increase > 4 and increase <= 6){
            cout << "You go see a movie with your friends. +" << increase << " happiness";
        }
        else if(increase > 6 and increase <= 8){
            cout << "You go to an amusement park with your friends. +" << increase << " happiness";
        }
        else if(increase > 8 and increase <= 10){
            cout << "You travel the world with your friends. +" << increase << " happiness";
        }

        cout << "   -3 grades";
        grades -= 3;
        cout << endl;  
        if(happiness > 100){
            happiness = 100;
        }

        if(grades < 0){
            grades = 0;
        }
    }


    void Character::promptForName() {
        string username;
        cin >> username;
        name = username;
    }
