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

  // Create the New Game button.
  bool renderScreens = true;
  auto gameTitle = text(L"CS Student Simulator") | bold | hcenter | color(Color::Green);
  Component new_game_button = Button("New Game", [] {
      // On button click
      std::string gameName;

      Component inputGameName = Input(&gameName, "My Game #1");
      Component test = Input(&gameName, "Name the game");




      Component submitButton = Button("Ready", [&] {
      // On submit button click
        if (!gameName.empty()) {
          // Game name is not empty, do something with it
          Game* game = new Game();
          game->setName(gameName);
          game->save();
        }
      });
      
      auto newGameComponents = Container::Vertical({
        inputGameName,
        submitButton
      });

      auto newGameScreen = Renderer(newGameComponents, [&] {
      return vbox({
          text("What would you like to name your game"),
          separator(),
          // hbox(text(" Name of game: "), inputGameName->Render()),
          hbox(inputGameName->Render()),
          separator(),
          hbox(submitButton->Render())
     }) | border;


      });
 
      auto screen = ScreenInteractive::Fullscreen();
      screen.Loop(newGameScreen);


      



  });

  // Create the Load Game button.
  Component load_game_button = Button("Load Game", [] {
    // On button click
    // Display the dropdown with saved games
  });

  // Create the container to hold the buttons.
  auto buttons = Container::Vertical({
    new_game_button,
    load_game_button,
  });

  auto titleScreen = Renderer(buttons, [&] {
    return vbox({
               gameTitle,
               separator(),
               buttons->Render(),
           }) |
           border;
  });

  // Create the screen and render the container.
  auto screen = ScreenInteractive::Fullscreen();
  screen.Loop(titleScreen);

  return 0;
}
