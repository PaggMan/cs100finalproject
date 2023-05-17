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
)




# Include the headers
target_include_directories(rungame PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ftxui/component
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ftxui


)

# Add the JSONCpp source files to project
target_sources(rungame PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib_json/json_reader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib_json/json_value.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib_json/json_writer.cpp
)





# Add all FTXUI source files to your project
file(GLOB FTXUI_SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ftxui/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ftxui/component/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ftxui/dom/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ftxui/screen/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ftxui/component/terminal_input_parser.hpp
)
target_sources(rungame PRIVATE ${FTXUI_SOURCE_FILES})




# Set the Google Test directory
set(GTEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/gtest")

# Add Google Test subdirectory
add_subdirectory(${GTEST_DIR})

# Include Google Test directories
include_directories(${GTEST_INCLUDE_DIRS})

# Link Google Test libraries
target_link_libraries(rungame gtest gtest_main)