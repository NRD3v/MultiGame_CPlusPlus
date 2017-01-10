#pragma once
#include "FMoreOrLess.h"
#include "FRandomNumber.h"
#include "FHanged.h" // TODO : remove

FMoreOrLess::FMoreOrLess()
{
	LIMIT = setLimit(11);
	TITLE = setTitle("more or less");
}

FString FMoreOrLess::getTitle() const
{
	return TITLE;
}

int32 FMoreOrLess::getLimit() const
{
	return LIMIT;
}

void FMoreOrLess::getLogo()
{
	std::cout << std::endl;
	std::cout << "       ###          #####    #######\n";
	std::cout << "      #   #        #     #   #       #\n";
	std::cout << "      #   #       #       #  #  ###   #\n";
	std::cout << "   ###     ###   #   ###   # #  #  #  #   ###########\n";
	std::cout << "  #           #  #  #   #  # #  ###   #  #           #\n";
	std::cout << "  #           #  #  #   #  # #       #   #           #\n";
	std::cout << "   ###     ###   #   ###   # #  #   #     ###########\n";
	std::cout << "      #   #       #       #  #  # #   #\n";
	std::cout << "      #   #        #     #   #  #  #  #\n";
	std::cout << "       ###          #####    ####  ####\n";
	std::cout << std::endl; 
	return;
}

void FMoreOrLess::startGame()
{
	FTools T;
	do
	{
		guessNumber();
	} while (T.playAgain());
	return;
}

void FMoreOrLess::guessNumber()
{
	FTools T;
	FRandomNumber Number;
	int32
		userGuess,
		fLimit = getLimit(),
		fMin = Number.getMin(),
		fMax = Number.getMax(),
		fNumber = Number.getRandomNumber();

	getLogo();
	std::cout << "=> WELCOME TO THE \"" << T.toUppercase(getTitle()) << "\" GAME\n";
	std::cout << "=> You have " << fLimit - 1 << " tries to find a number between " << fMin << " and " << fMax << ".\n";
	std::cout << "=> Good luck!\n\n";
	// std::cout << fNumber << std::endl; // TODO : remove debug display
	for (int32 turn = 1; turn < fLimit; turn++)
	{
		std::cout << "Try no " << turn << " : ";
		while (!(std::cin >> userGuess)) {
			std::cin.clear();
			std::cout << "\nIncorrect input. Please try again.\n\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Try no " << turn << " : ";
		}
		if (userGuess == fNumber)
		{
			FString tries = (turn == 1) ? "try" : "tries";
			std::cout << "Well done! You found " << userGuess << " in " << turn << " " << tries << ".\n";
			return;
		}
		FString state = (userGuess < fNumber) ? "bigger\n" : "smaller\n";
		std::cout << "\nThe number is " << state << std::endl;
	}
	std::cout << "\nYou failed finding the number : " << fNumber << "\n\n";
	return;
}

FString FMoreOrLess::setTitle(FString value)
{
	return TITLE = value;
}

int32 FMoreOrLess::setLimit(int32 value)
{
	return LIMIT = value;
}
