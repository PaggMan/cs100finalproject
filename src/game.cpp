#include "../include/game.h"
// #include "../include/character.h"

#include <fstream>

Game::Game() {
    std::cout << "New game started" << std::endl;
    character = new Character();
    currentDay = 0;
    name = "";
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
    // Write character data
    Json::Value characterToWrite;
    characterToWrite["name"] = character->getName();
    characterToWrite["grades"] = character->getGrades();
    characterToWrite["happiness"] = character->getHappiness();
    characterToWrite["health"] = character->getHealth();

    // Create a JSON object for the game
    Json::Value game;
    game["character"] = characterToWrite;
    game["version"] = "1.0";
    game["name"] = name;
    

    // Write the JSON to a file
    Json::StyledWriter writer;
    std::string jsonString = writer.write(game);
    std::ofstream file("gamedata/game.json");
    file << jsonString;
    file.close();


}

void Game::start() {
    
}

void Game::setName(const string& name) {this->name = name;}
