#include <iostream>
#include "../include/game.h"
#include <experimental/filesystem>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
using namespace std;

namespace fs = std::experimental::filesystem;

int main() {
    std::cout << "Welcome to College Student Simulator!\n";

    cout << "Menu: " << endl;
    cout << "1. New Game" << endl;
    cout << "2. Load Game" << endl;
    cout << "3. Quit" << endl;

    // Get user input
    int choice;
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    system("clear");
    Game* game = new Game();
    // Process user input
    if(choice == 1) {
        // Start new game
        game->start();
        game->save();
    }
    else if(choice == 2) {
        // Load saved game
        cout << "Which game do you want to load." << endl;
        // std::string directoryPath = "../data";  // Replace with the actual directory path

        // for (const auto& entry : fs::directory_iterator(directoryPath)) {
        //     if (fs::is_regular_file(entry)) {
        //         std::cout << entry.path().filename() << std::endl;
        //     }
        // }
        game->start();
    } 
    else {
        // Invalid input
        cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
    }



    delete game;  // Clean up the dynamically allocated game object

    return 0;
}
