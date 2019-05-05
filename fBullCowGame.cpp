#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include "fBullCowGame.h"
#include <map>
//#define TMAP std::map; will cause errors!
#define TMap std::map

using int32 = int;

//start with constructor, then methods
//constructor
FBullCowGame::FBullCowGame()
{
	//sets these up automatically when class FBullCowGame is called

	//bool IsIsogram(std::string);
	void Reset();
}

void FBullCowGame::Reset() //default constructor
{

	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	MyHiddenWord = HIDDEN_WORD;
	bGameIsWon = false;
	std::cout << "Game Resetting" << std::endl;
	return;
}

int32 FBullCowGame::GetMaxTries() const
{
	//test and adjust difficulty accordingly
	TMap<int32, int32> WordLengthMaxTries{ {3,4}, {4,6}, {5,10}, {6,15} };
	//populate word length: max tries map
	//play test to find sweet spot
	//declaration takes us to the header file. definition is the content.
	return WordLengthMaxTries[MyHiddenWord.length];
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

//I could not set GetHiddenWordLength to int32 because it was constructed as a string
int32 FBullCowGame::GetHiddenWordLength() const
{

	return MyHiddenWord.length();
}

bool FBullCowGame::IsGameWon() const
{
	return bGameIsWon;
}





EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	//if the guess is not an isogram, return an error
	if (!IsIsogram(Guess))
	{
		return EGuessStatus::Not_Isogram;
	}
	//if guess is not pure lowercase, return an error
	else if (!all_of(Guess.begin(), Guess.end(), &::islower))
	{
		return EGuessStatus::Invalid_Characters;
	}
	//if guess length is incorrect, return an error
	else if (GetHiddenWordLength() != Guess.length())
	{
		return EGuessStatus::Invalid_Length;
	}
	else
	{
		//otherwise, return OK
		return EGuessStatus::OK; //TODO make actual error
	}
}

//receives a VALID guess, increments

BullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	//increment turn number
	MyCurrentTry++;
	//set up a return variable. Re-initializes bulls and cows to zero
	//type is BullCowCount.  We're initializing a new variable BullCowCount
	BullCowCount BullCowCount;
	//loop through all letters in the guess
	int32 WordLength = MyHiddenWord.length(); //assumes same length as guess

	for (int32 HWChar = 0; HWChar < WordLength; HWChar++)
	{
		//compare letters against hidden word

		//renamed to HWChar for debugging
		if (Guess[HWChar] == MyHiddenWord[HWChar])
		{
			BullCowCount.Bulls++;
		}
		else
		{
			//renamed to GChar for debugging
			for (int32 GChar = 0; GChar < WordLength; GChar++)
			{
				//if they match, increment bulls if they're in the same place.

				if (Guess[HWChar] == MyHiddenWord[GChar])
				{
					BullCowCount.Cows++; //must be a cow
				}
			}
		}

		//see if the game is won after submitting word length

		if (BullCowCount.Bulls == WordLength)
		{
			bGameIsWon = true;
		}
		else
		{
			bGameIsWon = false;
		}

	
	}
		return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	//treat 0 and 1 letter words as isograms
	if (Word.length() <= 1)
	{
		return true;
	}

	TMap<char, bool> LetterSeen; //setup the map
	for (auto Letter : Word) //for all letters of the word:
	{
		Letter = tolower(Letter); //handle mixed case
		if (LetterSeen[Letter]) {
			return false; //we do NOT have an isogram
		}
		else {
			LetterSeen[Letter] = true;
		}
	}

	return true;
}

bool FBullCowGame::IsLowerCase(FString Word) const
{
	for (auto Letter : Word)
	{
		// if not a lowercase letter
		if (!islower(Letter))
		{
			return false;
		}
	}
		return true;
	}

