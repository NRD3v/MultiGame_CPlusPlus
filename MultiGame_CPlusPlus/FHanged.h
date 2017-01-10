#pragma once
#include "FTools.h"

class FHanged
{
	public:
		// Constructor
		FHanged();
		
		// Getters
		FString getTitle() const;
		void getLogo();
		void getStatus(int32);

		// Actions
		void startGame();
		void guessLetter();
		void display(FString);

		// Setters
		FString setHidden(FString);
		FString setTitle(FString);

	private:
		FString TITLE;
};
