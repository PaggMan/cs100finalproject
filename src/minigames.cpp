#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int RockPaperScissors() {
    int userScore = 0;
    int computerScore = 0;
    string userChoice;
    int computerChoice;
    string output;
    
    output = "\nHello, welcome to Rock Paper Scissors!\nThe rules are like any normal Rock Paper Scissors game and it is first to 3 wins.\nLet's get started!\n\n";
    cout << output;

    while(userScore != 3 and computerScore != 3) {
        srand(time(0));
        computerChoice = (rand() % 3) + 1; // 1 is Rock, 2 is Paper, 3 is Scissors
        output = "Enter your choice (Rock, Paper, Scissors): ";
        cout << output;
        cin >> userChoice;

        if(userChoice == "Rock" or userChoice == "rock") {
            if(computerChoice == 1) {
                output = "We both chose Rock, it is a tie!\n";
                cout << output;
            }
            else if(computerChoice == 2) {
                computerScore++;
                output = "I chose Paper and you chose Rock, I win this round!\n";
                cout << output;
            }
            else if(computerChoice == 3) {
                userScore++;
                output = "I chose Scissors and you chose Rock, you win this round!\n";
                cout << output;
            }
        }
        else if(userChoice == "Paper" or userChoice == "paper") {
            if(computerChoice == 1) {
                userScore++;
                output = "I chose Rock and you chose Paper, you win this round!\n";
                cout << output;
            }
            else if(computerChoice == 2) {
                
                output = "We both chose Paper, it is a tie!\n";
                cout << output;
            }
            else if(computerChoice == 3) {
                computerScore++;
                output = "I chose Scissors and you chose Paper, I win this round!\n";
                cout << output;
            }
        }
        else if(userChoice == "Scissors" or userChoice == "scissors") {
            if(computerChoice == 1) {
                computerScore++;
                output = "I chose Rock and you chose Scissors, I win this round!\n";
                cout << output;
            }
            else if(computerChoice == 2) {
                userScore++;
                output = "I chose Paper and you chose Scissors, you win this round!\n";
                cout << output;
            }
            else if(computerChoice == 3) {
                output = "We both chose Scissors, it is a tie!\n";
                cout << output;
            }
        }
        else {
            cout << "Error" << endl;
        }
        output = "The current score is " + to_string(userScore) + " (your score) to " + to_string(computerScore) + " (my score).\n\n";
        cout << output;
    }
    if(userScore == 3) {
        output = "\nCongratulations, you won the game!\n";
        cout << output;
    }
    else if(computerScore == 3) {
        output = "\nUnlucky, you did not win the game.\n";
        cout << output;
    }
    else {
        cout << "Error" << endl;
    }

    return userScore;
}

