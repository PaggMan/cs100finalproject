#include "../include/MinesweeperMinigame.h"

MinesweeperMinigame::MinesweeperMinigame(){
    
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

void MinesweeperMinigame::executeChoice(int row, int column) {
    if(validIndex(row, column)) {
        if(gridToPrint[row][column] == 0) {
            gridToPrint[row][column] = 1;
            if(grid[row][column] == 0){
                executeChoice(row - 1, column - 1);
                executeChoice(row - 1, column);
                executeChoice(row - 1, column + 1);
                executeChoice(row, column - 1);
                executeChoice(row, column + 1);
                executeChoice(row + 1, column - 1);
                executeChoice(row + 1, column);
                executeChoice(row + 1, column + 1);
            }
        }
    }
}

void MinesweeperMinigame::printGrid(bool endGame) {
    for(int i = 0; i < 8; ++i) {
        cout << "| ";
        for(int j = 0; j < 10; ++j) {
            if(endGame or gridToPrint[i][j] != 0) {
                if(grid[i][j] == -1) {
                    cout << "M ";
                }
                else {
                    cout << grid[i][j] << ' ';
                }
            }
            else {
                cout << "X ";
            }
        }
        cout << "|" << endl;
    }
}

void MinesweeperMinigame::initialize(){
    int userIndex = -1;
    int row;
    int column;
    
    cout << "Welcome to Minesweeper! There are 10 mines on the board. Let's get started!" << endl << endl;
    cout << "Enter your first choice: ";
    cin >> userIndex;
    row = userIndex / 10;
    column = userIndex % 10;
    while(!validIndex(row, column)) {
        cout << "Please enter a valid choice: ";
        cin >> userIndex;
        cout << endl;
        row = userIndex / 10;
        column = userIndex % 10;
    }
    
    generateGrid(row, column);
    executeChoice(row, column);
    printGrid(false);

    terminate();
}

void MinesweeperMinigame::terminate(){
    
}

int main() {
    MinesweeperMinigame testGame;
    testGame.initialize();

    return 0;
}