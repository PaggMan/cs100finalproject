#include "../include/game.h"
#include "../include/characterValidator.h"
#include "../include/MinesweeperMinigame.h"
#include "../include/RockPaperScissorsMinigame.h"
#include "../include/TicTacToeMinigame.h"
#include "../include/TypingMinigame.h"
#include "../include/UnscrambleMinigame.h"
#include "../include/WordleMinigame.h"

#include <fstream>
#include <unistd.h>
#include <stdexcept>
#include <random>
#include <vector>
#include <cstdlib>





Game::Game() {

    // The following is if they are loading a new game, we can skip this if they have a saved game.

    //initialize current day to 1.
    //initialize the name of the game to "My Game"

    currentDay = 1;
    name = "My Simulation";
    courseList = new Course*[4];    //Array of course pointers of size 4 initialized.
    character = nullptr;    //The character will be initialized later once the user gives the character customization information.
    
    minigameList.push_back(new MinesweeperMinigame());
    minigameList.push_back(new RockPaperScissorsMinigame());
    minigameList.push_back(new TicTacToeMinigame());
    //minigameList.push_back(new TypingMinigame());
     minigameList.push_back(new UnscrambleMinigame());
     minigameList.push_back(new WordleMinigame());
}


void Game::printCourseList() {  //Takes contents of courseCatalog.txt and outputs in formatted way.
    std::ifstream inFS;
    inFS.open("courseCatalog.txt");
    if (!inFS.is_open()) {
        throw runtime_error("Could not open courseList.txt");
    }

    int numSpaces = 0;  //To keep formatting consistent, shorter course names will have spaces added to them in the end so that courseDifficulties are under the same column.
    std::string courseName = "";
    double courseDifficulty = 0.0;
    while (inFS >> courseName) {
        std::cout << courseName;
        numSpaces = 8 - courseName.size();

        for (unsigned i = 0; i < numSpaces; ++i) {
            std::cout << ' ';
        }
        inFS >> courseDifficulty;
        std::cout << '\t' << courseDifficulty << '\n';
    }

    inFS.close();
}


void Game::chooseCourses() {   //Prompts the user to choose 4 courses
    std::cout << '\n';

    //Show list of courses
    printCourseList();

    //Prompt for 1st course
    //If 1st course is invalid ask for another input

    std::string courseName = " ";   //The user input will be stored here.
    CharacterValidator courseListValidator; //This object will be used to make sure the courseList does not contain any duplicate courses.
    bool isValidCourse = false; //This boolean variable will be used to break a loop asking the user to choose a course.
    unsigned courseListSize = 0;

    while (!isValidCourse) {
        std::cout << "\n1st course: ";
        getline(cin, courseName);
        addCourse(courseName, courseListSize);
        if (courseListSize == 1) {  //If the courseListSize changed, that means the course was successfully added.

            //Now the only thing that must be done to verify the course is to ensure that there are no duplicate courses in courseList
            if (courseListValidator.isValidCourseList(courseList, courseListSize)) {
                isValidCourse = true;
                
            }

            else {
                delete courseList[0];
                courseListSize--;
            }
        }

        else {  //The course is not in courseList so is not valid.
            std::cout << "The course you entered is not valid. Make sure you spell the course correctly as you see in the course list.\n";
        }
    }

    //Prompt for 2nd course
        //If 2nd course is invalid ask for another input

    courseName = " ";   //The user input will be stored here.
    isValidCourse = false; //This boolean variable will be used to break a loop asking the user to choose a course.

    while (!isValidCourse) {
        std::cout << "\n2nd course: ";

        getline(cin, courseName);
        addCourse(courseName, courseListSize);
        if (courseListSize == 2) {  //If the courseListSize changed, that means the course was successfully added.

            //Now the only thing that must be done to verify the course is to ensure that there are no duplicate courses in courseList
            if (courseListValidator.isValidCourseList(courseList, courseListSize)) {
                isValidCourse = true;
            }

            else {
                std::cout << "You already added " << courseList[1]->getName() << " to your list of courses. Add a different course instead!\n";
                delete courseList[1];
                courseListSize--;
            }
        }

        else {  //The course is not in courseList so is not valid.
            std::cout << "The course you entered is not valid. Make sure you spell the course correctly as you see in the course list.\n";
        }
    }


    


    //Prompt for 3rd course
        //If 3rd course is invalid ask for another input
    
    courseName = " ";   //The user input will be stored here.
    isValidCourse = false; //This boolean variable will be used to break a loop asking the user to choose a course.

    while (!isValidCourse) {
        std::cout << "\n3rd course: ";

        getline(cin, courseName);
        addCourse(courseName, courseListSize);
        if (courseListSize == 3) {  //If the courseListSize changed, that means the course was successfully added.

            //Now the only thing that must be done to verify the course is to ensure that there are no duplicate courses in courseList
            if (courseListValidator.isValidCourseList(courseList, courseListSize)) {
                isValidCourse = true;
            }

            else {
                std::cout << "You already added " << courseList[2]->getName() << " to your list of courses. Add a different course instead!\n";
                delete courseList[2];
                courseListSize--;
            }
        }

        else {  //The course is not in courseList so is not valid.
            std::cout << "The course you entered is not valid. Make sure you spell the course correctly as you see in the course list.\n";
        }
    }



    //Prompt for 4th course
        //If 4th course is invalid ask for another input

    courseName = " ";   //The user input will be stored here.
    isValidCourse = false; //This boolean variable will be used to break a loop asking the user to choose a course.

    while (!isValidCourse) {
        std::cout << "\n4th course: ";

        getline(cin, courseName);
        addCourse(courseName, courseListSize);
        if (courseListSize == 4) {  //If the courseListSize changed, that means the course was successfully added.

            //Now the only thing that must be done to verify the course is to ensure that there are no duplicate courses in courseList
            if (courseListValidator.isValidCourseList(courseList, courseListSize)) {
                isValidCourse = true;
            }

            else {
                std::cout << "You already added " << courseList[3]->getName() << " to your list of courses. Add a different course instead!\n";
                delete courseList[3];
                courseListSize--;
            }
        }

        else {  //The course is not in courseList so is not valid.
            std::cout << "The course you entered is not valid. Make sure you spell the course correctly as you see in the course list.\n";
        }
    }
}