int TicTacToe() {
    char arr[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int userChoice = 0;
    int computerChoice = 0;
    int count = 0;
    int winner = 0;
    string output;

    output = "\nHello, welcome to Tic Tac Toe!\nThe rules are like any normal Tic Tac Toe game.\nLet's get started!\n\n";
    cout << output;

    while((count < 9) && (winner == 0)) {
        if(count % 2 == 0) {
            output = "Enter your choice (1, 2, 3, 4, 5, 6, 7, 8, 9): ";
            cout << output;
            cin >> userChoice;
            userChoice--;
            while(arr[userChoice] != ' ') {
                output = "This location is not empty!\n";
                cout << output;
                output = "Enter your choice (1, 2, 3, 4, 5, 6, 7, 8, 9): ";
                cout << output;
                cin >> userChoice;
                userChoice--;
            }
            arr[userChoice] = 'O';
        }
        else {
            if(arr[0] == ' ' and ((arr[2] == 'X' and arr[2] == arr[1]) or (arr[3] == 'X' and arr[3] == arr[6]) or (arr[4] == 'X' and arr[4] == arr[8]))) {
                arr[0] = 'X';
            }
            else if(arr[1] == ' ' and ((arr[0] == 'X' and arr[0] == arr[2]) or (arr[4] == 'X' and arr[4] == arr[7]))) {
                arr[1] = 'X';
            }
            else if(arr[2] == ' ' and ((arr[0] == 'X' and arr[0] == arr[1]) or (arr[5] == 'X' and arr[5] == arr[8]) or (arr[4] == 'X' and arr[4] == arr[6]))) {
                arr[2] = 'X';
            }
            else if(arr[3] == ' ' and ((arr[0] == 'X' and arr[0] == arr[6]) or (arr[4] == 'X' and arr[4] == arr[5]))) {
                arr[3] = 'X';
            }
            else if(arr[4] == ' ' and ((arr[3] == 'X' and arr[3] == arr[5]) or (arr[1] == 'X' and arr[1] == arr[7]) or (arr[0] == 'X' and arr[0] == arr[8]) or (arr[2] == 'X' and arr[2] == arr[6]))) {
                arr[4] = 'X';
            }
            else if(arr[5] == ' ' and ((arr[2] == 'X' and arr[2] == arr[8]) or (arr[4] == 'X' and arr[4] == arr[3]))) {
                arr[5] = 'X';
            }
            else if(arr[6] == ' ' and ((arr[8] == 'X' and arr[8] == arr[7]) or (arr[3] == 'X' and arr[3] == arr[0]) or (arr[4] == 'X' and arr[4] == arr[2]))) {
                arr[6] = 'X';
            }
            else if(arr[7] == ' ' and ((arr[1] == 'X' and arr[1] == arr[4]) or (arr[6] == 'X' and arr[6] == arr[8]))) {
                arr[7] = 'X';
            }
            else if(arr[8] == ' ' and ((arr[6] == 'X' and arr[6] == arr[7]) or (arr[5] == 'X' and arr[5] == arr[2]) or (arr[4] == 'X' and arr[4] == arr[0]))) {
                arr[8] = 'X';
            }
            else if(arr[0] == ' ' and ((arr[2] != ' ' and arr[2] == arr[1]) or (arr[3] != ' ' and arr[3] == arr[6]) or (arr[4] != ' ' and arr[4] == arr[8]))) {
                arr[0] = 'X';
            }
            else if(arr[1] == ' ' and ((arr[0] != ' ' and arr[0] == arr[2]) or (arr[4] != ' ' and arr[4] == arr[7]))) {
                arr[1] = 'X';
            }
            else if(arr[2] == ' ' and ((arr[0] != ' ' and arr[0] == arr[1]) or (arr[5] != ' ' and arr[5] == arr[8]) or (arr[4] != ' ' and arr[4] == arr[6]))) {
                arr[2] = 'X';
            }
            else if(arr[3] == ' ' and ((arr[0] != ' ' and arr[0] == arr[6]) or (arr[4] != ' ' and arr[4] == arr[5]))) {
                arr[3] = 'X';
            }
            else if(arr[4] == ' ' and ((arr[3] != ' ' and arr[3] == arr[5]) or (arr[1] != ' ' and arr[1] == arr[7]) or (arr[0] != ' ' and arr[0] == arr[8]) or (arr[2] != ' ' and arr[2] == arr[6]))) {
                arr[4] = 'X';
            }
            else if(arr[5] == ' ' and ((arr[2] != ' ' and arr[2] == arr[8]) or (arr[4] != ' ' and arr[4] == arr[3]))) {
                arr[5] = 'X';
            }
            else if(arr[6] == ' ' and ((arr[8] != ' ' and arr[8] == arr[7]) or (arr[3] != ' ' and arr[3] == arr[0]) or (arr[4] != ' ' and arr[4] == arr[2]))) {
                arr[6] = 'X';
            }
            else if(arr[7] == ' ' and ((arr[1] != ' ' and arr[1] == arr[4]) or (arr[6] != ' ' and arr[6] == arr[8]))) {
                arr[7] = 'X';
            }
            else if(arr[8] == ' ' and ((arr[6] != ' ' and arr[6] == arr[7]) or (arr[5] != ' ' and arr[5] == arr[2]) or (arr[4] != ' ' and arr[4] == arr[0]))) {
                arr[8] = 'X';
            }
            else {
                srand(time(0));
                computerChoice = rand() % 9;
                while(arr[computerChoice] != ' ') {
                    computerChoice = rand() % 9;
                    cout << computerChoice << endl;
                }
                arr[computerChoice] = 'X';
            }
            output = "\nMy turn! Here is my move.\n";
            cout << output;
        }

        cout << arr[0] << " | " << arr[1] << " | " << arr[2] << endl;
        cout << "---------" << endl;
        cout << arr[3] << " | " << arr[4] << " | " << arr[5] << endl;
        cout << "---------" << endl;
        cout << arr[6] << " | " << arr[7] << " | " << arr[8] << endl << endl;

        
        if(((arr[0] == arr[1]) && (arr[1] == arr[2]) && (arr[2] == 'O')) or ((arr[3] == arr[4]) && (arr[4] == arr[5]) && (arr[5] == 'O')) or ((arr[6] == arr[7]) && (arr[7] == arr[8]) && (arr[8] == 'O')) or ((arr[0] == arr[3]) && (arr[3] == arr[6]) && (arr[6] == 'O')) or ((arr[1] == arr[4]) && (arr[4] == arr[7]) && (arr[7] == 'O')) or ((arr[2] == arr[5]) && (arr[5] == arr[8]) && (arr[8] == 'O')) or ((arr[0] == arr[4]) && (arr[4] == arr[8]) && (arr[8] == 'O')) or ((arr[2] == arr[4]) && (arr[4] == arr[6]) && (arr[6] == 'O'))) {
            output = "Congratulations, you won!\n";
            cout << output;
            break;
        }
        else if(((arr[0] == arr[1]) && (arr[1] == arr[2]) && (arr[2] == 'X')) or ((arr[3] == arr[4]) && (arr[4] == arr[5]) && (arr[5] == 'X')) or ((arr[6] == arr[7]) && (arr[7] == arr[8]) && (arr[8] == 'X')) or ((arr[0] == arr[3]) && (arr[3] == arr[6]) && (arr[6] == 'X')) or ((arr[1] == arr[4]) && (arr[4] == arr[7]) && (arr[7] == 'X')) or ((arr[2] == arr[5]) && (arr[5] == arr[8]) && (arr[8] == 'X')) or ((arr[0] == arr[4]) && (arr[4] == arr[8]) && (arr[8] == 'X')) or ((arr[2] == arr[4]) && (arr[4] == arr[6]) && (arr[6] == 'X'))) {
            output = "Unlucky, you did not win.\n";
            cout << output;
            break;
        }
        else if(count == 8) {
            output = "We tied!\n";
            cout << output;
        }
        count++;
    }

    return 0;
}

int Wordle() {
    string arr[20] = {"dream", "guard", "flood", "adult", "sight", "alarm", "force", "wound", "brave", "cable", "panic", "study", "faith", "equal", "grade", "award", "bully", "voice", "drive", "title"};
    int checkInWord[5] = {0, 0, 0, 0, 0};
    char attempt1[5][2];
    char attempt2[5][2];
    char attempt3[5][2];
    char attempt4[5][2];
    char attempt5[5][2];
    char attempt6[5][2];
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
    cin.ignore();
    for(i = 0; i < 5; ++i) {
        if(attempt1[i][1] != 'O') {
            for(j = 1; j < 5; ++j) {
                if((attempt1[i][0] == word.at((i + j) % 5)) and (checkInWord[(i + j) % 5] == 0)) {
                    attempt1[i][1] = 'X';
                }
            }
        }
    }
    for(i = 0; i < 5; ++i) {
        if(attempt1[i][1] == 'O') {
            cout << "\033[1;32m" << attempt1[i][0] << "\033[0m";
        }
        else if(attempt1[i][1] == 'X') {
            cout << "\033[1;33m" << attempt1[i][0] << "\033[0m";
        }
        else {
            cout << attempt1[i][0];
        }
        checkInWord[i] = 0;
    }
    cout << endl;
    if(wordCheck == 5) {
        cout << "Congratulations, you got the word!" << endl;
        return 6;
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
    cin.ignore();
    for(i = 0; i < 5; ++i) {
        if(attempt2[i][1] != 'O') {
            for(j = 1; j < 5; ++j) {
                if((attempt2[i][0] == word.at((i + j) % 5)) and (checkInWord[(i + j) % 5] == 0)) {
                    attempt2[i][1] = 'X';
                }
            }
        }
    }
    for(i = 0; i < 5; ++i) {
        if(attempt1[i][1] == 'O') {
            cout << "\033[1;32m" << attempt1[i][0] << "\033[0m";
        }
        else if(attempt1[i][1] == 'X') {
            cout << "\033[1;33m" << attempt1[i][0] << "\033[0m";
        }
        else {
            cout << attempt1[i][0];
        }
    }
    cout << endl;
    for(i = 0; i < 5; ++i) {
        if(attempt2[i][1] == 'O') {
            cout << "\033[1;32m" << attempt2[i][0] << "\033[0m";
        }
        else if(attempt2[i][1] == 'X') {
            cout << "\033[1;33m" << attempt2[i][0] << "\033[0m";
        }
        else {
            cout << attempt2[i][0];
        }
        checkInWord[i] = 0;
    }
    cout << endl;
    if(wordCheck == 5) {
        cout << "Congratulations, you got the word!" << endl;
        return 5;
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
    cin.ignore();
    for(i = 0; i < 5; ++i) {
        if(attempt3[i][1] != 'O') {
            for(j = 1; j < 5; ++j) {
                if((attempt3[i][0] == word.at((i + j) % 5)) and (checkInWord[(i + j) % 5] == 0)) {
                    attempt3[i][1] = 'X';
                }
            }
        }
    }
    for(i = 0; i < 5; ++i) {
        if(attempt1[i][1] == 'O') {
            cout << "\033[1;32m" << attempt1[i][0] << "\033[0m";
        }
        else if(attempt1[i][1] == 'X') {
            cout << "\033[1;33m" << attempt1[i][0] << "\033[0m";
        }
        else {
            cout << attempt1[i][0];
        }
    }
    cout << endl;
    for(i = 0; i < 5; ++i) {
        if(attempt2[i][1] == 'O') {
            cout << "\033[1;32m" << attempt2[i][0] << "\033[0m";
        }
        else if(attempt2[i][1] == 'X') {
            cout << "\033[1;33m" << attempt2[i][0] << "\033[0m";
        }
        else {
            cout << attempt2[i][0];
        }
    }
    cout << endl;
    for(i = 0; i < 5; ++i) {
        if(attempt3[i][1] == 'O') {
            cout << "\033[1;32m" << attempt3[i][0] << "\033[0m";
        }
        else if(attempt3[i][1] == 'X') {
            cout << "\033[1;33m" << attempt3[i][0] << "\033[0m";
        }
        else {
            cout << attempt3[i][0];
        }
        checkInWord[i] = 0;
    }
    cout << endl;
    if(wordCheck == 5) {
        cout << "Congratulations, you got the word!" << endl;
        return 4;
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
    cin.ignore();
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
    for(i = 0; i < 5; ++i) {
        if(attempt1[i][1] == 'O') {
            cout << "\033[1;32m" << attempt1[i][0] << "\033[0m";
        }
        else if(attempt1[i][1] == 'X') {
            cout << "\033[1;33m" << attempt1[i][0] << "\033[0m";
        }
        else {
            cout << attempt1[i][0];
        }
    }
    cout << endl;
    for(i = 0; i < 5; ++i) {
        if(attempt2[i][1] == 'O') {
            cout << "\033[1;32m" << attempt2[i][0] << "\033[0m";
        }
        else if(attempt2[i][1] == 'X') {
            cout << "\033[1;33m" << attempt2[i][0] << "\033[0m";
        }
        else {
            cout << attempt2[i][0];
        }
    }
    cout << endl;
    for(i = 0; i < 5; ++i) {
        if(attempt3[i][1] == 'O') {
            cout << "\033[1;32m" << attempt3[i][0] << "\033[0m";
        }
        else if(attempt3[i][1] == 'X') {
            cout << "\033[1;33m" << attempt3[i][0] << "\033[0m";
        }
        else {
            cout << attempt3[i][0];
        }
    }
    cout << endl;
    for(i = 0; i < 5; ++i) {
        if(attempt4[i][1] == 'O') {
            cout << "\033[1;32m" << attempt4[i][0] << "\033[0m";
        }
        else if(attempt4[i][1] == 'X') {
            cout << "\033[1;33m" << attempt4[i][0] << "\033[0m";
        }
        else {
            cout << attempt4[i][0];
        }
        checkInWord[i] = 0;
    }
    cout << endl;
    if(wordCheck == 5) {
        cout << "Congratulations, you got the word!" << endl;
        return 3;
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
    cin.ignore();
    for(i = 0; i < 5; ++i) {
        if(attempt5[i][1] != 'O') {
            for(j = 1; j < 5; ++j) {
                if((attempt5[i][0] == word.at((i + j) % 5)) and (checkInWord[(i + j) % 5] == 0)) {
                    attempt5[i][1] = 'X';
                }
            }
        }
    }
    for(i = 0; i < 5; ++i) {
        if(attempt1[i][1] == 'O') {
            cout << "\033[1;32m" << attempt1[i][0] << "\033[0m";
        }
        else if(attempt1[i][1] == 'X') {
            cout << "\033[1;33m" << attempt1[i][0] << "\033[0m";
        }
        else {
            cout << attempt1[i][0];
        }
    }
    cout << endl;
    for(i = 0; i < 5; ++i) {
        if(attempt2[i][1] == 'O') {
            cout << "\033[1;32m" << attempt2[i][0] << "\033[0m";
        }
        else if(attempt2[i][1] == 'X') {
            cout << "\033[1;33m" << attempt2[i][0] << "\033[0m";
        }
        else {
            cout << attempt2[i][0];
        }
    }
    cout << endl;
    for(i = 0; i < 5; ++i) {
        if(attempt3[i][1] == 'O') {
            cout << "\033[1;32m" << attempt3[i][0] << "\033[0m";
        }
        else if(attempt3[i][1] == 'X') {
            cout << "\033[1;33m" << attempt3[i][0] << "\033[0m";
        }
        else {
            cout << attempt3[i][0];
        }
    }
    cout << endl;
    for(i = 0; i < 5; ++i) {
        if(attempt4[i][1] == 'O') {
            cout << "\033[1;32m" << attempt4[i][0] << "\033[0m";
        }
        else if(attempt4[i][1] == 'X') {
            cout << "\033[1;33m" << attempt4[i][0] << "\033[0m";
        }
        else {
            cout << attempt4[i][0];
        }
    }
    cout << endl;
    for(i = 0; i < 5; ++i) {
        if(attempt5[i][1] == 'O') {
            cout << "\033[1;32m" << attempt5[i][0] << "\033[0m";
        }
        else if(attempt5[i][1] == 'X') {
            cout << "\033[1;33m" << attempt5[i][0] << "\033[0m";
        }
        else {
            cout << attempt5[i][0];
        }
        checkInWord[i] = 0;
    }
    cout << endl;
    if(wordCheck == 5) {
        cout << "Congratulations, you got the word!" << endl;
        return 2;
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
    cin.ignore();
    for(i = 0; i < 5; ++i) {
        if(attempt6[i][1] != 'O') {
            for(j = 1; j < 5; ++j) {
                if((attempt6[i][0] == word.at((i + j) % 5)) and (checkInWord[(i + j) % 5] == 0)) {
                    attempt6[i][1] = 'X';
                }
            }
        }
    }
    for(i = 0; i < 5; ++i) {
        if(attempt1[i][1] == 'O') {
            cout << "\033[1;32m" << attempt1[i][0] << "\033[0m";
        }
        else if(attempt1[i][1] == 'X') {
            cout << "\033[1;33m" << attempt1[i][0] << "\033[0m";
        }
        else {
            cout << attempt1[i][0];
        }
    }
    cout << endl;
    for(i = 0; i < 5; ++i) {
        if(attempt2[i][1] == 'O') {
            cout << "\033[1;32m" << attempt2[i][0] << "\033[0m";
        }
        else if(attempt2[i][1] == 'X') {
            cout << "\033[1;33m" << attempt2[i][0] << "\033[0m";
        }
        else {
            cout << attempt2[i][0];
        }
    }
    cout << endl;
    for(i = 0; i < 5; ++i) {
        if(attempt3[i][1] == 'O') {
            cout << "\033[1;32m" << attempt3[i][0] << "\033[0m";
        }
        else if(attempt3[i][1] == 'X') {
            cout << "\033[1;33m" << attempt3[i][0] << "\033[0m";
        }
        else {
            cout << attempt3[i][0];
        }
    }
    cout << endl;
    for(i = 0; i < 5; ++i) {
        if(attempt4[i][1] == 'O') {
            cout << "\033[1;32m" << attempt4[i][0] << "\033[0m";
        }
        else if(attempt4[i][1] == 'X') {
            cout << "\033[1;33m" << attempt4[i][0] << "\033[0m";
        }
        else {
            cout << attempt4[i][0];
        }
    }
    cout << endl;
    for(i = 0; i < 5; ++i) {
        if(attempt5[i][1] == 'O') {
            cout << "\033[1;32m" << attempt5[i][0] << "\033[0m";
        }
        else if(attempt5[i][1] == 'X') {
            cout << "\033[1;33m" << attempt5[i][0] << "\033[0m";
        }
        else {
            cout << attempt5[i][0];
        }
    }
    cout << endl;
    for(i = 0; i < 5; ++i) {
        if(attempt6[i][1] == 'O') {
            cout << "\033[1;32m" << attempt6[i][0] << "\033[0m";
        }
        else if(attempt6[i][1] == 'X') {
            cout << "\033[1;33m" << attempt6[i][0] << "\033[0m";
        }
        else {
            cout << attempt6[i][0];
        }
        checkInWord[i] = 0;
    }
    cout << endl;
    if(wordCheck == 5) {
        cout << "Congratulations, you got the word!" << endl;
        return 1;
    }

    cout << "Better luck next time, you did not get the word." << endl;
    return 0;
}