#include <iostream>
#include "../include/game.h"
#include <experimental/filesystem>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <unistd.h>


namespace fs = std::experimental::filesystem;
using namespace ftxui;
 
int main() {
 system("clear");

 Game g;

 /*cout << " _____  _____   _____ _             _            _     _____ _                 _       _             " << endl;
 cout << "/  __ \\/  ___| /  ___| |           | |          | |   /  ___(_)               | |     | |            " << endl;
 cout << "| /  \\/\\ `--.  \\ `--.| |_ _   _  __| | ___ _ __ | |_  \\ `--. _ _ __ ___  _   _| | __ _| |_ ___  _ __ " << endl;
 cout << "| |     `--. \\  `--. \\ __| | | |/ _` |/ _ \\ '_ \\| __|  `--. \\ | '_ ` _ \\| | | | |/ _` | __/ _ \\| '__|" << endl;
 cout << "| \\__/\\/\\__/ / /\\__/ / |_| |_| | (_| |  __/ | | | |_  /\\__/ / | | | | | | |_| | | (_| | || (_) | |   " << endl;
 cout << " \\____/\\____/  \\____/ \\__|\\__,_|\\__,_|\\___|_| |_|\\__| \\____/|_|_| |_| |_|\\__,_|_|\\__,_|\\__\\___/|_|   " << endl;
 cout << "\n\n\n\n\n";



cout << "1. New game\n";
cout << "2. Load game\n";
cout << "\n\n\n\n";
char userinput;
cout << "Enter an option: "; cin >> userinput;


if(userinput == '1') {
     system("clear");
     cout << "Starting new game..." << endl;
     sleep(1.5);
     system("clear");
     cin.clear();
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
     Game* game = new Game();
     game->start();
} else if(userinput == '2') {
  Game* game = new Game();
  game->load("../gamedata/game.json");
  system("clear");
  cout << "Loading game..." << endl;
  sleep(1.5);
  system("clear");
  cout << "Welcome back, " << game->getCharacter()->getName() << endl;

} else {
  cout << "in development";
}*/

  // bool showNewGameScreen = true; // Flag to control the new game screen visibility

  // auto gameTitle = text(L"CS Student Simulator") | bold | hcenter | color(Color::Green);
  // Component new_game_button = Button("New Game", [&] {
  //     // On button click
  //     std::string gameName;

  //     Component inputGameName = Input(&gameName, "My Game #1");
  //     Component test = Input(&gameName, "Name the game");
  //     Component submitButton = Button("Ready", [&] {
  //     // On submit button click
  //       if (!gameName.empty()) {
  //         // Game name is not empty, do something with it
  //         Game* game = new Game();
  //         game->setName(gameName);
  //         game->save();
  //         showNewGameScreen = false; // Hide the new game screen

  //         // buttons = Container::Vertical({}); // Set the component to an empty container
  //         // screen.PostEvent(Event::Custom); // Trigger a custom event to force a redraw

          
  //       // From this point on, the game object can handle the game screens
  //       }
  //     });
      
  //     auto newGameComponents = Container::Vertical({
  //       inputGameName,
  //       submitButton
  //     });

  //     auto newGameScreen = Renderer(newGameComponents, [&] {
  //     return vbox({
  //         text("What would you like to name your game"),
  //         separator(),
  //         // hbox(text(" Name of game: "), inputGameName->Render()),
  //         hbox(inputGameName->Render()),
  //         separator(),
  //         hbox(submitButton->Render())
  //    }) | border;


  //     });
 
  //     auto screen = ScreenInteractive::Fullscreen();
  //     screen.Loop(newGameScreen);


      



  // });

  // // Create the Load Game button.
  // Component load_game_button = Button("Load Game", [] {
  //   // On button click
  //   // Display the dropdown with saved games
  // });

  // // Create the container to hold the buttons.
  // auto buttons = Container::Vertical({
  //   new_game_button,
  //   load_game_button,
  // });

  // auto titleScreen = Renderer(buttons, [&] {
  //   if(showNewGameScreen) {
  //     return vbox({
  //           gameTitle,
  //           separator(),
  //           buttons->Render(),
  //       }) |
  //     border;
  //   }
  //   else { // clear the screen
  //    return vbox({}) | border;
  //   }
  // });

  // // Create the screen and render the container.
  // auto screen = ScreenInteractive::Fullscreen();
  // screen.Loop(titleScreen);
}
