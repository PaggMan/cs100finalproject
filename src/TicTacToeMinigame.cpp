#include "../include/TicTacToeMinigame.h"

TicTacToeMinigame::TicTacToeMinigame(){
    winner = 0;
}

void TicTacToeMinigame::initialize(){
    int userChoice = 0;
    int computerChoice = 0;
    int count = 0;

    cout << "\nHello, welcome to Tic Tac Toe!\nThe rules are like any normal Tic Tac Toe game.\n\n";

    cout << "Here are the index numbers for each location in the game:" << endl;
    cout << "1 | 2 | 3" << endl;
    cout << "---------" << endl;
    cout << "4 | 5 | 6" << endl;
    cout << "---------" << endl;
    cout << "7 | 8 | 9" << endl;
    
    cout << "\nLet's get started!\n\n";

    while((count < 9) && (winner == 0)) {
        if(count % 2 == 0) {
            cout << "Enter your choice (1, 2, 3, 4, 5, 6, 7, 8, 9): ";
            cin >> userChoice;
            userChoice--;
            while(arr[userChoice] != ' ') {
                if(cin.fail()) {
                    cin.clear();
                    cin.ignore(2147483647, '\n');
                }
                cout << "Invalid location!\n";
                cout << "Enter your choice (1, 2, 3, 4, 5, 6, 7, 8, 9): ";
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
            cout << "\nMy turn! Here is my move.\n";
        }

        cout << arr[0] << " | " << arr[1] << " | " << arr[2] << endl;
        cout << "---------" << endl;
        cout << arr[3] << " | " << arr[4] << " | " << arr[5] << endl;
        cout << "---------" << endl;
        cout << arr[6] << " | " << arr[7] << " | " << arr[8] << endl << endl;
        
        if(((arr[0] == arr[1]) && (arr[1] == arr[2]) && (arr[2] == 'O')) or ((arr[3] == arr[4]) && (arr[4] == arr[5]) && (arr[5] == 'O')) or ((arr[6] == arr[7]) && (arr[7] == arr[8]) && (arr[8] == 'O')) or ((arr[0] == arr[3]) && (arr[3] == arr[6]) && (arr[6] == 'O')) or ((arr[1] == arr[4]) && (arr[4] == arr[7]) && (arr[7] == 'O')) or ((arr[2] == arr[5]) && (arr[5] == arr[8]) && (arr[8] == 'O')) or ((arr[0] == arr[4]) && (arr[4] == arr[8]) && (arr[8] == 'O')) or ((arr[2] == arr[4]) && (arr[4] == arr[6]) && (arr[6] == 'O'))) {
            cout << "Congratulations, you won!\n";
            break;
        }
        else if(((arr[0] == arr[1]) && (arr[1] == arr[2]) && (arr[2] == 'X')) or ((arr[3] == arr[4]) && (arr[4] == arr[5]) && (arr[5] == 'X')) or ((arr[6] == arr[7]) && (arr[7] == arr[8]) && (arr[8] == 'X')) or ((arr[0] == arr[3]) && (arr[3] == arr[6]) && (arr[6] == 'X')) or ((arr[1] == arr[4]) && (arr[4] == arr[7]) && (arr[7] == 'X')) or ((arr[2] == arr[5]) && (arr[5] == arr[8]) && (arr[8] == 'X')) or ((arr[0] == arr[4]) && (arr[4] == arr[8]) && (arr[8] == 'X')) or ((arr[2] == arr[4]) && (arr[4] == arr[6]) && (arr[6] == 'X'))) {
            cout << "Unlucky, you did not win.\n";
            break;
        }
        else if(count == 8) {
            cout << "We tied!\n";
        }
        count++;
    }

    terminate();
}

void TicTacToeMinigame::terminate(){
    
}


