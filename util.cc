#include "util.hh"

#include <iostream>
#include <algorithm>
#include <termios.h>
#include <unistd.h>

struct termios old;
bool rawMode = false;

bool setRaw()
{
	if (tcgetattr(STDIN_FILENO, &old) < 0)
	{
		return false;
	}

	struct termios raw = old;

	raw.c_lflag &= ~(ECHO | ICANON);

	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) < 0)
	{
		return false;
	}

	rawMode = true;
	
	return true;
}

bool resetRaw()
{
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &old) < 0)
	{
		return false;
	}

	rawMode = false;

	return true;
}

bool isRaw()
{
	return rawMode;
}

std::string toUpperCase(const std::string& s)
{
	std::string result = s;
	std::transform(result.begin(), result.end(), result.begin(),
		[](unsigned char c) -> unsigned char { return ::toupper(c); });
	return result;
}

std::string getInput(const std::string& prompt)
{
	std::printf("%s", prompt.c_str());
	std::fflush(stdout);
	
	std::string result;
	if (!isRaw())
	{
		std::getline(std::cin, result);
	}
	else
	{
		char c;
		while ((c = std::fgetc(stdin)) != '\n' && c != '\0')
		{
			if (std::isalpha((unsigned char)c)) // Letter.
			{
				result += c;
				std::fputc(c, stdout);
				std::fflush(stdout);
			}
			else if (c == '\b' || c == '\x7f') // Backspace.
			{
				if (result.size() > 0)
				{
					std::printf("\b \b");
					std::fflush(stdout);
					result.pop_back();
				}
			}
		}
		std::fputc('\n', stdout);
	}
	
	return result;
}
