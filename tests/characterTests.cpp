#include "gtest/gtest.h"

#include "../include/character.h"

using namespace std;


TEST(ModifierTests, workoutTestIncrease){
    Character* testSubject = new Character();
    int beforeWorkout = testSubject->getHealth();
    testSubject->workout();
    EXPECT_TRUE(beforeWorkout < testSubject->getHealth());
}

TEST(ModifierTests, workoutGradeDecrease){
    Character* testSubject = new Character();
    int beforeWorkout = testSubject->getGrades();
    testSubject->workout();
    EXPECT_TRUE(beforeWorkout > testSubject->getGrades());
}


TEST(ModifierTests, studyTestIncrease){
    Character* testSubject = new Character();
    int beforeStudy = testSubject->getGrades();
    testSubject->studyHarder();
    EXPECT_TRUE(beforeStudy < testSubject->getGrades());
}

TEST(ModifierTests, studyTestHealthDecrease){
    Character* testSubject = new Character();
    int healthBeforeStudy = testSubject->getHealth();
    testSubject->studyHarder();
    EXPECT_TRUE(healthBeforeStudy > testSubject->getHealth());
}

TEST(ModifierTests, studyTestHappinessDecrease){
    Character* testSubject = new Character();
    int happinessBeforeStudy = testSubject->getHappiness();
    testSubject->studyHarder();
    EXPECT_TRUE(happinessBeforeStudy > testSubject->getHealth());
}

TEST(ModifierTests, hangoutTest){
    Character* testSubject = new Character();
    int beforeHangout = testSubject->getHappiness();
    testSubject->hangWithFriends();
    EXPECT_TRUE(beforeHangout < testSubject->getHappiness());
}

TEST(ModifierTests, hangoutGradeDecrease){
    Character* testSubject = new Character();
    int beforeHangout = testSubject->getGrades();
    testSubject->hangWithFriends();
    EXPECT_TRUE(beforeHangout > testSubject->getGrades());
}