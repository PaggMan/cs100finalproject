#include <iostream>
#include "../include/game.h"
#include <experimental/filesystem>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
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
 
  std::vector<std::string> entries = {
      "tribute",     "clearance", "ally",        "bend",        "electronics",
      "module",      "era",       "cultural",    "sniff",       "nationalism",
      "negotiation", "deliver",   "figure",      "east",        "tribute",
      "clearance",   "ally",      "bend",        "electronics", "module",
      "era",         "cultural",  "sniff",       "nationalism", "negotiation",
      "deliver",     "figure",    "east",        "tribute",     "clearance",
      "ally",        "bend",      "electronics", "module",      "era",
      "cultural",    "sniff",     "nationalism", "negotiation", "deliver",
      "figure",      "east",
  };
 
  int selected_1 = 0;
  int selected_2 = 0;
  int selected_3 = 0;
  int selected_4 = 0;
 
  auto layout = Container::Vertical({
      Container::Horizontal({
          Dropdown(&entries, &selected_1),
          Dropdown(&entries, &selected_2),
      }),
      Container::Horizontal({
          Dropdown(&entries, &selected_3),
          Dropdown(&entries, &selected_4),
      }),
  });
 
  auto screen = ScreenInteractive::FitComponent();
  screen.Loop(layout);

    return 0;
}