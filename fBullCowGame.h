#pragma once

//makes sure any imports are imported once
//Prefix classes by f
//OS X C++ file, next FBullCowGame
//include in main.cpp, fBullCowGame.cpp
//what all the methods you can:
//write as many simple signatures as you can
//don't worry about getting it right, there is no right.  Point is to think
//enjoy working at a higher level

//using namespace is bad
//Including our own header file

//what does this line do?
#pragma once
#include <string>
using FString = std::string;
using int32 = int;

//struct is a class, but members are Public.
struct BullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

//enumerates all possible failures
enum class EGuessStatus {
	OK,
	Not_Isogram,
	Not_Lower_Case,
	Invalid_Length,
	Invalid_Characters
};

class FBullCowGame {
public:
	//Constructor
	FBullCowGame();

	//declare a constant by using const at the END
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	const FString HIDDEN_WORD = "planet";
	const int32 MAX_TRIES = 5;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;


	EGuessStatus CheckGuessValidity(FString) const; //TODO make a more rich return value.
	void Reset(); //TODO make a more rich return value.
	//counts bulls & cows, and increases try # assuming valid guess
	BullCowCount SubmitValidGuess(FString);


//Please try and ignore this and focus on the interface above ^^
private:

	//see constructor for initialization
	int32 MyCurrentTry=1;
	int32 MyMaxTries=5;
	FString MyHiddenWord;
	bool bGameIsWon = false;
	bool IsIsogram(FString) const;
	bool IsLowerCase(FString) const;

};

