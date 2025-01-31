cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)
project(CsStudentSimulator)



set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

# Add project source files
add_executable(rungame
    src/main.cpp
    src/game.cpp  
    src/character.cpp
    src/course.cpp
    src/characterValidator.cpp
    src/MinesweeperMinigame.cpp
    src/RockPaperScissorsMinigame.cpp
    src/TicTacToeMinigame.cpp
    src/TypingMinigame.cpp
    src/UnscrambleMinigame.cpp
    src/WordleMinigame.cpp
)


configure_file(${CMAKE_CURRENT_SOURCE_DIR}/courseCatalog.txt
    ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
  
  configure_file(${CMAKE_SOURCE_DIR}/gamedata/internships.json ${CMAKE_BINARY_DIR}/gamedata/internships.json COPYONLY)



 
# --- Fetch FTXUI --------------------------------------------------------------
include(FetchContent)
 
set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG main
  # Important: Specify a GIT_TAG XXXXX here.
)
 
FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
  FetchContent_Populate(ftxui)
  add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
 
# ------------------------------------------------------------------------------

target_include_directories(rungame 
  PRIVATE src
  PRIVATE include
)


#  link against ftxui, and fs library (for reading files)
target_link_libraries(rungame
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component 
  PRIVATE stdc++fs
)


target_include_directories(rungame PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)


# Add the JSONCpp source files to project
target_sources(rungame PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib_json/json_reader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib_json/json_value.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib_json/json_writer.cpp
)



# Set the Google Test directory
set(GTEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/googletest")

# Add Google Test subdirectory
add_subdirectory(${GTEST_DIR})

# Include Google Test directories
include_directories(${GTEST_INCLUDE_DIRS})

# characterTests
add_executable(characterTests
    tests/characterTests.cpp
    src/character.cpp
)

# Link Google Test libraries
target_link_libraries(characterTests 
    PRIVATE gtest 
    PRIVATE gtest_main
    )

target_link_libraries(rungame
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component 
  PRIVATE stdc++fs
)
    
target_sources(characterTests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib_json/json_reader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib_json/json_value.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib_json/json_writer.cpp
)

 target_include_directories(characterTests PRIVATE
     ${CMAKE_CURRENT_SOURCE_DIR}/include
 )


# character validator tests
add_executable(testCharacterValidator
    tests/testCharacterValidator.cpp
    src/characterValidator.cpp
    src/course.cpp 
)

TARGET_LINK_LIBRARIES(testCharacterValidator gtest)
TARGET_COMPILE_DEFINITIONS(testCharacterValidator PRIVATE gtest_disable_pthreads=ON)




add_executable(testGame
    tests/testGame.cpp
    src/game.cpp
    src/character.cpp
    src/course.cpp
    src/characterValidator.cpp
    src/MinesweeperMinigame.cpp
    src/RockPaperScissorsMinigame.cpp
    src/TicTacToeMinigame.cpp
    src/TypingMinigame.cpp
    src/UnscrambleMinigame.cpp
    src/WordleMinigame.cpp
)

target_include_directories(testGame
  PRIVATE src
  PRIVATE include
)

target_sources(testGame PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib_json/json_reader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib_json/json_value.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib_json/json_writer.cpp
)

TARGET_LINK_LIBRARIES(testGame gtest)
TARGET_COMPILE_DEFINITIONS(testGame PRIVATE gtest_disable_pthreads=ON)