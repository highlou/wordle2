#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <csignal>

#include "colour.hh"
#include "random.hh"
#include "util.hh"
#include "wordle.hh"

int main()
{
	// Set input modes.
	if (setRaw())
	{
		std::atexit([]() { resetRaw(); });
		std::signal(SIGINT, SIG_DFL);
	}

	// Print an introduction.
	std::printf(
		"Terminal Wordle - A game that is like Wordle, but is played in a terminal.\n"
		"You can play Wordle at <https://powerlanguage.co.uk/wordle>.\n\n"
		"Colours:\n"
		"\tRed     - The letter doesn\'t exist\n"
		"\tYellow  - The letter exists but is in the wrong place.\n"
		"\tGreen   - The letter exists and is in the right place.\n\n"
	);

	// Create a Wordle engine.
	WordleEngine wordle;

	// Give the engine a random word.
	// wordle.setWord(toUpperCase(getRandomWord()));
	wordle.setWord(toUpperCase(getRandomWord()));

	// Initialise the engine.
	if (!wordle.init())
	{
		// Initialisation failed.
		std::fprintf(stderr, "Initialisation of Wordle engine failed.\n");
		return EXIT_FAILURE;
	}

	// Run the engine.
	for (unsigned attempt = 0; attempt < 6 && !wordle.isCorrect(); ++attempt)
	{
		std::string inputstring;
		static char prompt[0x40];
		
		// Make a prompt.
		std::snprintf(prompt, sizeof(prompt), "Five-letter word (attempt %u): ", attempt + 1);

		// Get input.
		while (inputstring.size() != 5)
		{
			if (inputstring.size() != 0)
			{
				std::printf("\"%s\" is not a five-letter word.\n", inputstring.c_str());
			}
			inputstring = toUpperCase(getInput(prompt));
		}

		// Judge the word.
		std::vector<WordleEngine::Clue> clues = wordle.judgeWord(inputstring);

		// Print the clues.
		for (std::size_t i = 0; i < clues.size(); ++i)
		{
			unsigned char colour;
			switch (clues[i])
			{
			case WordleEngine::Correct: colour = F_GREEN; break;
			case WordleEngine::Misplaced: colour = F_YELLOW; break;
			default: colour = F_RED; break;
			};
			putcColour(inputstring[i], colour);
		}
		std::printf("\n");
	}

	// Print a message.
	if (wordle.isCorrect())
	{
		std::printf("Correct!\n");
	}
	else
	{
		std::printf("Incorrect. The word is %s\n", wordle.getWord().c_str());
	}

	return EXIT_SUCCESS;
}
