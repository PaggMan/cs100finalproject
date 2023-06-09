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
    string output;
    Print outputObject;
    output = "    0 1 2 3 4 5 6 7 8 9\n  -----------------------\n";
    outputObject.printOutput(output);
    for(int i = 0; i < 8; ++i) {
        output = to_string(i) + " | ";
        outputObject.printOutput(output);
        for(int j = 0; j < 10; ++j) {
            if(endGame or gridToPrint[i][j] != 0) {
                if(grid[i][j] == -1) {
                    output = "M ";
                    outputObject.printOutput(output);
                }
                else {
                    output = to_string(grid[i][j]) + " ";
                    outputObject.printOutput(output);
                }
            }
            else {
                output = "? ";
                outputObject.printOutput(output);
            }
        }
        output = "|\n";
        outputObject.printOutput(output);
    }
    outputObject.printNewline();
}

void MinesweeperMinigame::initialize(){
    string output;
    Print outputObject;

    int row = -1;
    int column = -1;
    
    output = "Welcome to Minesweeper! There are 10 mines on the board. Let's get started!\n\n";
    output += "Enter the row of your first choice: ";
    outputObject.printOutput(output);
    cin >> row;
    outputObject.printNewline();
    while(cin.fail() or row < 0 or row > 7) {
        cin.clear();
        cin.ignore(2147483647, '\n');
        output = "Please enter a valid row: ";
        outputObject.printOutput(output);
        cin >> row;
        outputObject.printNewline();
    }
    output = "Enter the column of your first choice: ";
    outputObject.printOutput(output);
    cin >> column;
    outputObject.printNewline();
    while(cin.fail() or column < 0 or column > 9) {
        cin.clear();
        cin.ignore(2147483647, '\n');
        output = "Please enter a valid column: ";
        outputObject.printOutput(output);
        cin >> column;
        outputObject.printNewline();
    }
    generateGrid(row, column);
    revealChoice(row, column);
    printGrid(false);

    while(!gameOver) {
        row = -1;
        column = -1;
        while(!validIndex(row, column)) {
            output = "Enter your next row: ";
            outputObject.printOutput(output);
            cin >> row;
            outputObject.printNewline();
            while(cin.fail() or row < 0 or row > 7) {
                cin.clear();
                cin.ignore(2147483647, '\n');
                output = "Please enter a valid row: ";
                outputObject.printOutput(output);
                cin >> row;
                outputObject.printNewline();
            }
            output = "Enter your next column: ";
            outputObject.printOutput(output);
            cin >> column;
            outputObject.printNewline();
            while(cin.fail() or column < 0 or column > 9) {
                cin.clear();
                cin.ignore(2147483647, '\n');
                output = "Please enter a valid column: ";
                outputObject.printOutput(output);
                cin >> column;
                outputObject.printNewline();
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
    string output;
    Print outputObject;
    if(uncoveredSquares == 70) {
        output = "Congratulations, you won!\n\n";
        outputObject.printOutput(output);
        userWon = true;
    }
    else {
        output = "Better luck next time, you lost.\n\n";
        outputObject.printOutput(output);
        userWon = false;
    }
    gameOver = true;
    printGrid(true);
}