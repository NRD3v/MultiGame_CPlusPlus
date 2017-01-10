#pragma once
#include "FHanged.h"
#include "FRandomWord.h"

FHanged::FHanged()
{
	TITLE = "the hanged";
}

FString FHanged::getTitle() const
{
	return TITLE;
}

void FHanged::getLogo()
{
	std::cout << std::endl;
	std::cout << "                                        #########\n";
	std::cout << "                                       ###########\n";
	std::cout << "  ### # # ###                            #   #  ##\n";
	std::cout << "   #  ### ##                             #    ####\n";
	std::cout << "   #  # # ###                           ###     ##\n";
	std::cout << "                                       #   #    ##\n";
	std::cout << " #   #                                 #   #    ##\n";
	std::cout << " #   #  ###                             ###     ##\n";
	std::cout << " ##### #   # #   #                       #      ##\n";
	std::cout << " #   # ##### ##  #  ###                 ###     ##\n";
	std::cout << " #   # #   # # # # #     #####         # # #    ##\n";
	std::cout << "       #   # #  ## # ### #     ####   #  #  #   ##\n";
	std::cout << "             #   # #   # ####  #   #     #      ##\n";
	std::cout << "                    ###  #     #   #    # #     ##\n";
	std::cout << "                         ##### #   #   #   #    ##\n";
	std::cout << "                               ####   #     #   ##\n";
	std::cout << "                                              ######\n";
	std::cout << std::endl;
	return;
}

void FHanged::getStatus(int32 value)
{
	// TODO : for (int32 turn = 1; turn < 11; turn++)
	switch (value)
	{
	case 1:
		std::cout << "        \n";
		std::cout << "       |\n";
		std::cout << "       |\n";
		std::cout << "       |\n";
		std::cout << "       |\n";
		std::cout << "         \n";
		break;
	case 2:
		std::cout << "        \n";
		std::cout << "       |\n";
		std::cout << "       |\n";
		std::cout << "       |\n";
		std::cout << "       |\n";
		std::cout << "      ---\n";
		break;
	case 3:
		std::cout << "   _____\n";
		std::cout << "       |\n";
		std::cout << "       |\n";
		std::cout << "       |\n";
		std::cout << "       |\n";
		std::cout << "      ---\n";
		break;
	case 4:
		std::cout << "   _____\n";
		std::cout << "     \\ |\n";
		std::cout << "      \\|\n";
		std::cout << "       |\n";
		std::cout << "       |\n";
		std::cout << "      ---\n";
		break;
	case 5:
		std::cout << "   _____\n";
		std::cout << "   | \\ |\n";
		std::cout << "      \\|\n";
		std::cout << "       |\n";
		std::cout << "       |\n";
		std::cout << "      ---\n";
		break;
	case 6:
		std::cout << "   _____\n";
		std::cout << "   | \\ |\n";
		std::cout << "   O  \\|\n";
		std::cout << "       |\n";
		std::cout << "       |\n";
		std::cout << "      ---\n";
		break;
	case 7:
		std::cout << "   _____\n";
		std::cout << "   | \\ |\n";
		std::cout << "   O  \\|\n";
		std::cout << "   |   |\n";
		std::cout << "       |\n";
		std::cout << "      ---\n";
		break;
	case 8:
		std::cout << "   _____\n";
		std::cout << "   | \\ |\n";
		std::cout << "   O  \\|\n";
		std::cout << "  /|   |\n";
		std::cout << "       |\n";
		std::cout << "      ---\n";
		break;
	case 9:
		std::cout << "   _____\n";
		std::cout << "   | \\ |\n";
		std::cout << "   O  \\|\n";
		std::cout << "  /|\\  |\n";
		std::cout << "       |\n";
		std::cout << "      ---\n";
		break;
	case 10:
		std::cout << "   _____\n";
		std::cout << "   | \\ |\n";
		std::cout << "   O  \\|\n";
		std::cout << "  /|\\  |\n";
		std::cout << "  /    |\n";
		std::cout << "      ---\n";
		break;
	case 404:
		std::cout << "   _____\n";
		std::cout << "   | \\ |\n";
		std::cout << "   O  \\|\n";
		std::cout << "  /|\\  |\n";
		std::cout << "  / \\  |\n";
		std::cout << "      ---\n";
		break;
	default:
		NULL;
		break;
	}
	return;
}

void FHanged::startGame()
{
	FTools T;
	do
	{
		guessLetter();
	} while (T.playAgain());
	return;
}

void FHanged::guessLetter()
{
	FTools T;
	FRandomWord Word;
	int32 fLimit = Word.getLimit();
	FString
		userGuess,
		fWord = T.toUppercase(Word.getRandomWord()),
		fHidden = setHidden(fWord);

	getLogo();
	std::cout << "> WELCOME TO \"" << T.toUppercase(getTitle()) << "\" GAME\n";
	std::cout << "> You have " << fLimit << " tries to find the following ";
	std::cout << fWord.length() << " letter(s) word.\n";
	std::cout << "> Good luck!\n\n";
	for (int32 turn = 1; turn < fLimit; turn++)
	{
		std::cout << "> Try " << turn << " / " << fLimit << " (";
		display(fHidden);
		std::cout << ") : ";
		while (!(std::cin >> userGuess)) {
			std::cin.clear();
			std::cout << "\n> Incorrect input. Please try again.\n\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "> Try " << turn << " / " << fLimit << " : ";
		};
		FString fGuess = T.toUppercase(userGuess);
		bool validGuess = false;
		do
		{
			if (fGuess.length() == fWord.length())
			{
				if (fGuess == fWord)
				{
					FString tries = (turn == 1) ? "try" : "tries";
					std::cout << "Well done! You found " << fWord << " in " << turn << " " << tries << ".\n";
					return;
				}
			}
			else if (fGuess.length() > 1)
			{
				for (char i = 0; i < fGuess.length(); i++)
				{
					for (int32 j = 0; j < fWord.length(); j++)
					{
						if (fWord[j] == fGuess[i])
						{
							fHidden[j] = fGuess[i];
							validGuess = true;
						}
						if (fHidden == fWord)
						{
							FString tries = (turn == 1) ? "try" : "tries";
							std::cout << "Well done! You found " << fWord << " in " << turn << " " << tries << ".\n";
							return;
						}
					}
					turn++;
					if (validGuess) turn--;
				}
			}
			else
			{
				for (int32 i = 0; i < fWord.length(); i++)
				{
					if (fWord[i] == fGuess[0])
					{
						fHidden[i] = fGuess[0];
					}
					if (fHidden == fWord)
					{
						FString tries = (turn == 1) ? "try" : "tries";
						std::cout << "Well done! You found " << fWord << " in " << turn << " " << tries << ".\n";
						return;
					}
				}
			}
		} while (fHidden == fWord);
		getStatus(turn);
		std::cout << turn << std::endl;
	};
	getStatus(404);
	std::cout << "\nYou failed finding the word : " << fWord << "\n\n";
	return;
}

void FHanged::display(FString value)
{
	bool first = true;
	for (auto& elem : value)
	{
		if (!first) printf(" ");
		std::cout << elem;
		first = false;
	};
}

FString FHanged::setHidden(FString value)
{
	for (char i = 0; i < value.length(); i++)
	{
		std::replace(value.begin(), value.end(), value[i], '_');
	}
	return value;
}