void Game::addCourse(const std::string& courseName, unsigned& courseListSize) {  //Adds a course from courseCatalog.txt based on the user entered course name. If not found, the courseListSize variable is not incremented.
    //Open file
    ifstream inFS;
    inFS.open("courseCatalog.txt");

    //verify file is open
    if (!inFS.is_open()) {
        throw runtime_error("Failure in opening courseCatalog.txt");
    }

    //Iterate through file as long as there are still courses in the catalog and the courseListSize hasn't changed.
    unsigned originalCourseListSize = courseListSize;   //this new variable will be used to determine whether courseListSize has increased.
    std::string courseNameInCatalog = " ";  //This will store the course names found in the txt file.
    double courseDifficultyInCatalog = 0.0; //This will store the course difficulties found in the txt file.
    while (courseListSize == originalCourseListSize && inFS >> courseNameInCatalog >> courseDifficultyInCatalog) {
        //If name of course matches with one in file, store the difficulty as well in a double and store this new course object in courseList.
            //Increment courselIstSize by 1.

        if (courseName == courseNameInCatalog) {
            courseList[courseListSize] = new Course(courseNameInCatalog, courseDifficultyInCatalog);
            courseListSize++;
        }
    }

    inFS.close();
}


void Game::customizeCharacter() {  //Prompts the user to enter a name for their character.

    std::cout << "\tTo run " << name << ", you will need a character. What would you like to name this character?\n\n";

    CharacterValidator characterValidator;  //CharacterValidator will be used to determine whether or not characterName is valid.
    std::string characterName = " ";  //The name was initialized to Bob in case the user can't think of a valid character name after 3 tries.
    bool isValidName = false; //This will determine whether or not the program can exit the loop.

    do {
        std::cout << "\tName: ";
        getline(cin, characterName);
        std::cout << '\n';

        isValidName = characterValidator.isValidCharacterName(characterName);   //This stores true or false, whether or not the name is valid.

        if (!isValidName) {
            system("clear");
            std::cout << "The name you enter must not contain spaces and needs to be in between 2 to 20 characters. Please try again!\n\n";
        }
        
   }
        while(!isValidName);

    character = new Character();
    character -> setName(characterName);
    std::cout << "Character \"" << characterName << "\" created.\n";
}


