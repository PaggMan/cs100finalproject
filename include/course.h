#include "../include/course.h"

Course::Course(const std::string& _name, double _difficulty) {
    name = _name;
    difficulty = _difficulty;
}

const std::string& Course::getName() const {
    return name;
}
double Course::getDifficulty() const {
    return difficulty;
}

int main() {
    return 0;
}
