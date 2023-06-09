# Senior CS Student Simulator

## Authors
#### Komay Sugiyama (ksugi014)
- [Github Page](https://zenxha.github.io)
- [Issues](https://github.com/cs100/final-project-ksugi014-cmill100-pchen215-rnogh001/issues?q=user%3Azenxha)
#### Cole Miller (cmill100)
- [Github Page](https://github.com/Kolzza)
- [Issues](https://github.com/cs100/final-project-ksugi014-cmill100-pchen215-rnogh001/issues?q=user%3AKolzza)
#### Peyton Chen (pchen215)
- [Github Page](https://github.com/PaggMan)
- [Issues](https://github.com/cs100/final-project-ksugi014-cmill100-pchen215-rnogh001/issues?q=user%3APaggMan)
#### Ryan Noghani
- [Github Page](https://github.com/ryannoghani)
- [Issues](https://github.com/cs100/final-project-ksugi014-cmill100-pchen215-rnogh001/issues?q=user%3Aryannoghani)


## Getting started
### Installing
This assumes you already have a working c++ environment, if not, download [here](https://learn.microsoft.com/en-us/cpp/build/vscpp-step-0-installation?view=msvc-170)
Alternatively, you can install the C++ extension pack on Visual Studio Code

Test that you have g++ installed with
```sh
g++ --version
```
Clone the repository
```sh
git clone https://github.com/cs100/final-project-ksugi014-cmill100-pchen215-rnogh001
cd final-project-ksugi014-cmill100-pchen215-rnogh001
```

You will need to download CMake n from their [**website**](https://cmake.org/download/) to build the binary files used for executing the program.

### Usage

Set up your project environment with
```sh
cmake .
```
Install necessary dependencies and compile with
```sh
make
```
All binary files will be in the /bin directory.
Now you should be good to run the executable with the following
```sh
./bin/rungame
```
> NOTE: It will take some time to install FTXUI and link it.

## Project Description

### Why is it important to us?
- We have all come across some sort of story game in our lives, so it would be interesting to understand how one works behind the scenes. Not only is it an interesting story game, but it is also applicable to the life of a UCR computer science student.
### What languages/tools/technologies do we plan to use?
- The majority of the project will be done C++. We will use the GoogleTest subdirectory for our unit testing, and CMake for ease of compiling. 
### What will be the input/output of your project?
- The input will be numbers and strings from the user to navigate the menu and make choices, while the output will be story prompts displayed by the terminal. Throughout the game, you make specific choices and play minigames that affect your character's stats. At the end of the game, you will be given a job or internship based on how good your stats are. 
### What are the features that the project provides?
- The project provides a menu, character customization, ability to save, load, or restart the game, and user input choices or games that impact the path the game takes.


### Screen Navigation

<img src="https://files.catbox.moe/3ms1o7.png"  width="600">

### SOLID Principle UML Diagram
<img src="https://files.catbox.moe/e4jjw4.jpg"  width="600">
 - Our UML follows the Single Responsibilty SOLID principle. It is most evident in the minigame section, as each minigame has its own class that inherits from a Minigame interface. Another example of SRP being followed is the addition of the CharacterValidator class for our new UML diagram. The reason for this addition was because the Character class was initially in charge of not only storing a character's name and list of courses, but also making sure that these pieces of information the user enters are valid to use. This is why CharacterValidator was added, in order to divide these two responsibilities for the two classes.

### Main Menu
<img src="https://files.catbox.moe/ng74gj" width="600">

### Class Selection
<img src="https://files.catbox.moe/5a45yi.png" width = "600">

### Lobby Screen
<img src="https://files.catbox.moe/fp9wzh.png" width = "600">

### Final Game Over Screen
<img src="https://files.catbox.moe/lmbi4y.png" width = "600">

### Screen Layouts

Title Screen

<img src="https://cdn.discordapp.com/attachments/771442141007839294/1116689481597198416/image.png" width = "600">

TicTacToe

<img src="https://cdn.discordapp.com/attachments/771442141007839294/1116689457953902652/image.png" width = "600">

Minesweeper

<img src = "https://cdn.discordapp.com/attachments/771442141007839294/1116689441264762930/image.png" width = "600">

Lobby

<img src = "https://cdn.discordapp.com/attachments/771442141007839294/1116689606503579768/68747470733a2f2f66696c65732e636174626f782e6d6f652f706c656d37782e6a7067.png" width = "600">

### OLD UML Diagram
<img src="https://cdn.discordapp.com/attachments/1096301999986835466/1106704973959528508/Screen_Shot_2023-05-12_at_3.09.32_PM.png"  width="600">


This is our tentative UML diagram. Our game will consist of these classes. The "user" who's playing will be represented with our character class which will store their stats, and also store the actions that they can do. For example, things like changing their grades and health status. These changes will be brought about thorugh the game or minigame classes that will invoke different characther methods depending on what type of actions they do. If they skip school for example, the game class will use the character class health mutator to change their mental heath status to be a little better. The screen class is what we will use to render our game and allow for interaction between the user and our code. There will be methods like printing the screen and taking the user input.
