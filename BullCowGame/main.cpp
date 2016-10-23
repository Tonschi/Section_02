#include <string>
#include <iostream>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

// the program starts here
int main()
{
	do	
	{
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain() == true);
	
	// exit application
	return 0;
}

void PlayGame()
{
	FBullCowGame BCGame; // instantiate a new game (create an instance of the game)
	// set maximum guesses
	constexpr int MAX_TRIES = 2;

	// ask the user X times
	for (int count = 1; count <= MAX_TRIES; count++)
	{
		std::string Guess = GetGuess();
		
		//print the guess back
		std::cout << "You guessed: " << Guess << ".\n\n";
	}
}

void PrintIntro() 
{
	// introduce the game
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n\n";
	return;
}

std::string GetGuess()
{
	// get a guess from the user
	std::cout << "Enter your guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (yes/no)\n";
	std::string Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;
	// return true if the player wants to replay the game
	return (Response[0] == 'y' || Response[0] == 'Y');
}
