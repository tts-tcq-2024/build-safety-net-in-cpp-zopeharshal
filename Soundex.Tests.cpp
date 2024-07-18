#include <cassert>

void testSoundex() {
    assert(generateSoundex("Robert") == "R163");
    assert(generateSoundex("Rupert") == "R163");
    assert(generateSoundex("Rubin") == "R150");
    assert(generateSoundex("Yves") == "Y120");
    assert(generateSoundex("A") == "A000");
    assert(generateSoundex("") == "0000");
    assert(generateSoundex("Carter") == "C363");
    assert(generateSoundex("Katherine") == "K345");
}

int main() {
    testSoundex();
    return 0;
}
