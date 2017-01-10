#include "FTools.h"
#include "FRandomWord.h"

FRandomWord::FRandomWord()
{
	RandomWord = setRandomWord();
	LIMIT = setLimit(RandomWord);
}

FString FRandomWord::getRandomWord() const
{
	return RandomWord;
}

int32 FRandomWord::getLimit() const
{
	return LIMIT;
}

FString FRandomWord::setRandomWord()
{
	FTools T;
	FString RandomWord;
	return T.toUppercase("test");
}

int32 FRandomWord::setLimit(FString value)
{
	return LIMIT = round(value.length() * 1.5);
}
