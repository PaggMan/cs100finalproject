cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)
project(CsStudentSimulator)



set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

# Add project source files
add_executable(rungame
    src/main.cpp
    src/game.cpp
    src/screen.cpp
    src/character.cpp
    src/course.cpp
    src/characterValidator.cpp 
)

add_executable(characterTests
    tests/characterTests.cpp
    src/character.cpp
)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/courseCatalog.txt
    ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)



 
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

target_include_directories(rungame PRIVATE src)

target_link_libraries(rungame
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component 
)


target_include_directories(rungame PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)


target_include_directories(characterTests PRIVATE
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

# Link Google Test libraries
target_link_libraries(rungame 
    PRIVATE gtest 
    PRIVATE gtest_main
    )


add_executable(testCharacterValidator
    tests/testCharacterValidator.cpp
    src/characterValidator.cpp
    src/course.cpp 
)

TARGET_LINK_LIBRARIES(testCharacterValidator gtest)
TARGET_COMPILE_DEFINITIONS(testCharacterValidator PRIVATE gtest_disable_pthreads=ON)


