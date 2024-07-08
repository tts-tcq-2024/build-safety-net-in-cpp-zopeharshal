#include "Soundex.h"
#include <cctype>
#include <unordered_map>

char getSoundexCode(char c) {
    switch (std::toupper(c)) {
        case 'B': case 'F': case 'P': case 'V': return '1';
        case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
        case 'D': case 'T': return '3';
        case 'L': return '4';
        case 'M': case 'N': return '5';
        case 'R': return '6';
        default: return '0'; // A, E, I, O, U, Y, H, W map to '0'
    }
}

std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex;
    soundex += std::toupper(name[0]);

    char prevCode = getSoundexCode(name[0]);

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != prevCode) {
            soundex += code;
            prevCode = code;
        }
    }

    while (soundex.length() < 4) {
        soundex += '0';
    }

    return soundex;
}
