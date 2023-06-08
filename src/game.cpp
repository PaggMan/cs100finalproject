#include "../include/game.h"
#include "../include/characterValidator.h"
#include <fstream>
#include <unistd.h>
#include <stdexcept>

Game::Game() {
    //initialize current day to 1.
    //initialize the name of the game to "My Game"

    //Give welcome message    

    //ask user to enter character name
    //make sure that the entered name is valid. If not valid, ask again.
        //****I'm thinking of adding a feature where if the user enters 3 invalid names in a row, the game assigns the player a default name.
    

    //Show a list of courses the user can choose from
    //Ask the user to choose 4 courses by entering the name of a course.
        //A list of courses will be located in a txt file, where they can either be outputted to the screen and read from to create a new course.
        //A course validator must exist in order to determine whether a selected course actually exists, or if there is a duplicate course somewhere in your list.
    


    //2 of the 4 private member variables are being initialized here. 
    currentDay = 1;
    name = "My Simulation";
    //Character and CourseList will be initialized later because they first require user input.



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
    std::cout << "Good! It is time to begin your last quarter at UCR...";
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

    courseList = new Course*[4];    //Array of course pointers of size 4 initialized.

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

