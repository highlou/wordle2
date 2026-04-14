#include "random.hh"

#include <random>
#include <ctime>

std::uintmax_t getRandomNumber(std::uintmax_t min, std::uintmax_t maxplus1)
{
	std::uniform_int_distribution<std::uintmax_t> distrib(min, maxplus1 - 1);
	std::mt19937_64 engine;
	engine.seed(std::time(nullptr));
	return distrib(engine);
}

std::string getRandomWord()
{
	extern const char* wordlist[];
	std::size_t wordlist_size = 0;
	// Calculate size of word list.
	for (; wordlist[wordlist_size]; ++wordlist_size) { }
	// Return random word.
	return wordlist[getRandomNumber(0, wordlist_size)];
}
