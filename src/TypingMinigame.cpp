#include "../include/TypingMinigame.h"
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>
using namespace std;


TypingMinigame::TypingMinigame(){
    int targetWordIndex = rand() % 5;
    targetWord = possibleWords[targetWordIndex];
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
        gameOver = true;
    }
    else{
        cout << "You lose!" << endl;
        gameOver = false;
    }
    return;
}