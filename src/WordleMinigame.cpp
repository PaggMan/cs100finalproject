#include "../include/WordleMinigame.h"

WordleMinigame::WordleMinigame(){
    
}

void WordleMinigame::printAttempt(const char (&arr)[5][2]) {
    for(int i = 0; i < 5; ++i) {
        if(arr[i][1] == 'O') {
            cout << "\033[1;32m" << arr[i][0] << "\033[0m";
        }
        else if(arr[i][1] == 'X') {
            cout << "\033[1;33m" << arr[i][0] << "\033[0m";
        }
        else {
            cout << arr[i][0];
        }
    }
    cout << endl;
}

void WordleMinigame::initialize(){
    int wordCheck, i, j;
    string word, output;

    srand(time(0));
    word = arr[rand() % 20];
    //cout << "Word (for testing): " << word << endl << endl;

    output = "\nHello, welcome to Wordle!\nThe goal of the game is to guess the 5 letter word using 5 letter word guesses. You have 6 attempts!\nLet's get started!\n\n";
    cout << output;    
    
    output = "Enter your first attempt (all lowercase): ";
    cout << output;
    wordCheck = 0;
    for(i = 0; i < 5; ++i) {
        cin >> attempt1[i][0];
        if(attempt1[i][0] == word.at(i)) {
            attempt1[i][1] = 'O';
            checkInWord[i] = 1;
            wordCheck++;
        }
    }
    cin.ignore(2147483647, '\n');
    for(i = 0; i < 5; ++i) {
        if(attempt1[i][1] != 'O') {
            for(j = 1; j < 5; ++j) {
                if((attempt1[i][0] == word.at((i + j) % 5)) and (checkInWord[(i + j) % 5] == 0)) {
                    attempt1[i][1] = 'X';
                }
            }
        }
    }
    printAttempt(attempt1);
    for(int i = 0; i < 5; ++i) {
        checkInWord[i] = 0;
    }
    if(wordCheck == 5) {
        cout << "Congratulations, you got the word!" << endl;
        return;
    }
    
    output = "Enter your second attempt (all lowercase): ";
    cout << output;
    wordCheck = 0;
    for(i = 0; i < 5; ++i) {
        cin >> attempt2[i][0];
        if(attempt2[i][0] == word.at(i)) {
            attempt2[i][1] = 'O';
            checkInWord[i] = 1;
            wordCheck++;
        }
    }
    cin.ignore(2147483647, '\n');
    for(i = 0; i < 5; ++i) {
        if(attempt2[i][1] != 'O') {
            for(j = 1; j < 5; ++j) {
                if((attempt2[i][0] == word.at((i + j) % 5)) and (checkInWord[(i + j) % 5] == 0)) {
                    attempt2[i][1] = 'X';
                }
            }
        }
    }
    printAttempt(attempt1);
    printAttempt(attempt2);
    for(int i = 0; i < 5; ++i) {
        checkInWord[i] = 0;
    }
    if(wordCheck == 5) {
        cout << "Congratulations, you got the word!" << endl;
        return;
    }

    output = "Enter your third attempt (all lowercase): ";
    cout << output;
    wordCheck = 0;
    for(i = 0; i < 5; ++i) {
        cin >> attempt3[i][0];
        if(attempt3[i][0] == word.at(i)) {
            attempt3[i][1] = 'O';
            checkInWord[i] = 1;
            wordCheck++;
        }
    }
    cin.ignore(2147483647, '\n');
    for(i = 0; i < 5; ++i) {
        if(attempt3[i][1] != 'O') {
            for(j = 1; j < 5; ++j) {
                if((attempt3[i][0] == word.at((i + j) % 5)) and (checkInWord[(i + j) % 5] == 0)) {
                    attempt3[i][1] = 'X';
                }
            }
        }
    }
    printAttempt(attempt1);
    printAttempt(attempt2);
    printAttempt(attempt3);
    for(int i = 0; i < 5; ++i) {
        checkInWord[i] = 0;
    }
    if(wordCheck == 5) {
        cout << "Congratulations, you got the word!" << endl;
        return;
    }

    output = "Enter your fourth attempt (all lowercase): ";
    cout << output;
    wordCheck = 0;
    for(i = 0; i < 5; ++i) {
        cin >> attempt4[i][0];
        if(attempt4[i][0] == word.at(i)) {
            attempt4[i][1] = 'O';
            checkInWord[i] = 1;
            wordCheck++;
        }
    }
    cin.ignore(2147483647, '\n');
    for(i = 0; i < 5; ++i) {
        if(attempt4[i][1] != 'O') {
            for(j = 1; j < 5; ++j) {
                if((attempt4[i][0] == word.at((i + j) % 5)) and (checkInWord[(i + j) % 5] == 0)) {
                    attempt4[i][1] = 'X';
                    checkInWord[(i + j) % 5] = 1;
                }
            }
        }
    }
    printAttempt(attempt1);
    printAttempt(attempt2);
    printAttempt(attempt3);
    printAttempt(attempt4);
    for(int i = 0; i < 5; ++i) {
        checkInWord[i] = 0;
    }
    if(wordCheck == 5) {
        cout << "Congratulations, you got the word!" << endl;
        return;
    }

    output = "Enter your fifth attempt (all lowercase): ";
    cout << output;
    wordCheck = 0;
    for(i = 0; i < 5; ++i) {
        cin >> attempt5[i][0];
        if(attempt5[i][0] == word.at(i)) {
            attempt5[i][1] = 'O';
            checkInWord[i] = 1;
            wordCheck++;
        }
    }
    cin.ignore(2147483647, '\n');
    for(i = 0; i < 5; ++i) {
        if(attempt5[i][1] != 'O') {
            for(j = 1; j < 5; ++j) {
                if((attempt5[i][0] == word.at((i + j) % 5)) and (checkInWord[(i + j) % 5] == 0)) {
                    attempt5[i][1] = 'X';
                }
            }
        }
    }
    printAttempt(attempt1);
    printAttempt(attempt2);
    printAttempt(attempt3);
    printAttempt(attempt4);
    printAttempt(attempt5);
    for(int i = 0; i < 5; ++i) {
        checkInWord[i] = 0;
    }
    if(wordCheck == 5) {
        cout << "Congratulations, you got the word!" << endl;
        return;
    }

    output = "Enter your last attempt (all lowercase): ";
    cout << output;
    wordCheck = 0;
    for(i = 0; i < 5; ++i) {
        cin >> attempt6[i][0];
        if(attempt6[i][0] == word.at(i)) {
            attempt6[i][1] = 'O';
            checkInWord[i] = 1;
            wordCheck++;
        }
    }
    cin.ignore(2147483647, '\n');
    for(i = 0; i < 5; ++i) {
        if(attempt6[i][1] != 'O') {
            for(j = 1; j < 5; ++j) {
                if((attempt6[i][0] == word.at((i + j) % 5)) and (checkInWord[(i + j) % 5] == 0)) {
                    attempt6[i][1] = 'X';
                }
            }
        }
    }
    printAttempt(attempt1);
    printAttempt(attempt2);
    printAttempt(attempt3);
    printAttempt(attempt4);
    printAttempt(attempt5);
    printAttempt(attempt6);
    for(int i = 0; i < 5; ++i) {
        checkInWord[i] = 0;
    }
    if(wordCheck == 5) {
        cout << "Congratulations, you got the word!" << endl;
        return;
    }

    cout << "Better luck next time, you did not get the word, which was " + word + "." << endl;

    terminate();
}

void WordleMinigame::terminate(){
    
}