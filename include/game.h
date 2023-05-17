#include "character.h"
#include "json/json.h"
class Game {
    private:
        int currentDay;
        Character* character;
        string name;
    
    public:
        Game();
        void load(string fileName);
        ~Game();
        void save();
        void start();
        
};