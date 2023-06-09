#include <filesystem>
#include <vector>
#include <string>
#include <iostream>
namespace fs = std::filesystem;

class GameManager {
    private:
    vector<string> savedGames;
    vector<string> savedGameTitles;
    unsigned gameToLoadIndex;





    

    public:

    void handleGameLoad() {
        unsigned fileCtr = 1;
        for (const auto& entry : fs::directory_iterator("gamedata/savedgames")) {
            // Check if the entry is a regular file
            if (entry.is_regular_file()) {
                savedGames.push_back(entry.path().string());
                savedGameTitles.push_back(entry.path().stem().string());
                // std::cout << "  " << fileCtr << ". "<< entry.path().stem().string() << std::endl;
                // fileCtr++;
            }
        }

        if(savedGames.size() == 0) {
            throw std::runtime_error("Could not find any previous saved game files. Please start a new game instead.");
        }

        return;
    }


    void printOptions() {
        unsigned index = 1;
        for(const string& x : savedGameTitles) {
            cout << "  " << index << ". " << x << endl;
            index++;
        }
        cout << endl << endl;

        int userChoice;
        cout << "Type out the number corresponding to the game you want to load: "; cin >> userChoice;
        if(userChoice > savedGames.size() || userChoice < 1) 
            throw std::out_of_range("Invalid option");
        gameToLoadIndex = userChoice -1; // subtract 1 cuz index starts at 0
    }

    std::string getGameFile() {
        return savedGames[gameToLoadIndex];
    }

    unsigned getNumGames() {
        return savedGames.size();
    }
};


