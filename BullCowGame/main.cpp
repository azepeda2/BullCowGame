/* This is a console executable that uses the BullCow class.
This acts as the view in a MVC pattern, and handles all user interaction.
For game logic please refer to the FBullCowGame class.
*/


#pragma	once
#include <iostream>
#include <string>
#include "FBullCowGame.h"
#include <ctime>

// to make syntax Unreal friendly
using FText = std::string;
using int32 = int;

// function prototypes since not using header for main
void PlayGame();
void IntroduceGame();
FText GetGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame; //instance of new game

// the entry point of the program
int main() 
{
	srand(time(0)); //ensures the random number generator has unique seed, see FBullCowGame.cpp
	bool keepPlaying = false;
	do {
		IntroduceGame();
		PlayGame();
		keepPlaying = AskToPlayAgain();
		std::cout << std::endl;
	} while (keepPlaying);

	return 0;
}


void IntroduceGame() 
{
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << std::endl;
	std::cout << "          }   {         ___ " << std::endl;
	std::cout << "          (o o)        (o o) " << std::endl;
	std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
	std::cout << " *  |-,--- |              |------|  * " << std::endl;
	std::cout << "    ^      ^              ^      ^ " << std::endl;

}

// plays a single game to completion
void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	int32 WordLength = BCGame.GetHiddenWordLength();

	std::cout << "Can you guess the " << WordLength << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		FText Guess = GetGuess();
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Your guess was : " << Guess << std::endl;
		std::cout << "Bulls: " << BullCowCount.Bulls;
		std::cout << " Cows: " << BullCowCount.Cows;
		std::cout << std::endl << std::endl;
	}

	PrintGameSummary();

}

//get a guess from the player
FText GetGuess() 
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid;
	do {
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries();
		std::cout << ". Enter your guess: ";
		getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status) {
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please make sure to only enter lowercase letters. \n\n";
			break;
		case EGuessStatus::NOT_ISOGRAM:
			std::cout << "Please enter a word without repeating letters. \n\n";
			break;
		default:
			break; //assume word is OK
		}

	} while (Status != EGuessStatus::OK);
	return Guess;
}

bool AskToPlayAgain()
{
	FText Response = "";
	std::cout << "Do you want to play again (with a new hidden word)? ";
	getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
	
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "Good work! You Win! \n";
	}
	else
	{
		std::cout << "Better luck next time! \n";
	}
}
