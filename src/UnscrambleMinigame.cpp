#include "../include/UnscrambleMinigame.h"
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>
using namespace std;


UnscrambleMinigame::UnscrambleMinigame(){
    arrLength = 10;    
}

void UnscrambleMinigame::initialize(){

    int word = rand() % 10; //random number 0-9

    cout << "Unscramble this word: " << scrambledWords[word] << endl;
    getline(cin, userInput);


    if(userInput == possibleWords[word]){
        gameOver = true;
    }
    else{
        gameOver = false;
    }
    terminate();
    return;

}

void UnscrambleMinigame::terminate(){
    if(gameOver){
        cout << "You Win!" << endl;
    }
    else{
        cout << "You lose!" << endl;
    }
    return;
}



