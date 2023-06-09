#include "../include/TicTacToeMinigame.h"

TicTacToeMinigame::TicTacToeMinigame(){
    winner = 0;
}

void TicTacToeMinigame::initialize(){
    int userChoice = -1;
    int computerChoice = 0;
    int count = 0;

    output = "\nHello, welcome to Tic Tac Toe!\nThe rules are like any normal Tic Tac Toe game.\n\n";
    output += "Here are the index numbers for each location in the game:\n";
    output += "1 | 2 | 3\n";
    output += "---------\n";
    output += "4 | 5 | 6\n";
    output += "---------\n";
    output += "7 | 8 | 9\n";

    output += "\nLet's get started!\n\n";
    outputObject.printOutput(output);

    while((count < 9) && (winner == 0)) {
        if(count % 2 == 0) {
            output = "Enter your choice (1, 2, 3, 4, 5, 6, 7, 8, 9): ";
            outputObject.printOutput(output);
            cin >> userChoice;
            userChoice--;
            while(userChoice < 0 or userChoice > 9 or arr[userChoice] != ' ') {
                if(cin.fail()) {
                    cin.clear();
                    cin.ignore(2147483647, '\n');
                }
                output = "Invalid location!\n";
                output += "Enter your choice (1, 2, 3, 4, 5, 6, 7, 8, 9): ";
                outputObject.printOutput(output);
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
                }
                arr[computerChoice] = 'X';
            }
            output = "\nMy turn! Here is my move.\n";
            outputObject.printOutput(output);
        }

        output = string(1, arr[0]) + " | " + arr[1] + " | " + arr[2] + "\n";
        output += "---------\n";
        output += string(1, arr[3]) + " | " + arr[4] + " | " + arr[5] + "\n";
        output += "---------\n";
        output += string(1, arr[6]) + " | " + arr[7] + " | " + arr[8] + "\n\n";
        outputObject.printOutput(output);
        
        if(((arr[0] == arr[1]) && (arr[1] == arr[2]) && (arr[2] == 'O')) or ((arr[3] == arr[4]) && (arr[4] == arr[5]) && (arr[5] == 'O')) or ((arr[6] == arr[7]) && (arr[7] == arr[8]) && (arr[8] == 'O')) or ((arr[0] == arr[3]) && (arr[3] == arr[6]) && (arr[6] == 'O')) or ((arr[1] == arr[4]) && (arr[4] == arr[7]) && (arr[7] == 'O')) or ((arr[2] == arr[5]) && (arr[5] == arr[8]) && (arr[8] == 'O')) or ((arr[0] == arr[4]) && (arr[4] == arr[8]) && (arr[8] == 'O')) or ((arr[2] == arr[4]) && (arr[4] == arr[6]) && (arr[6] == 'O'))) {
            output = "Congratulations, you won!\n";
            outputObject.printOutput(output);
            winner = 1;
        }
        else if(((arr[0] == arr[1]) && (arr[1] == arr[2]) && (arr[2] == 'X')) or ((arr[3] == arr[4]) && (arr[4] == arr[5]) && (arr[5] == 'X')) or ((arr[6] == arr[7]) && (arr[7] == arr[8]) && (arr[8] == 'X')) or ((arr[0] == arr[3]) && (arr[3] == arr[6]) && (arr[6] == 'X')) or ((arr[1] == arr[4]) && (arr[4] == arr[7]) && (arr[7] == 'X')) or ((arr[2] == arr[5]) && (arr[5] == arr[8]) && (arr[8] == 'X')) or ((arr[0] == arr[4]) && (arr[4] == arr[8]) && (arr[8] == 'X')) or ((arr[2] == arr[4]) && (arr[4] == arr[6]) && (arr[6] == 'X'))) {
            output = "Unlucky, you did not win.\n";
            outputObject.printOutput(output);
            winner = -1;
        }
        else if(count == 8) {
            output = "We tied!\n";
            outputObject.printOutput(output);
        }
        count++;
    }

    terminate();
}

void TicTacToeMinigame::terminate(){
    if(winner == 1) {
        userWon = true;
    }
    else {
        userWon = false;
    }
}