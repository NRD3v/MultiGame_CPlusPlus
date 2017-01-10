#pragma once
#include "FRandomNumber.h"

FRandomNumber::FRandomNumber()
{
	MIN = setMin(0);
	MAX = setMax(100);
	RandomNumber = setRandomNumber();
}

int32 FRandomNumber::getMin() const
{
	return MIN;
}

int32 FRandomNumber::getMax() const
{
	return MAX;
}

int32 FRandomNumber::getRandomNumber() const
{
	return RandomNumber;
}

int32  FRandomNumber::setMin(int32 value)
{
	return MIN = value;
}

int32  FRandomNumber::setMax(int32 value)
{
	return MAX = value;
}

int32 FRandomNumber::setRandomNumber()
{
	// rand() % MAX + MIN || MIN + (rand() % (int32)(MAX - MIN + 1));
	std::random_device round;
	std::mt19937 range(round());
	std::uniform_int_distribution<int32> uni(getMin(), getMax());
	auto randomNumber = uni(range);
	return randomNumber;
}
