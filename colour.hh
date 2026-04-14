#include <string>

#ifndef __WORDLE2__COLOUR_HH_
#define __WORDLE2__COLOUR_HH_

// Colours.
enum Colours : unsigned char
{
	F_BLACK    = 0x00,
	F_BLUE     = 0x01,
	F_GREEN    = 0x02,
	F_CYAN     = 0x03,
	F_RED      = 0x04,
	F_MAGENTA  = 0x05,
	F_YELLOW   = 0x06,
	F_WHITE    = 0x07,

	B_BLACK    = 0x00,
	B_BLUE     = 0x10,
	B_GREEN    = 0x20,
	B_CYAN     = 0x30,
	B_RED      = 0x40,
	B_MAGENTA  = 0x50,
	B_YELLOW   = 0x60,
	B_WHITE    = 0x70,
};

// Print coloured character.
void putcColour(char ch, unsigned char colour);

#endif // __WORDLE2__COLOUR_HH_
