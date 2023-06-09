#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

//InputValidator has the job of taking inputs the user enters in the game and determining whether or not that input is valid.

class InputValidator {
    public:
        bool isValidChoice(char choice);   //Determine whether the user input for choosing what to do in the day is valid or not.

};

#endif