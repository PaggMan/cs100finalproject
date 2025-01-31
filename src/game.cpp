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
        output = courseName;
        outputObject.printStaggeredOutput(output, 10);
        numSpaces = 8 - courseName.size();

        for (unsigned i = 0; i < numSpaces; ++i) {
            output = ' ';
            outputObject.printStaggeredOutput(output, 10);
        }
        inFS >> courseDifficulty;
        
        outputObject.handleColor(static_cast<int>(courseDifficulty));
        output = '\t' + to_string(courseDifficulty);
        outputObject.printStaggeredOutput(output, 10);
        outputObject.handleColor(-1);
    }

    inFS.close();
}


void Game::chooseCourses() {   //Prompts the user to choose 4 courses
    output = "\n";
    outputObject.printOutput(output);

    //Show list of courses
    printCourseList();

    //Prompt for 1st course
    //If 1st course is invalid ask for another input

    std::string courseName = " ";   //The user input will be stored here.
    CharacterValidator courseListValidator; //This object will be used to make sure the courseList does not contain any duplicate courses.
    bool isValidCourse = false; //This boolean variable will be used to break a loop asking the user to choose a course.
    unsigned courseListSize = 0;

    while (!isValidCourse) {
        output = "\n1st course: ";
        outputObject.printOutput(output);

        getline(cin, courseName);
        addCourse(courseName, courseListSize);
        if (courseListSize == 1) {  //If the courseListSize changed, that means the course was successfully added.

            //Now the only thing that must be done to verify the course is to ensure that there are no duplicate courses in courseList
            if (courseListValidator.isValidCourseList(courseList, courseListSize)) {
                isValidCourse = true;
                // adfasfdjsalkf
            }

            else {
                delete courseList[0];
                courseListSize--;
            }
        }

        else {  //The course is not in courseList so is not valid.
            output = "The course you entered is not valid. Make sure you spell the course correctly as you see in the course list.\n";
            outputObject.printOutput(output);
        }
    }

    //Prompt for 2nd course
        //If 2nd course is invalid ask for another input

    courseName = " ";   //The user input will be stored here.
    isValidCourse = false; //This boolean variable will be used to break a loop asking the user to choose a course.

    while (!isValidCourse) {
        output = "\n2nd course: ";
        outputObject.printOutput(output);

        getline(cin, courseName);
        addCourse(courseName, courseListSize);
        if (courseListSize == 2) {  //If the courseListSize changed, that means the course was successfully added.

            //Now the only thing that must be done to verify the course is to ensure that there are no duplicate courses in courseList
            if (courseListValidator.isValidCourseList(courseList, courseListSize)) {
                isValidCourse = true;
            }

            else {
                output = "You already added " + courseList[1]->getName() + " to your list of courses. Add a different course instead!\n";
                outputObject.printOutput(output);
                delete courseList[1];
                courseListSize--;
            }
        }

        else {  //The course is not in courseList so is not valid.
            output = "The course you entered is not valid. Make sure you spell the course correctly as you see in the course list.\n";
            outputObject.printOutput(output);
        }
    }


    


    //Prompt for 3rd course
        //If 3rd course is invalid ask for another input
    
    courseName = " ";   //The user input will be stored here.
    isValidCourse = false; //This boolean variable will be used to break a loop asking the user to choose a course.

    while (!isValidCourse) {
        output = "\n3rd course: ";
        outputObject.printOutput(output);

        getline(cin, courseName);
        addCourse(courseName, courseListSize);
        if (courseListSize == 3) {  //If the courseListSize changed, that means the course was successfully added.

            //Now the only thing that must be done to verify the course is to ensure that there are no duplicate courses in courseList
            if (courseListValidator.isValidCourseList(courseList, courseListSize)) {
                isValidCourse = true;
            }

            else {
                output = "You already added " + courseList[2]->getName() + " to your list of courses. Add a different course instead!\n";
                outputObject.printOutput(output);

                delete courseList[2];
                courseListSize--;
            }
        }

        else {  //The course is not in courseList so is not valid.
            output = "The course you entered is not valid. Make sure you spell the course correctly as you see in the course list.\n";
            outputObject.printOutput(output);
        }
    }



    //Prompt for 4th course
        //If 4th course is invalid ask for another input

    courseName = " ";   //The user input will be stored here.
    isValidCourse = false; //This boolean variable will be used to break a loop asking the user to choose a course.

    while (!isValidCourse) {
        output = "\n4th course: ";
        outputObject.printOutput(output);

        getline(cin, courseName);
        addCourse(courseName, courseListSize);
        if (courseListSize == 4) {  //If the courseListSize changed, that means the course was successfully added.

            //Now the only thing that must be done to verify the course is to ensure that there are no duplicate courses in courseList
            if (courseListValidator.isValidCourseList(courseList, courseListSize)) {
                isValidCourse = true;
            }

            else {
                output = "You already added " + courseList[3]->getName() + " to your list of courses. Add a different course instead!\n";
                outputObject.printOutput(output);
                delete courseList[3];
                courseListSize--;
            }
        }

        else {  //The course is not in courseList so is not valid.
            output = "The course you entered is not valid. Make sure you spell the course correctly as you see in the course list.\n";
            outputObject.printOutput(output);
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

    output = "\tTo run " + name + ", you will need a character. What would you like to name this character?\n\n";
    outputObject.printOutput(output);

    CharacterValidator characterValidator;  //CharacterValidator will be used to determine whether or not characterName is valid.
    std::string characterName = " ";  //The name was initialized to Bob in case the user can't think of a valid character name after 3 tries.
    bool isValidName = false; //This will determine whether or not the program can exit the loop.

    do {
        output = "\tName: ";
        outputObject.printOutput(output);
        getline(cin, characterName);
        outputObject.printNewline();

        isValidName = characterValidator.isValidCharacterName(characterName);   //This stores true or false, whether or not the name is valid.

        if (!isValidName) {
            system("clear");
            output = "The name you enter must not contain spaces and needs to be in between 2 to 20 characters. Please try again!\n\n";
            outputObject.printOutput(output);
        }
        
   }
        while(!isValidName);

    character = new Character();
    character -> setName(characterName);
    output = "Character \"" + characterName + "\" created.\n";
    outputObject.printOutput(output);
}


Game::~Game() {
     delete character;
    
     delete courseList[0];
     delete courseList[1];
     delete courseList[2];
     delete courseList[3];
     delete[] courseList;

    for (Minigame* x: minigameList) {
        delete x;
    }

    /*for (unsigned i = 0; i < minigameList.size(); ++i) {
        delete minigameList.at(i);
    }*/
}

void Game::load(string fileName) {

    // std::ifstream file("gamedata/game.json");
    std::ifstream file(fileName);
    Json::Value gameData;
    file >> gameData;
    file.close();

    Json::Value characterData = gameData["character"];

    std::string name = characterData["name"].asString();
    int grades = characterData["grades"].asInt();
    int happiness = characterData["happiness"].asInt();
    int health = characterData["health"].asInt();
    this->currentDay = gameData["currentDay"].asInt();

    character = new Character();
    character->setName(name);
    character->setGrades(grades);
    character->setHappiness(happiness);
    character->setHealth(health);
    this->name = gameData["name"].asString();

    courseList[0] = new Course("Class", 5.0);
    courseList[1] = new Course("Class", 5.0);
    courseList[2] = new Course("Class", 5.0);
    courseList[3] = new Course("Class", 5.0);

    output = "Loading your game...\n";
    outputObject.printOutput(output);
    sleep(1.5);
    system("clear");
    output = "Welcome back to UCR, " + character->getName() + "\n";
    outputObject.printOutput(output);
    gameLoop();
    return;
}

void Game::save(string fileName) {

    string fileNameToSave;
    if(fileName == "") fileNameToSave = "gamedata/game";
    else fileNameToSave = "gamedata/savedgames/" + fileName + ".json";
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
    game["currentDay"] = currentDay;
    game["name"] = fileName;
    

    // Write the JSON to a file
    Json::StyledWriter writer;
    std::string jsonString = writer.write(game);
    // std::ofstream file("gamedata/game.json");
    std::ofstream file(fileNameToSave);
    file << jsonString;
    file.close();
    output = "\n\nSaving game...\n";
    outputObject.printOutput(output);
    clearAndLoad();
    output = "Successfully saved game to " + fileNameToSave + "\n\n";
    outputObject.printOutput(output);


    //delete this;


}

 void Game::setName(const string& name) {
    this->name = name;
 }


void Game::start() {

//Welcome message to starting a new game
    output = "Hello there! Welcome to CS Student Simulator! The simulation we will be running today is \"" + name + "\".\n\n";
    outputObject.printOutput(output);
    customizeCharacter();   //This function will create a character and give it a name.


    sleep(2);
    system("clear");

    output = "Hello " + character->getName() + "! You are a student at UCR in your last quarter before graduating!";
    output += " For this last quarter, you decide to take four more classes.";
    output += " Below are a list of classes you can take. Choose your 1st class by typing its name down below.\n";
    outputObject.printOutput(output);

    chooseCourses();

    system("clear");
    output += "Good! It is time to begin your last quarter at UCR...\n";
    outputObject.printOutput(output);

    //(void)displayInternships();

}

void Game::gameLoop() {

    srand(time(NULL));
    //While loop that iterates until currentDay reaches 30

    for (currentDay; currentDay <= 15; ++currentDay) {
        if (name == "==") {
            currentDay = 15;
        }
        system("clear");
        runDay();
    }
    // build suspense here
    system("clear");
    outputObject.printStaggeredOutput("You just finished your last day at UCR!\n\n\n", 25);
    sleep(1.5);
    outputObject.printStaggeredOutput("Now it's time to see what internship offers you got!\n\n", 25);
    sleep(1.5);
    displayInternships();
    this->save(this->name);
}


void Game::runDay() {  //Allows user to make choices on a given day and calls minigame classes

    output = "DAY " + to_string(currentDay) + "\n\n";
    outputObject.printOutput(output);
    
    //Asks User if they skip class or go to class
        //If they go to class, start a minigame

    
    output = "Do you skip class today or go to class? (Type 1 to skip, type 2 to go to class)\n";
    outputObject.printOutput(output);
    
    
    char choice = ' ';

    bool skippingClass = true;  //This will be used later to determine what path the user takes.

    while(true) {   //The loop keeps running until a valid response is Entered by the User

        output = "\t1) Skip class\n\t2) Go to class\n\n\tChoice: ";
        outputObject.printOutput(output);
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
            output = "Invalid Response. Try Again.\n";
            outputObject.printOutput(output);
            cin.clear();
        }
    }


    if (!skippingClass) {   //If they don't skip, they play a minigame
        system("clear");
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        playMinigame();
        sleep(3);
    }
    //If they skip, give the character an upgrade and jump to the end of the day 
    else {
        system("clear");
        printLobby();
        sleep(3);
    }

    //End of the day:
        //Show Lobby
        //Choose a stat boosting you want
            //If you skipped class you can upgrade another stat.
    system("clear");
    output = "End of day " + to_string(currentDay) + "\n\n";
    outputObject.printOutput(output);
    sleep(1);
    printLobby();
    sleep(3);
}


void Game::playMinigame() {     //Randomly chooses a minigame to play
    int randomIndex = rand()%5;
    minigameList.at(randomIndex)->initialize();
    if(minigameList.at(randomIndex)->getResult()) {
        character->setGrades(character->getGrades() + 10);
    }
    else {
        character->setGrades(character->getGrades() - 5);
    }
    delete minigameList.at(randomIndex);
    
    if (randomIndex == 0) {
        minigameList.at(randomIndex) =  new MinesweeperMinigame();
    }

    else if (randomIndex == 1) {
        minigameList.at(randomIndex) = new RockPaperScissorsMinigame();
    }

    else if (randomIndex == 2) {
        minigameList.at(randomIndex) = new TicTacToeMinigame();
    } 

    else if (randomIndex == 3) {
        minigameList.at(randomIndex) = new UnscrambleMinigame();
    }

    else if (randomIndex == 4) {
        minigameList.at(randomIndex) = new WordleMinigame();
    }
}

void Game::giveInstructions() {

    // run all the days of the game here.
    string text1 = "Welcome to UCR! You just finished your 2nd quarter as a fourth year computer science major and things are starting to heat up...\n\n";
    string text2 = "Keeping your work-life balance has always been quite the task... \nThere's just so many things to do in a day...\n";
    string text3 = "This game will be a simulation of keeping your life 'intact' before you graduate. You'll have to balance your happiness levels, health, and grades all while worrying about jobs for when you graduate. And you definitely don't want to spend your life cleaning toilets for the night shift at the local McDonalds...\n\n";
    string text4 = "When you start this game, you'll be at the point where there's only 15 days left before graduation, and everyday, you'll always be busy with something\n";
    string text5 = "A typical day in this game consists of choosing whether to attend your classes for the day or not, and then doing a nighttime activity to work on various aspects of your status as a student.\n";
    string text6 = "If you decide to go to class, you'll play one of the of the many minigames in this game. If you win, you will gain 'academic points' that will help your academic status.\n But be careful, if you lose, you might see a dip in your GPA.\n";
    string text7 = "If you opt not to go to class, you will have an option to do a daytime activity. These all can affect in various ways your health, happiness, and grades.\n\nYou'll still have the nightime activity too!";
    string text8 = "At the end of the day, you'll be sent to your room where you can view your stats, and plan accordingly the next day in order to be at your best state.\n";
    string text9 = "At the end of the 15 days, your status as a student will be used to determine your job opportunity. The better your stats, the better your wage and opportunity!";
    string text10 = "In calculating your standardized score as a student, different categories will be weighted differently, so make sure you don't slack off on your grades.";
    string text11 = "Not studying/going to class will lower your grades category so make sure you keep an eye out on that.";

    outputObject.printStaggeredOutput(text1, 25); // in milliseconds
    outputObject.printStaggeredOutput("\n\n\n", 150);
    outputObject.printStaggeredOutput(text2, 25);
    outputObject.printStaggeredOutput("\n\n\n", 150);
    outputObject.printStaggeredOutput(text3+text4, 25);
    outputObject.printStaggeredOutput("\n\n\n", 150);
    outputObject.printStaggeredOutput(text5+text6, 25);
    outputObject.printStaggeredOutput("\n\n\n", 150);
    outputObject.printStaggeredOutput(text7, 25);
    outputObject.printStaggeredOutput("\n\n\n", 150);
    outputObject.printStaggeredOutput(text8, 25);
    outputObject.printStaggeredOutput("\n\n\n", 150);
    outputObject.printStaggeredOutput(text9, 25);
    outputObject.printStaggeredOutput("\n\n\n", 150);
    outputObject.printStaggeredOutput(text10, 25);
    outputObject.printStaggeredOutput("\n\n\n", 150);
    outputObject.printStaggeredOutput(text11, 25);
    outputObject.printStaggeredOutput("\n\n\n", 150);
    outputObject.printOutput("\n\n\n");


    //Give introduction message about what it being your last quarter and how this quarter determines your job prospects.
    //Tells user to stay as happy as possible and shows them stat bars
        //Display stat bars
    //Explains the user will have decisions to make that will alter these stat bars and also minigames to play to make upgrades.


    // Very end
    outputObject.printStaggeredOutput("Ok, you seem good to go!", 25);
    outputObject.printStaggeredOutput("\n\n\n", 150);
    outputObject.printStaggeredOutput("Its time to start your last quarter here at UCR!", 25);
    outputObject.printStaggeredOutput("\n\n\n", 150);
    outputObject.printStaggeredOutput("Type any character to continue...", 25);
    outputObject.printStaggeredOutput("\n\n\n", 150);
    char trash; cin >> trash;
    cin.clear();
    cin.ignore(2147483647, '\n');
    system("clear");
}

std::vector<Internship> Game::parseInternships(string tier) {

    std::vector<Internship> internships;

    std::ifstream ifs;
    ifs.open("gamedata/internships.json");
    if (!ifs.is_open()) {
        output = "Failed to open the JSON file.\n";
        outputObject.printOutput(output);
        throw runtime_error("error reading file");
    }

    Json::Value root;
    Json::Reader reader;
    if (!reader.parse(ifs, root)) {
        output = "Failed to parse the JSON file.\n";
        outputObject.printOutput(output);
        ifs.close();
        throw runtime_error("error reading file");
    }

    Json::Value tierInternships = root[tier];

    if (tierInternships.isNull()) {
        output = "Invalid tier specified.\n";
        outputObject.printOutput(output);
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
    }

    ifs.close();
    return internships;
}

void Game::displayInternships() {

    system("clear");
    output = "Loading your internship opportunity...\n";
    outputObject.printOutput(output);
    clearAndLoad();

    // string tier = calculateScore();
    string tier = this->character->getTier();
    std::vector<Internship> possibleInternships = parseInternships(tier);


    // int randIndex = rand() % possibleInternships.size();
    // Internship theInternship = possibleInternships.at(randIndex); broken
    Internship theInternship = getRandomFromVector(possibleInternships);
 
    output = "Congratulations! With your cumulative game score of " + to_string(this->character->getCumulativeScore()) + ", ";
    output += "You've been offered an internship at " + theInternship.company + "!\n\n";
    output += "Here's a message from the hiring team: \n\n" + theInternship.welcomeMessage + "\n\n\n";
    output += "Your starting wage is " + theInternship.startingWage + "\n\n\n";
    outputObject.printStaggeredOutput(output, 25);
    string x;
    cin >> x;
    cin.clear();
    cin.ignore(2147483647, '\n');



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

void Game::printLobby() {

    output = character->getName() + "\'s Room\n\n\n";
    outputObject.printOutput(output);
    int healthPercent = character->getHealth() / 10; //health out of 10 (truncated)
    output = "Health:    [ ";
    outputObject.printOutput(output);
    outputObject.handleColor(healthPercent); // set to green or yellow based on score
    for(int i = 0; i < healthPercent; ++i){
        output = "█ "; 
        outputObject.printOutput(output);
    }
    for(int i = healthPercent; i < 10; ++i){
        output = "- ";
        outputObject.printOutput(output);
    }
    
    output = "] " + to_string(character->getHealth()) + "%\n";
    outputObject.printOutput(output);
    outputObject.handleColor(-1); // reset to white
    outputObject.printNewline();

    int gradesPercent = character->getGrades() / 10;
    output = "Grades:    [ ";
    outputObject.printOutput(output);
    outputObject.handleColor(gradesPercent);
    for(int i = 0; i < gradesPercent; ++i){
        output = "█ ";
        outputObject.printOutput(output);
    }
    for(int i = gradesPercent; i < 10; ++i){
        output = "- ";
        outputObject.printOutput(output);
    }

    output = "] " + to_string(character->getGrades()) + "%\n";
    outputObject.printOutput(output);
    outputObject.handleColor(-1);
    outputObject.printNewline();

    int happinessPercent = character->getHappiness() / 10;
    output = "Happiness: [ ";
    outputObject.printOutput(output);
    outputObject.handleColor(happinessPercent);
    for(int i = 0; i < happinessPercent; ++i){
        output = "█ "; 
        outputObject.printOutput(output);
    }
    for(int i = happinessPercent; i < 10; ++i){
        output = "- ";
        outputObject.printOutput(output);
    }

    output = "] " + to_string(character->getHappiness()) + "%\n";
    outputObject.printOutput(output);
    outputObject.handleColor(-1);
    output = "\n\n";

    output += "Options: \n";
    output += "\t1. Workout\n";
    output += "\t2. Study\n"; 
    output += "\t3. Hang with Friends\n";
    output += "\t4. Save and quit game\n";
    output += "Type an option: \n";
    outputObject.printOutput(output);
    char option = 0;
    cin >> option;

    while(cin.fail() or option != '1' and option != '2' and option != '3' and option != '4'){
        cin.clear();
        cin.ignore(2147483647, '\n');
        output = "Invalid option, please try again\n";
        output += "Type an option: ";
        outputObject.printOutput(output);
        cin >> option;
    }
    if(option == '1'){
        character->workout();
    }
    else if(option == '2'){
        character->studyHarder();
    }

    else if(option == '4') {
        save(this->name);
        throw runtime_error("Game saved and quit");

    }
    else{
        character->hangWithFriends();
    }
}



