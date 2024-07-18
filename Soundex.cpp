char getSoundexCode(char c) {
    c = toupper(c);
    switch (c) {
        case 'B': case 'F': case 'P': case 'V': return '1';
        case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
        case 'D': case 'T': return '3';
        case 'L': return '4';
        case 'M': case 'N': return '5';
        case 'R': return '6';
        default: return '0'; // Ignored characters
    }
}

bool shouldIgnoreChar(char c) {
    return std::string("AEIOUHYW").find(toupper(c)) != std::string::npos;
}

std::string processCharacter(char currentChar, char& prevCode, std::string& soundex) {
    if (shouldIgnoreChar(currentChar)) return "";

    char currentCode = getSoundexCode(currentChar);
    if (currentCode != '0' && currentCode != prevCode) {
        soundex += currentCode;
        prevCode = currentCode;
    }
    return "";
}

std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "0000";

    std::string soundex(1, toupper(name[0]));
    char prevCode = getSoundexCode(name[0]);

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        processCharacter(name[i], prevCode, soundex);
    }

    while (soundex.length() < 4) {
        soundex += '0';
    }

    return soundex;
}
