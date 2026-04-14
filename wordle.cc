#include "wordle.hh"

// WordleEngine::*

WordleEngine::WordleEngine() { }

bool WordleEngine::init()
{
	if (m_correctword.size() == 0)
	{
		return false;
	}
	
	m_wordsize = m_correctword.size();
	m_correct = false;

	return true;
}

std::vector<WordleEngine::Clue> WordleEngine::judgeWord(const std::string& word)
{
	std::vector<Clue> clues;
	std::size_t len = word.size() > m_correctword.size() ? m_correctword.size() : word.size();
	std::string correctword_copy = m_correctword;
	for (std::size_t i = 0; i < len; ++i)
	{
		std::size_t location = i;
		char ch = word[i];
		Clue clue = Incorrect;

		// Correct.
		if (ch == correctword_copy[i])
		{
			clue = Correct;
		}
		else // Try to search for the word.
		{
			// Search for an unoccupied letter.
			// if it exists, set `colour` to yellow.
			location = -1;
			while ((location = correctword_copy.find(ch, location + 1)) != std::string::npos)
			{
				if (correctword_copy[location] != word[location])
				{
					clue = Misplaced;
					break;
				}
			}
		}

		// If the letter exists, make the letter occupied.
		if (clue != Incorrect)
		{
			correctword_copy[location] = '\0';
		}

		// Push the clue.
		clues.push_back(clue);
	}

	// Set `m_correct` to TRUE if the word is correct.
	if (word == m_correctword)
	{
		m_correct = true;
	}

	// Return the clues.
	return clues;
}

void WordleEngine::setWord(const std::string& word)
{
	m_correctword = word;
}

std::string WordleEngine::getWord()
{
	return m_correctword;
}

bool WordleEngine::isCorrect()
{
	return m_correct;
}
