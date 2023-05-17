#include <iostream>
#include "../include/game.h"
#include <experimental/filesystem>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>

namespace fs = std::experimental::filesystem;
using namespace ftxui;

int main() {
    // // Initialize FTXUI screen
    // auto screen = Screen(100, 100);

    // // Create UI elements
    // auto title = text(L"College Student Simulator") | bold | hcenter;
    // auto menu = hbox({
    //     text(L"1. New Game"),
    //     text(L"2. Load Game"),
    //     text(L"3. Quit"),
    // }) | hcenter;
    // auto container = vbox({
    //     title,
    //     separator(),
    //     menu,
    // }) | yflex;

    // // Render the UI
    // Render(container, &screen);

    // // Refresh the screen
    // screen.Print();

    // // Wait for user input
    // bool quit = false;
    // while (!quit) {
    //     // Read user input
    //     auto input = screen.GetEvent();

    //     if (input == Event::Character('1')) {
    //         // Start new game
    //         std::cout << "Starting new game..." << std::endl;
    //         Game* game = new Game();
    //         quit = true;
    //     } else if (input == Event::Character('2')) {
    //         // Load saved game
    //         std::cout << "Loading saved game..." << std::endl;
    //         quit = true;
    //     } else if (input == Event::Character('3')) {
    //         // Quit game
    //         std::cout << "Quitting game..." << std::endl;
    //         quit = true;
    //     }
    // }
 
  // Define the document
  Element document =
    hbox({
      text("left")   | border,
      text("middle") | border | flex,
      text("right")  | border,
    });
 
  auto screen = Screen::Create(
    Dimension::Full(),       // Width
    Dimension::Fit(document) // Height
  );
  Render(screen, document);
  screen.Print();
 
  return EXIT_SUCCESS;

    

    return 0;
}