#include "gtest/gtest.h"

#include "../include/character.h"

using namespace std;


TEST(ModifierTests, workoutTest){
    Character* testSubject = new Character();
    beforeWorkout = testSubject->getHealth();
    testSubject->workout();
    EXPECT_TRUE(beforeWorkout > testSubject->getHealth());
}

TEST(ModifierTests, studyTest){
    Character* testSubject = new Character();
    beforeStudy = testSubject->getGrades();
    testSubject->studyHarder();
    EXPECT_TRUE(beforeStudy > testSubject->getGrades());
}

TEST(ModifierTests, hangoutTest){
    Character* testSubject = new Character();
    beforeHangout = testSubject->getHappiness();
    testSubject->hangWithFriends();
    EXPECT_TRUE(beforeHangout > testSubject->getHappiness());
}


//TEST()