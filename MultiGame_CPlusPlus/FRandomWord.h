#pragma once
#include "FTools.h"

class FRandomWord
{
	public:
		// Constructor
		FRandomWord();

		// Getters
		FString getRandomWord() const;
		int32 getLimit() const;

		// Setters
		FString setRandomWord();
		int32 setLimit(FString);

	private:
		FString RandomWord;
		int32 LIMIT;
};
