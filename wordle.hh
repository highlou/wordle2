#include <string>
#include <vector>

#ifndef __WORDLE2__WORDLE_HH_
#define __WORDLE2__WORDLE_HH_

// An engine that can simulate Wordle, a game you can play at
// <https://powerlanguage.co.uk/wordle>, or if that does not work,
// <https://www.nytimes.com/games/wordle/index.html>.
class WordleEngine
{
public:
	// A clue.
	// Correct    - The letter is in the word and is in the correct position.
	// Misplaced  - The letter is in the word but is not in the correct position.
	// Incorrect  - The letter does not exist in the word.
	enum Clue : unsigned char
	{
		Correct, Misplaced, Incorrect,
	};
private:
	std::string m_correctword;
	std::size_t m_wordsize;
	bool m_correct = false;
public:
	// Constructor, does not do anything.
	WordleEngine();
	// Initialise the wordle game.
	bool init();
	// Compare a given word to the correct word.
	// @param word The word to compare to the correct word.
	// @return The clues that express the similarities and differences
	// between the given word and the correct word. Each clue corresponds to
	// each letter of the given word (e.g. the second clue is for the second
	// letter of the given word).
	std::vector<Clue> judgeWord(const std::string& word);
	// Set the correct word of the engine.
	void setWord(const std::string& word);
	// Get the correct word of the engine.
	std::string getWord();
	// Returns TRUE if the correct word was solved, FALSE otherwise.
	bool isCorrect();
};

#endif // __WORDLE2__WORDLE_HH_
