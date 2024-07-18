#include <cassert>
#include <iostream>

void testGenerateSoundex() {
    // Basic tests
    assert(generateSoundex("Robert") == "R163");
    assert(generateSoundex("Rupert") == "R163");
    assert(generateSoundex("Rubin") == "R150");

    // Edge cases
    assert(generateSoundex("") == "0000"); // Test for empty input
    assert(generateSoundex("A") == "A000"); // Single character
    assert(generateSoundex("E") == "E000"); // Vowel input
    assert(generateSoundex("C") == "C000"); // Single consonant

    // Testing with different cases
    assert(generateSoundex("bobby") == "B010"); // Mixed case
    assert(generateSoundex("Smythe") == "S530"); // Testing uncommon names

    // Test with names containing similar letters
    assert(generateSoundex("Tymothy") == "T530"); // Y and T should be compressed
}

int main() {
    testGenerateSoundex();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
