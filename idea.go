// Created 2022-03-27
// 
// File extension is .go just for the syntax hylighting.
// 

/*

print intro
loop:
	if the user lost in 6 attempts, exit the loop
	get word
	judge word
	print the correct, incorrect, and misplaced letters
	if word is correct, exit the loop
	increment the number of attempts
	loop again

if the user was correct, print a good message
else, print a bad message

exit

*/

// PSEUDOCODE 1

bool correct = false;
const string correctword = touppercase(getrandom5letterword());

print("Welcome to Wordle");

// Gameloop.
for (int attempt in 0 ... 6)
{
	// Get input.
	string inputword = touppercase(get5letterinput());
	stringcolour clues;
	string correctword_copy = correctword;
	// See if the inputted word is correct or not.
	for (int i in 0 ... inputword.length())
	{
		int clue = C_INCORRECT;
		uint location = 0;
		char c = inputword[i];
		// Search for the character.
		if (c == correctword_copy[i])
		{
			clue = C_CORRECT;
			correctword_copy[i] = 0;
		}
		else if ((location = find(correctword_copy, c)) != corectword_copy.end())
		{
			clue = C_MISPLACED;
			correctword_copy[location] = 0;
		}
		// Determine the colour of the letter.
		byte colour;
		if (clue == C_CORRECT)
			colour = F_GREEN;
		else if (clue == C_MISPLACED)
			colour = F_YELLOW;
		else
			colour = F_RED;
		// Append to clues.
		clues += { ch: c, colour: colour };
	}
	// Print the correct, misplaced, and the incorrect characters.
	print_colour(clues);
	// Check if the user is correct.
	if (inputword == correctword)
	{
		correct = true;
		break;
	}
}

if (correct)
{
	print("Correct!");
}
else
{
	print("You lost! The word was %s.", correctword);
}

exit(0);

// PSEUDOCODE 2

print("Welcome to Terminal Wordle!");
const string correctword = "world";
bool correct = false;

for (uint attempt = 0; attempt < 6; ++attempt)
{
	string inputstring = getguess();
	string correctword_copy = correctword;
	for (uint i = 0; i < len(inputstring); ++i)
	{
		char ch = inputstring[i];
		colour colr = F_RED;
		uint location = i;
		if (ch == correctword_copy[i]) // Correct.
		{
			colr = F_GREEN;
		}
		else // Try to search for the letter.
		{
			// search for an unoccupied letter,
			// if letter is found, set the colour to yellow.
			location = (uint)-1;
			while ((location = find(correctword_copy, len(correctword_copy), ch, location + 1)) != len(correctword_copy))
			{
				if (correctword_copy[location] != inputstring[location])
				{
					colr = F_YELLOW;
					break;
				}
			}
		}
		if (colr != F_RED)
		{
			correctword_copy[location] = 1;
		}
		printc_colour(ch, colr);
	}
	printc('\n');
	if (inputstring == correctword) // Fully correct.
	{
		correct = true;
		break;
	}
}

if (correct)
{
	print("Correct!");
}
else
{
	print("Incorrect. The word is ", correctword);
}
