#ifndef COURSE_H
#define COURSE_H
#include <string>
class Course {
    private:
        std::string name;
        double difficulty;
    public:
        Course();
        Course(const std::string&, double);
        const std::string& getName() const;
        double getDifficulty() const;
};
#endif
