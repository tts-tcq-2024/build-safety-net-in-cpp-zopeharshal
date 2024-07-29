#include "Soundex.h"
#include <gtest/gtest.h>

class SoundexTest : public ::testing::Test {
protected: 
    SoundexTest() {
        // Initialize objects or perform setup steps
    }

    virtual ~SoundexTest() {
     
    }

};

// Unit tests

// Test case for getSoundexCode function
TEST_F(SoundexTest, GetSoundexCodeTest) {
    EXPECT_EQ(getSoundexCode('A'), '0'); 
    EXPECT_EQ(getSoundexCode('B'), '1'); 
    EXPECT_EQ(getSoundexCode('C'), '2');
    EXPECT_EQ(getSoundexCode('Z'), '2'); 
}

// Test case for SoundexLengthCheck function
TEST_F(SoundexTest, SoundexLengthCheckTest) {
    EXPECT_TRUE(SoundexLengthCheck("123")); 
    EXPECT_FALSE(SoundexLengthCheck("1234")); 
}

// Test case for SoundexCodeCheck function
TEST_F(SoundexTest, SoundexCodeCheckTest) {
    EXPECT_TRUE(SoundexCodeCheck('1', '0')); 
    EXPECT_FALSE(SoundexCodeCheck('1', '1')); 
}

// Test case for IncrementSoundex function
TEST_F(SoundexTest, IncrementSoundexTest) {
    EXPECT_EQ(IncrementSoundex("S", "Smith", getSoundexCode('S')), "S503"); 
    EXPECT_EQ(IncrementSoundex("S", "Johnson", getSoundexCode('S')), "S005"); 
}

// Test case for generateSoundex function
TEST_F(SoundexTest, GenerateSoundexTest) {
    EXPECT_EQ(generateSoundex("Smith"), "S503"); 
    EXPECT_EQ(generateSoundex("Johnson"), "J005"); 
    EXPECT_EQ(generateSoundex(""), "");
}

// Test case for padSoundex function
TEST_F(SoundexTest, PadSoundexTest) {
    EXPECT_EQ(padSoundex("S5"), "S500"); 
    EXPECT_EQ(padSoundex("J525"), "J525");
}

// Entry point for running tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
