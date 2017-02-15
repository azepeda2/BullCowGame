#pragma once

#include "FBullCowGame.h"
#include <map>
#include <vector>
#include <iostream>


// to make syntax Unreal friendly
#define TMap std::map
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); } //default constructor

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
bool FBullCowGame::IsGameWon() const { return bIsGameWon; }
std::vector<FString> HiddenWords = { "fly", "back", "bat", "bowl", "bowling", "fowl", "camp", "jaw", "jump", "brick",
"bling", "drying", "dying", "boxing", "trick", "jordan", "blacksmith", "gunpowder", "abolishment", "atmospheric",
"backgrounds","campgrounds", "complainers", "countryside", "dangerously", "disgraceful", "disturbance", "documentary",
"facetiously", "fracedinous", "filmography", "fluoridates", "lumberjacks", "misanthropy", "nefariously", "palindromes",
"personality", "playgrounds", "playwrights", "precautions", "predictably", "republicans", "semordnilap", "speculation",
"stenography", "subordinate", "trampolines", "undesirably", "vouchsafing", "workmanship" };

//makes use of random seed in main.cpp to ensure random word is picked
FString FBullCowGame::ChooseHiddenWord() const
{
	int key = std::rand() % HiddenWords.size();
	std::cout << "randint = " << key << "\n";
	return HiddenWords.at(key);
}

int32 FBullCowGame::GetMaxTries() const 
{ 
	TMap<int32, int32> WordLengthToMaxTries{ {3,4}, {4,7}, {5,10}, {6,16}, {7,20}, {8,20}, {9,25}, {10,30}, {11,35} };
	return WordLengthToMaxTries[MyHiddenWord.length()]; 
}


void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = ChooseHiddenWord(); // this must be an isogram
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bIsGameWon = false;

	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const 
{ 
	if (!IsIsogram(Guess)) {
		return EGuessStatus::NOT_ISOGRAM;
	}
	else if (!IsLowercase(Guess)) {
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != MyHiddenWord.length()) {
		return EGuessStatus::Wrong_Length;
	}
	else {
		return EGuessStatus::OK;
	}
}


FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 HiddenWordLength = MyHiddenWord.length();

	for (int32 i = 0; i < HiddenWordLength; i++) {

		for (int32 j = 0; j < HiddenWordLength; j++) {
			if (Guess[j] == MyHiddenWord[i]) {
				if (i == j) {
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}
			}
		}
	}
	if (BullCowCount.Bulls == HiddenWordLength) {
		bIsGameWon = true;
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Guess) const
{
	if (Guess.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;
	for (char Letter : Guess) {
		Letter = tolower(Letter);
		if (LetterSeen[Letter]) {
			return false;
		}
		else {
			LetterSeen[Letter] = true;
		}
	}
	return true; //just in case of '/0' being entered
}

bool FBullCowGame::IsLowercase(FString Guess) const
{
	for (char Letter : Guess) {
		if (!islower(Letter)) {
			return false;
		}
	}
	return true;
}
