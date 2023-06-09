#include "character.h"
#include "course.h"
#include "internship.h"
#include "json/json.h"
#include <vector>
class Game {
    private:    //Private member variables
        int currentDay;
        string name;
        Character* character;
        Course** courseList;
    
    public: //Public member functions
        Game();
        void load(string fileName);
        ~Game();
        void save(string fileName);
        void start();


        Character* getCharacter();
        string getName();
        int getCurrentDay();
        void setName(const string& name);
        
        template<class T>
        T getRandomFromVector(const std::vector<T>& internships);
        void displayInternships();
        std::vector<Internship> parseInternships(string );

    private:   //Private member functions
    
    //Helper functions for constructor
        void customizeCharacter();  //Prompts the user to enter a name for their character.
        void chooseCourses();   //Prompts the user to choose 4 courses.
        void printCourseList(); //Outputs the contents of courseList in a formatted way.
        void addCourse(const std::string& courseName, unsigned& courseListSize);  //Adds a course from courseCatalog.txt based on the user entered course name. If not found, the courseListSize variable is not incremented.
        void clearAndLoad();
        void gameLoop();


        string calculateScore(); // Used to calculate internship opportunities
        
};