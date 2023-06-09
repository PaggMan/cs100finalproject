#include "inputValidator.h"

bool InputValidator::isValidChoice(char choice) {   //Returns true if valid, returns false if invalid.
    return choice == '1' || choice == '2';
}