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

⚠️ **IMPORTANT** ⚠️

- It's important that you create an empty directory under `/gamedata/` called `savedgames` or else game saving and loading will crash.

Next, set up your project environment with
```sh
cmake .
```
Install necessary dependencies and compile with
```sh
make
```
> NOTE: It will take some time to install FTXUI and link it.

All binary files will be in the /bin directory.
Now you should be good to run the executable with the following
```sh
./bin/rungame
```


## Project Description

### Why is it important to us?
Understanding how a story game works behind the scenes is important for several reasons. Firstly, it allows us to appreciate the complexity and effort that goes into creating such games. By dissecting the mechanics, we can gain insights into game design principles, narrative structures, and interactive storytelling techniques. This knowledge can be valuable for aspiring game developers or storytellers, providing them with a foundation to create engaging and immersive experiences.

Secondly, as UCR computer science students, exploring the inner workings of a story game can have practical applications. It allows us to apply programming concepts, such as object-oriented design, input/output handling, and data management, in a real-world scenario. By working on this project, we can enhance our programming skills, problem-solving abilities, and collaborative development techniques, all of which are crucial for our academic and professional growth.

### What languages/tools/technologies do we plan to use?
For this project, we plan to primarily use C++ as the programming language. It provides the necessary tools and libraries to handle various game mechanics and interactions effectively.

Additionally, we intend to utilize GoogleTest, a C++ testing framework, to ensure the reliability and correctness of our code. By writing unit tests, we can verify that different components of our game function as intended, catch bugs early in the development process, and maintain the overall quality of the project.

To streamline the build process, we will employ CMake, a cross-platform build system. CMake simplifies the compilation and linking of our code, making it easier to manage dependencies, build configurations, and generate executable files across different platforms.

### What will be the input/output of your project?
The input for our project will consist of numbers and strings provided by the user through the terminal. These inputs will be used to navigate the menu, make choices, and interact with the game world. For example, the user may input numbers to select menu options, input strings to customize their character's name, or make decisions during the story prompts.

The output of the project will be displayed in the terminal as story prompts and game information. The prompts will present the narrative elements of the game, guiding the player through different scenarios and choices. Additionally, the game will provide feedback to the user based on their decisions and actions, such as displaying the outcome of a particular choice, presenting character stats, or indicating progress within the game.

### What are the features that the project provides?
The project aims to provide several key features to enhance the gameplay experience. These features include:

Menu System: The game will have a menu system that allows the player to navigate different options, such as starting a new game, loading a saved game, or exiting the game.

Character Customization: Players will have the ability to customize their character by inputting their preferred name or selecting different attributes. These choices may affect the gameplay and outcomes.

Save, Load, and Restart: The game will provide options to save the current progress, load a saved game, or restart the game from the beginning. This feature allows players to continue their gameplay from where they left off or explore different paths by replaying the game.

User Input Choices: Throughout the game, players will encounter story prompts that require them to make choices. These choices may influence the direction of the narrative, affect character stats, or determine the outcome of certain events.

Minigames and Stats: The game may include minigames or challenges that players can participate in. The performance in these activities can impact the character's stats or unlock additional content. These mechanics add an interactive element to the game


### Screen Navigation

<img src="https://cdn.discordapp.com/attachments/964617182325637160/1116865547456479332/image.png"  width="600">

### SOLID Principle UML Diagram
<img src="https://files.catbox.moe/o9g4r9.png"  width="600">

 - Our UML follows the Single Responsibilty SOLID principle. It is most evident in the minigame section, as each minigame has its own class that inherits from a Minigame interface. 
 
 - Another example of SRP being followed is the addition of the CharacterValidator class for our new UML diagram. The reason for this addition was because the Character class was initially in charge of not only storing a character's name and list of courses, but also making sure that these pieces of information the user enters are valid to use. This is why CharacterValidator was added, in order to divide these two responsibilities for the two classes.
 
 - SRP is followed by giving output functions their own class called "print". This relieves the extra responsibility of outputting for the game class, allowing game to only have to focus on story progression.
 
 - Open-closed principle: Our program has the ability to extend its course and internship list without having to modify the display functions that show the user courses and internships. This is due to storing courses and internships inside a file. The file's contents can be extended while the functions reading from that file are not changed.

### Main Menu
<img src="https://cdn.discordapp.com/attachments/1096301999986835466/1116772027928416276/Screen_Shot_2023-06-09_at_9.50.08_AM.png" width="600">


### Class Selection
<img src="https://files.catbox.moe/5a45yi.png" width = "600">

### Lobby Screen
<img src="https://files.catbox.moe/03gnlp.png" width = "600">

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

