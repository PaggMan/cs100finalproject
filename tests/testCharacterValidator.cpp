#include "gtest/gtest.h"

#include "../include/characterValidator.h"



TEST (ValidCharacterNameTest, testBlankSpace) {  //Ensures that isValidCharacterName function doesn't validate a blank space name ("")
    CharacterValidator* blank = new CharacterValidator();
    EXPECT_FALSE(blank->isValidCharacterName(""));
}

TEST (ValidCharacterNameTest, testNameWithSpaces) {  //Ensures that isValidCharacterName function validates a name with spaces
    CharacterValidator* spaces = new CharacterValidator();
    EXPECT_TRUE(spaces->isValidCharacterName("Hi there"));
}

TEST (ValidCharacterNameTest, testLongName) {  //Ensures that isValidCharacterName function doesn't validate a really long name
    CharacterValidator* spaces = new CharacterValidator();
    EXPECT_FALSE(spaces->isValidCharacterName("abcdefghijklmnopqrstubwuxyz"));
}



TEST (ValidCourseListTest, testEmptyCourseList) {  //Ensures that isValidCourseList function doesn't validate an empty courseList
    CharacterValidator* cv = new CharacterValidator();
    Course** emptyCourseList = new Course*[4];
    unsigned sizeOfCourseList = 0;
    EXPECT_FALSE(cv->isValidCourseList(emptyCourseList, sizeOfCourseList));
}

TEST (ValidCourseListTest, testOneCourse) {  //Ensures that isValidCourseList function validates a courseList of size 1
    CharacterValidator* cv = new CharacterValidator();
    Course** courseList = new Course*[4];
    courseList[0] = new Course("CS010a", 2.3);
    unsigned sizeOfCourseList = 1;
    EXPECT_TRUE(cv->isValidCourseList(courseList, sizeOfCourseList));
}

TEST (ValidCourseListTest, testTwoIdenticalCourses) {  //Ensures that isValidCourseList function doesn't validate a courseList of size 2 with two of the same course
    CharacterValidator* cv = new CharacterValidator();
    Course** courseList = new Course*[4];
    courseList[0] = new Course("CS010a", 2.3);
    courseList[1] = new Course("CS010a", 2.3);
    unsigned sizeOfCourseList = 2;
    EXPECT_FALSE(cv->isValidCourseList(courseList, sizeOfCourseList));
}

TEST (ValidCourseListTest, testTwoDifferentCourses) {  //Ensures that isValidCourseList function validates a courseList of size 2 with two of the same course
    CharacterValidator* cv = new CharacterValidator();
    Course** courseList = new Course*[4];
    courseList[0] = new Course("CS010a", 2.3);
    courseList[1] = new Course("CS010b", 3.2);
    unsigned sizeOfCourseList = 2;
    EXPECT_TRUE(cv->isValidCourseList(courseList, sizeOfCourseList));
}

TEST (ValidCourseListTest, testThreeInvalidCourses) {  //Ensures that isValidCourseList function doesn't validate a courseList of size 3 with multiple of the same course
    CharacterValidator* cv = new CharacterValidator();
    Course** courseList = new Course*[4];
    courseList[0] = new Course("CS010a", 2.3);
    courseList[1] = new Course("CS010b", 3.2);
    courseList[2] = new Course("CS010b", 3.2);
    unsigned sizeOfCourseList = 3;
    EXPECT_FALSE(cv->isValidCourseList(courseList, sizeOfCourseList));
}

TEST (ValidCourseListTest, testThreeDifferentCourses) {  //Ensures that isValidCourseList function validates a courseList of size 3 with three different courses
    CharacterValidator* cv = new CharacterValidator();
    Course** courseList = new Course*[4];
    courseList[0] = new Course("CS010a", 2.3);
    courseList[1] = new Course("CS010b", 3.2);
    courseList[2] = new Course("CS010c", 4.4);
    unsigned sizeOfCourseList = 3;
    EXPECT_TRUE(cv->isValidCourseList(courseList, sizeOfCourseList));
}

TEST (ValidCourseListTest, testFourInvalidCourses) {  //Ensures that isValidCourseList function doesn't validate a courseList of size 4 with multiple of the same course
    CharacterValidator* cv = new CharacterValidator();
    Course** courseList = new Course*[4];
    courseList[0] = new Course("CS010a", 2.3);
    courseList[1] = new Course("CS010a", 2.3);
    courseList[2] = new Course("CS010b", 3.2);
    courseList[3] = new Course("CS010b", 3.2);
    unsigned sizeOfCourseList = 4;
    EXPECT_FALSE(cv->isValidCourseList(courseList, sizeOfCourseList));
}

TEST (ValidCourseListTest, testFourDifferentCourses) {  //Ensures that isValidCourseList function validates a courseList of size 4 with different courses
    CharacterValidator* cv = new CharacterValidator();
    Course** courseList = new Course*[4];
    courseList[0] = new Course("CS010a", 2.3);
    courseList[1] = new Course("CS010b", 2.3);
    courseList[2] = new Course("CS010c", 4.4);
    courseList[3] = new Course("CS100", 5.7);
    unsigned sizeOfCourseList = 4;
    EXPECT_TRUE(cv->isValidCourseList(courseList, sizeOfCourseList));
}



int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}