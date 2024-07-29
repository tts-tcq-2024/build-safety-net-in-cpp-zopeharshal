#ifndef SOUNDEX_HPP
#define SOUNDEX_HPP

#include <string>

// Declaration of functions
char getSoundexCode(char c);
bool SoundexLengthCheck(const std::string& soundex);
bool SoundexCodeCheck(char code, char prevCode);
std::string IncrementSoundex(const std::string& soundex, const std::string& name, char prevCode);
std::string generateSoundex(const std::string& name);
std::string padSoundex(const std::string& soundex);

#endif // SOUNDEX_HPP
