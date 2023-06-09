#include "../include/TypingMinigame.h"
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>
using namespace std;

TypingMinigame::TypingMinigame(){
    possibleWords[0] = "The fox jumps over the lazy dog";
    possibleWords[1] = "CS100 is the best class";
    possibleWords[2] = "CS Student simulator is Game of the Year";
    possibleWords[3] = "I think the developers should get a raise";
    possibleWords[4] = "How much wood would a woodchuck chuck if a woodchuck could chuck wood";
    srand(time(0));
    int targetWordIndex = rand() % 5;
    targetWord = possibleWords[targetWordIndex];
}
TypingMinigame::~TypingMinigame() {
}

void TypingMinigame::disableTerminalEcho() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void TypingMinigame::enableTerminalEcho() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void TypingMinigame::initialize(){
    disableTerminalEcho();

    cout << "Welcome to the Typing Game! You will be given a phrase and you have to type it, however, you cannot see what you type!\n";
    cout << "Type \"" << targetWord << "\"" << endl;
    getline(cin, userInput);

    enableTerminalEcho();

    cout << "You entered: " << userInput << endl;

    terminate();
    return;
}

void TypingMinigame::terminate(){
    if(userInput == targetWord){
        cout << "You Win!" << endl;
        userWon = true;
    }
    else{
        cout << "You lose!" << endl;
        userWon = false;
    }
    return;
}
