#pragma once
#include "FTools.h"

FString FTools::capitalizeFirst(FString value)
{
	value[0] = toupper(value[0]);
	for (int i = 1; i < value.length(); i++)
	{
		if (value[i] != ' ')
		{
			value[i] = tolower(value[i]);
		}
		if (value[i] == ' ')
		{
			value[i + 1] = toupper(value[i + 1]);
			i++;
		}
	}
	return value;
}

FString FTools::toUppercase(FString value)
{
	std::transform(value.begin(), value.end(), value.begin(), [](unsigned char c) { return std::toupper(c); });
	return value;
}

bool FTools::playAgain()
{
	FString Answer;
	std::cout << "Would you like to play again (Y / N) ? ";
	while (Answer.empty() || Answer != "y" || Answer != "n")
	{
		std::getline(std::cin, Answer);
		if (Answer == "y" || Answer == "Y") {
			std::cout << "\n";
			return true;
		}
		else if (Answer == "n" || Answer == "N")
		{
			return false;
		}
	}
	return false;
}
