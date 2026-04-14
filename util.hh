#include <string>

#ifndef __WORDLE2__UTIL_HH_
#define __WORDLE2__UTIL_HH_

bool setRaw();
bool resetRaw();
bool isRaw();

std::string toUpperCase(const std::string& s);
std::string getInput(const std::string& prompt = "");

#endif // __WORDLE2__UTIL_HH_
