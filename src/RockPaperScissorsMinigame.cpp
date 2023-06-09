#include "../include/RockPaperScissorsMinigame.h"

RockPaperScissorsMinigame::RockPaperScissorsMinigame(){
    userScore = 0;
    computerScore = 0;
}

void RockPaperScissorsMinigame::initialize(){
    string userChoice;
    int computerChoice;
    
    output = "\nHello, welcome to Rock Paper Scissors!\nThe rules are like any normal Rock Paper Scissors game and it is first to 3 wins.\nLet's get started!\n\n";
    outputObject.printOutput(output);

    while(userScore != 3 and computerScore != 3) {
        srand(time(0));
        computerChoice = (rand() % 3) + 1; // 1 is Rock, 2 is Paper, 3 is Scissors
        output = "Enter your choice (Rock, Paper, Scissors): ";
        outputObject.printOutput(output);
        cin >> userChoice;

        if(userChoice == "Rock" or userChoice == "rock") {
            if(computerChoice == 1) {
                output = "We both chose Rock, it is a tie!\n";
                outputObject.printOutput(output);
            }
            else if(computerChoice == 2) {
                computerScore++;
                output = "I chose Paper and you chose Rock, I win this round!\n";
                outputObject.printOutput(output);
            }
            else if(computerChoice == 3) {
                userScore++;
                output = "I chose Scissors and you chose Rock, you win this round!\n";
                outputObject.printOutput(output);
            }
        }
        else if(userChoice == "Paper" or userChoice == "paper") {
            if(computerChoice == 1) {
                userScore++;
                output = "I chose Rock and you chose Paper, you win this round!\n";
                outputObject.printOutput(output);
            }
            else if(computerChoice == 2) {
                output = "We both chose Paper, it is a tie!\n";
                outputObject.printOutput(output);
            }
            else if(computerChoice == 3) {
                computerScore++;
                output = "I chose Scissors and you chose Paper, I win this round!\n";
                outputObject.printOutput(output);
            }
        }
        else if(userChoice == "Scissors" or userChoice == "scissors") {
            if(computerChoice == 1) {
                computerScore++;
                output = "I chose Rock and you chose Scissors, I win this round!\n";
                outputObject.printOutput(output);
            }
            else if(computerChoice == 2) {
                userScore++;
                output = "I chose Paper and you chose Scissors, you win this round!\n";
                outputObject.printOutput(output);
            }
            else if(computerChoice == 3) {
                output = "We both chose Scissors, it is a tie!\n";
                outputObject.printOutput(output);
            }
        }
        else {
            output = "Invalid choice! You did not choose rock, paper, or scissors!\n";
            outputObject.printOutput(output);
        }
        output = "The current score is " + to_string(userScore) + " (your score) to " + to_string(computerScore) + " (my score).\n\n";
        outputObject.printOutput(output);
    }
    terminate();
}

void RockPaperScissorsMinigame::terminate(){
    if(userScore == 3) {
        output = "\nCongratulations, you won the game!\n";
        outputObject.printOutput(output);
        userWon = true;
    }
    else if(computerScore == 3) {
        output = "\nUnlucky, you did not win the game.\n";
        outputObject.printOutput(output);
        userWon = false;
    }
}