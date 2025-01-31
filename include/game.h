#include "character.h"
#include "course.h"
#include "minigame.h"
#include "print.h"
#include "internship.h"
#include "json/json.h"
#include <vector>

class Game {
    private:    //Private member variables
        int currentDay;
        string name;
        Character* character;
        Course** courseList;
        std::vector<Minigame*> minigameList;
        Minigame* minigame1;
        Minigame* minigame2;
        Minigame* minigame3;
        Minigame* minigame4;
        Minigame* minigame5;
        Print outputObject;
        string output;
    public: //Public member functions
        Game();
        void load(string fileName);
        ~Game();
        void save(string fileName);
        void start();

        void giveInstructions();    //Explains the user how to play the game
        void runDay();  //Allows user to make choices on a given day and calls minigame classes
        void gameLoop();

        Character* getCharacter();
        string getName();
        int getCurrentDay();
        void setName(const string& name);
        
        template<class T>
        T getRandomFromVector(const std::vector<T>& internships);
        void displayInternships();
        std::vector<Internship> parseInternships(string );

    private:   //Private member functions
    
    void customizeCharacter();  //Prompts the user to enter a name for their character.
    void chooseCourses();   //Prompts the user to choose 4 courses.
    void printCourseList(); //Outputs the contents of courseList in a formatted way.
    void addCourse(const std::string& courseName, unsigned& courseListSize);  //Adds a course from courseCatalog.txt based on the user entered course name. If not found, the courseListSize variable is not incremented.
    void clearAndLoad();
    void playMinigame();
    void printLobby();
    
    string calculateScore(); // Used to calculate internship opportunities
        
};