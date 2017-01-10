#pragma once
#include "FMoreOrLess.h"
#include "FHanged.h"

#include "FRandomWord.h"

void test();

int main()
{
	//test();
	FTools T;
	FHanged H;
	FMoreOrLess MOL;
	std::cout << "CHOOSE YOUR GAME :\n";
	std::cout << std::endl;
	std::cout << "Press 1 => " << T.capitalizeFirst(MOL.getTitle()) << std::endl;
	std::cout << "Press 2 => " << T.capitalizeFirst(H.getTitle()) << std::endl;
	std::cout << "Press 3 => Mastermind\n";
	std::cout << std::endl;
	std::cout << "Your choice (press any other key to exit) : ";
	int32 userChoice;
	std::cin >> userChoice;
	std::cout << std::endl;
	if (userChoice)
	{
		switch (userChoice)
		{
			case 1:
				MOL.startGame();
				break;
			case 2:
				H.startGame();
				break;
			case 3:
				// TODO : Mastermind
				break;
			default:
				return 0;
				break;
		}
	}
	return 0;
}

void test()
{
	FTools T;
	FHanged H;
	FRandomWord Word;
	int32 fLimit = Word.getLimit();
	FString
		userGuess,
		fWord = Word.getRandomWord(),
		fHidden = H.setHidden(fWord);

	std::cout << "Word : " << fWord << ", Limit : " << fLimit;
	std::cout << "\nHidden : ";
	H.display(fHidden);

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}
