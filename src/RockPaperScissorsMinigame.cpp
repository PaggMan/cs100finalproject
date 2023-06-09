#include "../include/RockPaperScissorsMinigame.h"

RockPaperScissorsMinigame::RockPaperScissorsMinigame(){
    userScore = 0;
    computerScore = 0;
}

void RockPaperScissorsMinigame::initialize(){
    string userChoice;
    int computerChoice;
    string output;
    
    cout << "\nHello, welcome to Rock Paper Scissors!\nThe rules are like any normal Rock Paper Scissors game and it is first to 3 wins.\nLet's get started!\n\n";

    while(userScore != 3 and computerScore != 3) {
        srand(time(0));
        computerChoice = (rand() % 3) + 1; // 1 is Rock, 2 is Paper, 3 is Scissors
        cout << "Enter your choice (Rock, Paper, Scissors): ";
        cin >> userChoice;

        if(userChoice == "Rock" or userChoice == "rock") {
            if(computerChoice == 1) {
                cout << "We both chose Rock, it is a tie!\n";
            }
            else if(computerChoice == 2) {
                computerScore++;
                cout << "I chose Paper and you chose Rock, I win this round!\n";
            }
            else if(computerChoice == 3) {
                userScore++;
                cout << "I chose Scissors and you chose Rock, you win this round!\n";
            }
        }
        else if(userChoice == "Paper" or userChoice == "paper") {
            if(computerChoice == 1) {
                userScore++;
                cout << "I chose Rock and you chose Paper, you win this round!\n";
            }
            else if(computerChoice == 2) {
                
                cout << "We both chose Paper, it is a tie!\n";
            }
            else if(computerChoice == 3) {
                computerScore++;
                cout << "I chose Scissors and you chose Paper, I win this round!\n";
            }
        }
        else if(userChoice == "Scissors" or userChoice == "scissors") {
            if(computerChoice == 1) {
                computerScore++;
                cout << "I chose Rock and you chose Scissors, I win this round!\n";
            }
            else if(computerChoice == 2) {
                userScore++;
                cout << "I chose Paper and you chose Scissors, you win this round!\n";
            }
            else if(computerChoice == 3) {
                cout << "We both chose Scissors, it is a tie!\n";
            }
        }
        else {
            cout << "Invalid choice! You did not choose rock, paper, or scissors!" << endl;
        }
        cout << "The current score is " + to_string(userScore) + " (your score) to " + to_string(computerScore) + " (my score).\n\n";
    }
    terminate();
}

void RockPaperScissorsMinigame::terminate(){
    if(userScore == 3) {
        cout << "\nCongratulations, you won the game!\n";
        userWon = true;
    }
    else if(computerScore == 3) {
        cout << "\nUnlucky, you did not win the game.\n";
        userWon = false;
    }
}