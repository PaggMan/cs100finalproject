#include "../include/game.h"
// #include "../include/character.h"

#include <fstream>

Game::Game() {
    std::cout << "New game started" << std::endl;
    character = new Character();
    currentDay = 0;
}

Game::~Game() {
    delete character;
}

void Game::load(string fileName) {
    std::ifstream file;
    file.open(fileName);

    if(!file.is_open()) throw std::runtime_error("Could not read file.");

}

void Game::save() {
    std::ofstream file;
    file.open(name + ".json");

}

void Game::start() {
    
}
