#pragma once
#include "FTools.h"

class FMoreOrLess
{
	public:
		// Constructor
		FMoreOrLess();
		
		// Getters
		FString getTitle() const;
		int32 getLimit() const;
		void getLogo();
		void startGame();
		void guessNumber();

		// Setters
		FString setTitle(FString);
		int32 setLimit(int32);

	private:
		int32 LIMIT;
		FString TITLE;
};
