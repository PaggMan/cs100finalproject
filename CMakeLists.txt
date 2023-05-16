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




# Include the JSONCpp headers
target_include_directories(rungame PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Add the JSONCpp source files to project
target_sources(rungame PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib_json/json_reader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib_json/json_value.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib_json/json_writer.cpp
)




# Include the FTXUI headers
target_include_directories(rungame PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Add all FTXUI source files to your project
file(GLOB FTXUI_SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ftxui/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ftxui/*.hpp
    # Add other patterns if necessary
)
target_sources(rungame PRIVATE ${FTXUI_SOURCE_FILES})