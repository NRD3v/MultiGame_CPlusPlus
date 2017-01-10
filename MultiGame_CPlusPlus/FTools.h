#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <random>

using FString = std::string;
using int32 = int;

class FTools
{
	public:
		FString capitalizeFirst(FString);
		FString toUppercase(FString);
		bool playAgain();
};
