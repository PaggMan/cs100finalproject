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
<img src="[(https://cdn.discordapp.com/attachments/1096301999986835466/1116772027928416276/Screen_Shot_2023-06-09_at_9.50.08_AM.png)]" width="600">


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

### Testing
We tested out project using GitHub actions (CI). Our continuous integration constantly checks to see if unit tests are passing, and if the program is working correctly. 

<img src = "https://cdn.discordapp.com/attachments/1096301999986835466/1116714924434010172/image.png" width = "600">

