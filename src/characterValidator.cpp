#include "../include/characterValidator.h"


bool CharacterValidator::isValidCharacterName(const std::string& characterName) {  //Returns true or false depending on the validity of the name passed in.
    return characterName.size() >=2 && characterName.size() <= 20;
}

bool CharacterValidator::isValidCourseList(Course* courseList, unsigned sizeOfCourseList) {  //Returns true or false depending on the validity of the course list passed in.
    
    if (sizeOfCourseList == 0) {
        return false;
    }

    else if (sizeOfCourseList == 1) {
        return true;
    }

    else if (sizeOfCourseList == 2) {
        return validateTwoCourses(courseList);
    }

    else if (sizeOfCourseList == 3) {
        return validateThreeCourses(courseList);
    }

    else {
        return validateFourCourses(courseList);
    }
}


bool CharacterValidator::validateTwoCourses(Course* courseList) {  //Given two courses, the function determines whether they can be taken together or not
    return courseList[0].getName() != courseList[1].getName();
}

bool CharacterValidator::validateThreeCourses(Course* courseList) {  //Given three courses, the function determines whether they can be taken together or not
    return validateTwoCourses(courseList) && courseList[2].getName() != courseList[0].getName() && courseList[2].getName() != courseList[1].getName();
}

bool CharacterValidator::validateFourCourses(Course* courseList) {  //Given four courses, the function determines whether they can be taken together or not
    return validateThreeCourses(courseList) && courseList[3].getName() != courseList[0].getName() && courseList[3].getName() != courseList[1].getName() && courseList[3].getName() != courseList[2].getName();
}