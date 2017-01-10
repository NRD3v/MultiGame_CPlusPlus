#pragma once
#include "FTools.h"

class FRandomNumber
{
	public:
		FRandomNumber();

		// Getters
		int32
			getMin() const,
			getMax() const,
			getRandomNumber() const;

		// Setters
		int32 
			setMin(int32),
			setMax(int32),
			setRandomNumber();

	private:
		int32
			MIN,
			MAX,
			RandomNumber;
};
