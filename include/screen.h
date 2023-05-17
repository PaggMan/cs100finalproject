#include <string>
class Screen{
    private:
        string title;

    public:
        void setTitle(string newTitle){
            title = newTitle;
        }
        
        string getTitle(){
            return title;
        }
        
        virtual int getUserChoice() = 0;
        virtual void printMenu() = 0;
        virtual void printOptions() = 0;
        virtual void printSummary() = 0;
}