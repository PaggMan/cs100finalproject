#include "../include/MinesweeperMinigame.h"

MinesweeperMinigame::MinesweeperMinigame(){
    gameOver = false;
    uncoveredSquares = 0;
}

void MinesweeperMinigame::generateGrid(int userRow, int userColumn) {
    int index;
    int mineRow;
    int mineColumn;
    srand(time(0));
    for(int i = 0; i < 10; ++i) {
        do {
            index = rand() % 80;
            mineRow = index / 10;
            mineColumn = index % 10;
        }
        while(!validMineIndex(userRow, userColumn, mineRow, mineColumn));

        grid[mineRow][mineColumn] = -1;

        if(validIndex(mineRow - 1, mineColumn - 1) and (grid[mineRow - 1][mineColumn - 1] != -1)) {
            grid[mineRow - 1][mineColumn - 1] += 1;
        }
        if(validIndex(mineRow - 1, mineColumn) and (grid[mineRow - 1][mineColumn] != -1)) {
            grid[mineRow - 1][mineColumn] += 1;
        }
        if(validIndex(mineRow - 1, mineColumn + 1) and (grid[mineRow - 1][mineColumn + 1] != -1)) {
            grid[mineRow - 1][mineColumn + 1] += 1;
        }
        if(validIndex(mineRow, mineColumn - 1) and (grid[mineRow][mineColumn - 1] != -1)) {
            grid[mineRow][mineColumn - 1] += 1;
        }
        if(validIndex(mineRow, mineColumn + 1) and (grid[mineRow][mineColumn + 1] != -1)) {
            grid[mineRow][mineColumn + 1] += 1;
        }
        if(validIndex(mineRow + 1, mineColumn - 1) and (grid[mineRow + 1][mineColumn - 1] != -1)) {
            grid[mineRow + 1][mineColumn - 1] += 1;
        }
        if(validIndex(mineRow + 1, mineColumn) and (grid[mineRow + 1][mineColumn] != -1)) {
            grid[mineRow + 1][mineColumn] += 1;
        }
        if(validIndex(mineRow + 1, mineColumn + 1) and (grid[mineRow + 1][mineColumn + 1] != -1)) {
            grid[mineRow + 1][mineColumn + 1] += 1;
        }
    }
}

bool MinesweeperMinigame::validMineIndex(int userRow, int userColumn, int mineRow, int mineColumn) {
    if(grid[mineRow][mineColumn] == -1) {
        return false;
    }
    else if((userRow == mineRow) and (userColumn == mineColumn)) {
        return false;
    }
    else if(validIndex(userRow - 1, userColumn - 1) and (userRow - 1 == mineRow) and (userColumn - 1 == mineColumn)) {
        return false;
    }
    else if(validIndex(userRow - 1, userColumn) and (userRow - 1 == mineRow) and (userColumn == mineColumn)) {
        return false;
    }
    else if(validIndex(userRow - 1, userColumn + 1) and (userRow - 1 == mineRow) and (userColumn + 1 == mineColumn)) {
        return false;
    }
    else if(validIndex(userRow, userColumn - 1) and (userRow == mineRow) and (userColumn - 1 == mineColumn)) {
        return false;
    }
    else if(validIndex(userRow, userColumn + 1) and (userRow == mineRow) and (userColumn + 1 == mineColumn)) {
        return false;
    }
    else if(validIndex(userRow + 1, userColumn - 1) and (userRow + 1 == mineRow) and (userColumn - 1 == mineColumn)) {
        return false;
    }
    else if(validIndex(userRow + 1, userColumn) and (userRow + 1 == mineRow) and (userColumn == mineColumn)) {
        return false;
    }
    else if(validIndex(userRow + 1, userColumn + 1) and (userRow + 1 == mineRow) and (userColumn + 1 == mineColumn)) {
        return false;
    }
    else {
        return true;
    }
}

bool MinesweeperMinigame::validIndex(int row, int column) {
    if(((row >= 0) and (row < 8)) and ((column >= 0) and (column < 10))) {
        return true;
    }
    else {
        return false;
    }
}

void MinesweeperMinigame::revealChoice(int row, int column) {
    if(validIndex(row, column)) {
        if(gridToPrint[row][column] == 0) {
            gridToPrint[row][column] = 1;
            uncoveredSquares++;
            if(grid[row][column] == 0){
                revealChoice(row - 1, column - 1);
                revealChoice(row - 1, column);
                revealChoice(row - 1, column + 1);
                revealChoice(row, column - 1);
                revealChoice(row, column + 1);
                revealChoice(row + 1, column - 1);
                revealChoice(row + 1, column);
                revealChoice(row + 1, column + 1);
            }
        }
    }
}

void MinesweeperMinigame::printGrid(bool endGame) {
    cout << "    0 1 2 3 4 5 6 7 8 9\n  -----------------------\n";
    for(int i = 0; i < 8; ++i) {
        cout << i << " | ";
        for(int j = 0; j < 10; ++j) {
            if(endGame or gridToPrint[i][j] != 0) {
                if(grid[i][j] == -1) {
                    cout << "M ";
                }
                else {
                    cout << grid[i][j] << ' ';
                }
            }
            else if(gridToPrint[i][j] == -1) {
                cout << "F ";
            }
            else {
                cout << "? ";
            }
        }
        cout << "|\n";
    }
    cout << endl;
}

void MinesweeperMinigame::initialize(){
    int row = -1;
    int column = -1;
    
    cout << "Welcome to Minesweeper! There are 10 mines on the board. Let's get started!\n\n";
    cout << "Enter the row of your first choice: ";
    cin >> row;
    cout << endl;
    while(cin.fail() or row < 0 or row > 7) {
        cin.clear();
        cin.ignore(2147483647, '\n');
        cout << "Please enter a valid row: ";
        cin >> row;
        cout << endl;
    }
    cout << "Enter the column of your first choice: ";
    cin >> column;
    cout << endl;
    while(cin.fail() or column < 0 or column > 9) {
        cin.clear();
        cin.ignore(2147483647, '\n');
        cout << "Please enter a valid column: ";
        cin >> column;
        cout << endl;
    }
    generateGrid(row, column);
    revealChoice(row, column);
    printGrid(false);

    while(!gameOver) {
        row = -1;
        column = -1;
        while(!validIndex(row, column)) {
            cout << "Enter your next row: ";
            cin >> row;
            cout << endl;
            while(cin.fail() or row < 0 or row > 7) {
                cin.clear();
                cin.ignore(2147483647, '\n');
                cout << "Please enter a valid row: ";
                cin >> row;
                cout << endl;
            }
            cout << "Enter your next column: ";
            cin >> column;
            cout << endl;
            while(cin.fail() or column < 0 or column > 9) {
                cin.clear();
                cin.ignore(2147483647, '\n');
                cout << "Please enter a valid column: ";
                cin >> column;
                cout << endl;
            }
        }
        if(grid[row][column] == -1) {
            terminate();
        }
        else {
            revealChoice(row, column);
            if(uncoveredSquares >= 70) {
                terminate();
            }
            else {
                printGrid(false);
            }
        }
    }
}

void MinesweeperMinigame::terminate(){
    if(uncoveredSquares == 70) {
        cout << "Congratulations, you won!\n\n";
        userWon = true;
    }
    else {
        cout << "Better luck next time, you lost.\n\n";
        userWon = false;
    }
    gameOver = true;
    printGrid(true);
}
