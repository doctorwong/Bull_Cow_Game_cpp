#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

//std:: is the c++ standard library

//namespace is dangerous
//if you have the same function in two namespaces there will be conflict
void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();

//instantiates a new game -- creates an instance of FBullCowGame named BCGame.
//At top, highest scope so it's available to all methods.
//This is a global
FBullCowGame BCGame;

int32 main()
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		//TODO: add a game summary

		bPlayAgain = AskToPlayAgain();
	}
	//while(true) creates an infinite loop
	//while bPlayAgain means if bPlayAgain is true
		while (bPlayAgain);
	return 0; //exits the application
}

void PrintIntro()
{
	//use "constexpr int" to declare Constants
	std::cout << "\n\nWelcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << BCGame.HIDDEN_WORD.length();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "You Win!\n";
	}
	else
	{
		std::cout << "You are out of tries. Better luck next time!\n";
	}
}

void PlayGame()
{

	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

								   //loop asking for guesses while game is NOT won 
								   //and there are tries remaining
								   //use ! for not

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		std::cout << "Max Tries: " << MaxTries << std::endl;
		std::cout << "Current Try: " << BCGame.GetCurrentTry() << std::endl;
		FText Guess = GetValidGuess(); //TODO make loop checking valid

		//if (Guess == BCGame.)
		//Define the appropriate getter method
		//Create a private variable prefixed with b
		//Set the private variable in SubmitValidGuess()
		//Test you can now win the game
		BullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls =" << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}

	//TODO summarize game
	PrintGameSummary();
	return;
}



bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n) \n";
	FText Response = "";
	std::getline(std::cin, Response);

	//returns 1 in first character is 'y' or 'Y'
	return (Response[0] == 'y' || Response[0] == 'Y');
}

FText GetValidGuess() //TODO change to GetValidGuess
{
	//set an invalid status until status is valid
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Characters;
	do {
		//prints current try
		//Call the function in the Global Class
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << std::endl;
		FText Guess = "";
		//gets a guess from the player
		std::cout << "Enter your guess: ";
		std::getline(std::cin, Guess);
		//initialize a variable string before storing a variable in it
		

		//check guess status
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status) //
		{
		case EGuessStatus::Invalid_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Invalid_Characters:
			std::cout << "Please enter letters only in lower case\n";
			break;
		case EGuessStatus::Not_Isogram:
			//not implemented
			std::cout << "Please enter a word with no duplicate characters\n";
	
			break;
		default:
			//assumes the guess is valid
			return Guess;
			break;
		}		
		std::cout << std::endl;
	}
	//Status is out of scope
	while (Status != EGuessStatus::OK); //keep looking until will have no errors (valid input)
	return Guess;
}



