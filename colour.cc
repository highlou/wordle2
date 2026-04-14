#include "colour.hh"

void putcColour(char ch, unsigned char colour)
{
	static const unsigned char lookup[8] =
	{ 0b000, 0b100, 0b010, 0b110, 0b001, 0b101, 0b011, 0b111 };
	std::printf(
		"\033[%u;%um%c\033[39m",
		30 + lookup[colour % 8],
		40 + lookup[(colour >> 4) % 8],
		ch
	);
}
