#include "../include/UnscrambleMinigame.h"
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>
using namespace std;


UnscrambleMinigame::UnscrambleMinigame(){
    srand(time(0));
    word = rand() % 10;
}

void UnscrambleMinigame::initialize(){
    cout << "Unscramble this word: " << scrambledWords[word] << endl;
    getline(cin, userInput);

    if(userInput == possibleWords[word]){
        userWon = true;
    }
    else{
        userWon = false;
    }
    terminate();
    return;
}

void UnscrambleMinigame::terminate(){
    if(userWon){
        cout << "You Win!" << endl;
    }
    else{
        cout << "You lose!" << endl;
    }
    return;
}