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
        string output;
        Print outputObject;
        int increase = rand() % 10 + 1;
        if(health == 100){
            output = "You ego-lift without a spotter, and it falls on your face. -15 health\n";
            outputObject.printOutput(output);
            health -= 15; 
            return;
        }
        health += increase;
        if(increase <= 2){
            output = "You trip and fall over a loose dumbell. +" + to_string(increase) + " health";
            outputObject.printOutput(output);
        }
        else if(increase > 2 and increase <= 4){
            output = "You feel lazy, so you just do cardio. +" + to_string(increase) + " health";
            outputObject.printOutput(output);
        }
        else if(increase > 4 and increase <= 6){
            output = "You have a good workout and feel sore the next day. +" + to_string(increase) + " health";
            outputObject.printOutput(output);
        }
        else if(increase > 6 and increase <= 8){
            output = "You have an amazing workout and get a new record on some of your sets. +" + to_string(increase) + " health";
            outputObject.printOutput(output);
        }
        else if(increase > 8 and increase <= 10){
            output = "You PR on everything you try and get some reputaton at the gym. +" + to_string(increase) + " health";
            outputObject.printOutput(output);
        }

        output = "   -3 grades";
        outputObject.printOutput(output);
        grades -= 3;

        if(grades < 0){
            grades = 0;
        }
        outputObject.printNewline();
        if(health > 100){
            health = 100;
        }

    }

    void Character::studyHarder(){
        string output;
        Print outputObject;
        if(grades == 100){
            output = "You get burnt out, fall asleep at your desk, and miss your midterm. -10 grades\n";
            outputObject.printOutput(output);
            grades -= 10; 
            return;
        }
        int increase = rand() % 5 + 1;
        grades += increase;

        if(increase <= 1){
            output = "You get distracted by your phone. +" + to_string(increase) + " grades"; 
            outputObject.printOutput(output);
        }
        else if(increase > 1 and increase <= 2){
            output = "You study a little bit. +" + to_string(increase) + " grades";
            outputObject.printOutput(output);
        }
        else if(increase > 2 and increase <= 3){
            output = "You join a study group and are ready for your test. +" + to_string(increase) + " grades";
            outputObject.printOutput(output);
        }
        else if(increase > 3 and increase <= 4){
            output = "You study for a while. Maybe you can help teach class next time. +" + to_string(increase) + " grades";
            outputObject.printOutput(output);
        }
        else if(increase >  4 and increase <= 5){
            output = "You master the subject. It is impossible to fail your exam. +" + to_string(increase) + " grades" ;
            outputObject.printOutput(output);
        }

        output = "   -1 health   -1 happiness";
        outputObject.printOutput(output);
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
        outputObject.printNewline();
    }

    void Character::hangWithFriends(){
        string output;
        Print outputObject;
        if(happiness == 100){
                output = "You get into an argument with your friends on the way back home. -15 happiness\n";
                outputObject.printOutput(output);
                happiness -= 10; 
                return;
            }
        int increase = rand() % 10 + 1;
        happiness += increase;
        if(increase <= 2){
            output = "You get forgotten and don't get picked up. +" + to_string(increase) + " happiness"; 
            outputObject.printOutput(output);
        }
        else if(increase > 2 and increase <= 4){
            output = "You get McDonalds with your friend. +" + to_string(increase) + " happiness";
            outputObject.printOutput(output);
        }
        else if(increase > 4 and increase <= 6){
            output = "You go see a movie with your friends. +" + to_string(increase) + " happiness";
            outputObject.printOutput(output);
        }
        else if(increase > 6 and increase <= 8){
            output = "You go to an amusement park with your friends. +" + to_string(increase) + " happiness";
            outputObject.printOutput(output);
        }
        else if(increase > 8 and increase <= 10){
            output = "You travel the world with your friends. +" + to_string(increase) + " happiness";
            outputObject.printOutput(output);
        }

        output = "   -3 grades";
        outputObject.printOutput(output);
        grades -= 3;
        outputObject.printNewline();
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
