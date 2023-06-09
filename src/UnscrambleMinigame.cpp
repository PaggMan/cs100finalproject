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
    output = "Welcome to Unscramble! Your goal is the unscramble the given CS100 word!\n";
    output += "Unscramble this word: " + scrambledWords[word] + "\n\n";
    output += "  *Be careful, the word is case sensitive!\n\n\n";

    output += "Enter your guess: ";
    outputObject.printOutput(output);
  
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
        output = "You Win!\n";
        outputObject.printOutput(output);
    }
    else{
        output = "You lose!\n";
        outputObject.printOutput(output);
    }
    return;
}