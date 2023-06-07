/*The role of characterCustomizer is to verify that the customization data the user enters is valid and playable.
Such data includes the name of the character as well as the list of courses the character will take.*/

#ifndef CHARACTERVALIDATOR_H
#define CHARACTERVALIDATOR_H


#include <string>
#include "course.h"


class CharacterValidator {
    public:
        bool isValidCharacterName(const std::string& characterName);  //Returns true or false depending on the validity of the name passed in.
        bool isValidCourseList(Course** courseList, unsigned sizeOfCourseList);  //Returns true or false depending on the validity of the course list passed in.
    private:
        bool validateTwoCourses(Course** courseList);  //Given two courses, the function determines whether they can be taken together or not
        bool validateThreeCourses(Course** courseList);  //Given three courses, the function determines whether they can be taken together or not
        bool validateFourCourses(Course** courseList);  //Given four courses, the function determines whether they can be taken together or not
};

#endif