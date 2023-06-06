#include "../include/game.h"
// #include "../include/character.h"
#include <unistd.h>
#include <fstream>

Game::Game() {
    character = new Character();
    currentDay = 0;
}

Game::~Game() {
    delete character;
}

void Game::load(string fileName) {

    std::ifstream file("gamedata/game.json");
    Json::Value gameData;
    file >> gameData;
    file.close();

    Json::Value characterData = gameData["character"];
    std::string name = characterData["name"].asString();
    int grades = characterData["grades"].asInt();
    int happiness = characterData["happiness"].asInt();
    int health = characterData["health"].asInt();

    character = new Character();
    character->setName(name);
    character->setGrades(grades);
    character->setHappiness(happiness);
    character->setHealth(health);

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
    game["name"] = "College Student Simulator";
    

    // Write the JSON to a file
    Json::StyledWriter writer;
    std::string jsonString = writer.write(game);
    std::ofstream file("gamedata/game.json");
    file << jsonString;
    file.close();


}



void Game::start() {
    cout << "Enter a name for your character: ";
    character->promptForName();
    clearAndLoad();
    cout << "Hi there, " << character->getName() << endl;
    cout << "Type 1 to begin the game" << endl;
    string garbage;
    cin >> garbage;
    save();
    gameLoop();

}

void Game::gameLoop() {
    // run all the days of the game here.
}


// Getters and setters
Character* Game::getCharacter() {
    return this->character;
}

std::string Game::getName() {
    return this->name;
}

int Game::getCurrentDay() {
    return this->currentDay;
}

void Game::clearAndLoad() {
    system("clear");
    sleep(1.5);
}

