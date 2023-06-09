#include <iostream>
#include "../include/game.h"
#include "../include/print.h"
// #include <experimental/filesystem>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <unistd.h>
#include "../include/loadgame.h"
#include <thread>


using namespace ftxui;



bool noSpacesInName(const std::string& name) {
  if (name.size() == 0) {
    return false;
  }

  for (unsigned i = 0; i < name.size(); ++i) {
    if (name.at(i) == ' ' || name.at(i) == '\t' || name.at(i) == '\n') {
      return false;
    }
  }
  return true;
}
 
int main() {
 system("clear");
cout << "\033[1;36m";
 cout << " _____  _____   _____ _             _            _     _____ _                 _       _             " << endl;
 
 cout << "/  __ \\/  ___| /  ___| |           | |          | |   /  ___(_)               | |     | |            " << endl;
 cout << "| /  \\/\\ `--.  \\ `--.| |_ _   _  __| | ___ _ __ | |_  \\ `--. _ _ __ ___  _   _| | __ _| |_ ___  _ __ " << endl;
 cout << "| |     `--. \\  `--. \\ __| | | |/ _` |/ _ \\ '_ \\| __|  `--. \\ | '_ ` _ \\| | | | |/ _` | __/ _ \\| '__|" << endl;
 cout << "| \\__/\\/\\__/ / /\\__/ / |_| |_| | (_| |  __/ | | | |_  /\\__/ / | | | | | | |_| | | (_| | || (_) | |   " << endl;
 cout << " \\____/\\____/  \\____/ \\__|\\__,_|\\__,_|\\___|_| |_|\\__| \\____/|_|_| |_| |_|\\__,_|_|\\__,_|\\__\\___/|_|   " << endl;
 cout << "\n\n\n\n\n";
  cout << "\033[0m\n" << endl;


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

     //Recieve user input for the name of the game
     //The user should keep on being asked for a name until they enter a name without spaces, tabs, or newlines.
     string name = " ";
     while (true) {
        std::cout << "Choose a name for the game (this is what the game will be saved as): ";
        getline(cin, name);
        if (noSpacesInName(name)) {
          game -> setName(name);
          break;
        }
        //If the name had spaces, the user is asked to enter another name.
        system("clear");
        std::cout << "Invalid Response. Make sure to not put any spaces in the name.\n\n";
     }
     system("clear");
     
     //game->giveInstructions();
     game->start();

     try {
        game->gameLoop();
     }

     catch(std::runtime_error& e) {
        delete game;
        return 1;
     }



    //  game->displayInternships(); we moved this into gameloop so the game class handles the entirety of the game

     delete game;

} else if(userinput == '2') {
    system("clear");
    cout << "Looking for saved games..." << endl;
    sleep(1.5);
    system("clear");
    GameManager gm = GameManager();
    try {
          gm.handleGameLoad();
    } catch(std::runtime_error& e) {
      cout << e.what() << endl;
      return 0;
    }

    bool rePrint = false;
    do {
      try {
        cout << "Found " << gm.getNumGames() << " saved games." << endl;
        gm.printOptions();
      } catch(std::out_of_range& e) {
        cout << "\n\nInvalid option." << endl;
        sleep(1);
        system("clear");
        rePrint = true;
      }
          
    } while(rePrint);


    string fileToLoad = gm.getGameFile();


    Game* game = new Game();
    try {
      game->load(fileToLoad); // goes into game
    }
    catch(std::runtime_error& e) {
      delete game;
      return 0;
    }
    /*
    Everything below here should be handled by the load function
    */
    // cout << "Loading game..." << endl;
    // sleep(1.5);
    // system("clear");
    // cout << "Welcome back, " << game->getCharacter()->getName() << endl;

    delete game;
  

} else {
  cout << "in development";
}

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
  return 0;
}
