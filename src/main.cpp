// #include <ftxui/screen/screen.hpp>
#include <iostream>
using namespace std;
 
// int main(void) {
//   using namespace ftxui;
//   auto screen = Screen::Create(Dimension::Fixed(32), Dimension::Fixed(10));
 
//   auto& pixel = screen.PixelAt(9,9);
//   pixel.character = U'A';
//   pixel.bold = true;
//   pixel.foreground_color = Color::Blue;
 
//   std::cout << screen.ToString();
//   return EXIT_SUCCESS;
// }

// ^ this shit don't work


int main() {
    std::cout << "\033[1;31m";
    std::cout << "  ____        _     _ _     _____ _                 \n";
    std::cout << " / ___| _ __ (_) __| (_)___|  ___(_)_ __   ___ ___ \n";
    std::cout << " \\___ \\| '_ \\| |/ _` | / __| |_  | | '_ \\ / __/ _ \\\n";
    std::cout << "  ___) | |_) | | (_| | \\__ \\  _| | | |_) | (_|  __/\n";
    std::cout << " |____/| .__/|_|\\__,_|_|___/_|   |_| .__/ \\___\\___|\n";
    std::cout << "       |_|                        |_|              \n";
    std::cout << "\033[0m";
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
    // Process user input
    switch(choice) {
        case 1:
            // Start new game
            cout << "Starting new game..." << endl;
            break;
        case 2:
            // Load saved game
            cout << "Loading saved game..." << endl;
            break;
        case 3:
            // Quit game
            cout << "Quitting game..." << endl;
            return 0;
        default:
            // Invalid input
            cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
            break;
    }
    return 0;
}