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

## Project Description

### Why is it important to us?
- We have all come across some sort of story game in our lives, so it would be interesting to understand how one works behind the scenes.
### What languages/tools/technologies do we plan to use?
- The majority of the project will be done C++. We also plan to use some external dependencies like [FTXUI](https://github.com/ArthurSonzogni/FTXUI) that will allow us to build terminal interfaces easily.
### What will be the input/output of your project?
- The input will be keys to navigate the menu and make choices, while the output will be story prompts displayed by the terminal.
### What are the features that the project provides?
- The project provides a menu, character customization, ability to save/restart the game, make choices that impact the path the game takes.


### Screen Navigation

<img src="https://cdn.discordapp.com/attachments/1096301999986835466/1105351405377704017/image.png"  width="600" height="300">

### SOLID Principle UML Diagram
<img src="https://files.catbox.moe/e4jjw4.jpg"  width="600">
 - Our UML follows the Single Responsibilty SOLID principle. It is most evident in the minigame section, as each minigame has its own class that inherits from a Minigame interface. Another example of SRP being followed is the addition of the CharacterValidator class for our new UML diagram. The reason for this addition was because the Character class was initially in charge of not only storing a character's name and list of courses, but also making sure that these pieces of information the user enters are valid to use. This is why CharacterValidator was added, in order to divide these two responsibilities for the two classes.

### Main Menu
<img src="https://files.catbox.moe/ng74gj" width="600">

### Class Selection
<img src="https://files.catbox.moe/5a45yi.png" width = "600">

### Lobby Screen
<img src="https://files.catbox.moe/fp9wzh.png" width = "600">

### Lobby Screen Layout
<img src="https://files.catbox.moe/plem7x.jpg" width="600">

### OLD UML Diagram
<img src="https://cdn.discordapp.com/attachments/1096301999986835466/1106704973959528508/Screen_Shot_2023-05-12_at_3.09.32_PM.png"  width="600">


This is our tentative UML diagram. Our game will consist of these classes. The "user" who's playing will be represented with our character class which will store their stats, and also store the actions that they can do. For example, things like changing their grades and health status. These changes will be brought about thorugh the game or minigame classes that will invoke different characther methods depending on what type of actions they do. If they skip school for example, the game class will use the character class health mutator to change their mental heath status to be a little better. The screen class is what we will use to render our game and allow for interaction between the user and our code. There will be methods like printing the screen and taking the user input.