Game::~Game() {
     delete character;
    
     delete courseList[0];
     delete courseList[1];
     delete courseList[2];
     delete courseList[3];
     delete[] courseList;
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

 void Game::setName(const string& name) {
    this->name = name;
 }


void Game::start() {


//Welcome message to starting a new game
    std::cout << "Hello there! Welcome to CS Student Simulator! The simulation we will be running today is \"" << name << "\".\n\n";
    
    customizeCharacter();   //This function will create a character and give it a name.


    sleep(2);
    system("clear");

    std::cout << "Hello " << character->getName() << "! You are a student at UCR in your last quarter before graduating!";
    std::cout << " For this last quarter, you decide to take four more classes.";
    std::cout << " Below are a list of classes you can take. Choose your 1st class by typing its name down below.\n";

    chooseCourses();

    system("clear");
    std::cout << "Good! It is time to begin your last quarter at UCR..." << endl;


    //(void)displayInternships();

}

void Game::gameLoop() {
    

    //Before the loop starts, the minigame objects need to be initialized and added to a vector, so that vector can later be used to
    //choose a random game.

    srand((unsigned) time(NULL));



    //While loop that iterates until currentDay reaches 30


    //Start the day


    //increment dayCounter by 1
}

void Game::runDay() {  //Allows user to make choices on a given day and calls minigame classes
    std::cout << "DAY " << currentDay << "\n\n";
    
    //Asks User if they skip class or go to class
        //If they go to class, start a minigame

    
    std::cout << "Do you skip class today or go to class? (Type 1 to skip, type 2 to go to class)\n";
    
    
    char choice = ' ';

    bool skippingClass = true;  //This will be used later to determine what path the user takes.

    while(true) {   //The loop keeps running until a valid response is Entered by the User

        std::cout << "\t1) Skip class\n\t2) Go to class\n\n\tChoice: ";
        cin >> choice;

        if (choice == '1') {
            skippingClass = true;
            break;
        }

        else if (choice == '2') {
            skippingClass = false;
            break;
        }
        
        else {
            system("clear");
            std::cout << "Invalid Response. Try Again.\n";
            cin.clear();
        }
    }


    if (!skippingClass) {   //If they don't skip, they play a minigame
        system("clear");
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        playMinigame();
    }

    //If they skip, jump to the end of the day

    //End of the day:
        //Choose a stat boosting you want
            //If you skip you can upgrade another stat.
}

void Game::playMinigame() {     //Randomly chooses a minigame to play
    srand(time(NULL));
    minigameList.at(rand()%5)->initialize();
}

void Game::giveInstructions() {
    // run all the days of the game here.


    //Give introduction message about what it being your last quarter and how this quarter determines your job prospects.
    //Tells user to stay as happy as possible and shows them stat bars
        //Display stat bars
    //Explains the user will have decisions to make that will alter these stat bars and also minigames to play to make upgrades.
}

std::vector<Internship> Game::parseInternships(string tier) {
    std::vector<Internship> internships;

    std::ifstream ifs;
    ifs.open("gamedata/internships.json");
    if (!ifs.is_open()) {
        std::cout << "Failed to open the JSON file." << std::endl;
        throw runtime_error("error reading file");
    }

    Json::Value root;
    Json::Reader reader;
    if (!reader.parse(ifs, root)) {
        std::cout << "Failed to parse the JSON file." << std::endl;
        ifs.close();
        throw runtime_error("error reading file");
    }

    Json::Value tierInternships = root[tier];

    if (tierInternships.isNull()) {
        std::cout << "Invalid tier specified." << std::endl;
        ifs.close();
        throw runtime_error("invalid tier specified.");
    }

    for (Json::Value::ArrayIndex i = 0; i < tierInternships.size(); ++i) {
        Json::Value internship = tierInternships[i];
        Internship newInternship;
        newInternship.title = internship["title"].asString();
        newInternship.company = internship["company"].asString();
        newInternship.startingWage = internship["starting_wage"].asString();
        newInternship.welcomeMessage = internship["welcome_message"].asString();
        internships.push_back(newInternship);
        // cout << newInternship.title << endl;
    }

    ifs.close();
    return internships;
}

void Game::displayInternships() {
    system("clear");
    cout << "Loading your internship opportunity..." <<endl;
    clearAndLoad();

    string tier = calculateScore();
    std::vector<Internship> possibleInternships = parseInternships(tier);


    // int randIndex = rand() % possibleInternships.size();
    // Internship theInternship = possibleInternships.at(randIndex); broken
    Internship theInternship = getRandomFromVector(possibleInternships);
 
    cout << "Congratulations! With your cumulative game score of " << this->character->getGrades() + this->character->getHappiness() + this->character->getHappiness() << ", ";
    cout << "You've been offered an internship at " << theInternship.company << "!\n\n";
    cout << "Here's a message from the hiring team: "<< endl << endl << theInternship.welcomeMessage << "\n\n\n";
    cout << "Your starting wage is " << theInternship.startingWage << "\n\n\n";




}
template<class T>
T Game::getRandomFromVector(const std::vector<T>& v) {
    // Initialize random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Generate a random index within the range of the vector size
    std::uniform_int_distribution<> dist(0, v.size() - 1);
    int randomIndex = dist(gen);
    
    // Return the random Internship
    return v[randomIndex];
}

string Game::calculateScore() {
    int overallScore = this->character->getGrades() + this->character->getHappiness() + this->character->getHappiness();

    if(overallScore > 280) {
        return "legendary";
    } else if(overallScore > 250) {
        return "epic";
    } else if(overallScore > 200) {
        return "good";
    } else if(overallScore > 140) {
        return "satisfactory";
    } else {
        return "poor";
    }

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
    sleep(1.5);
    system("clear");
}




