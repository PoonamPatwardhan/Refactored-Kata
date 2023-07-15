#include<vector>
#define GTEST_LANG_CXX 1
#include <gtest/gtest.h>
#include "RefactoredSongKata.cpp"


TEST(SongRecitalTests, TestSongRecitalWithNormalLyrics) //good weather scenario
{
    // Arrange
    SongCharacter fly("fly", "I don't know why she swallowed a fly- perhaps she'll die!");
    SongCharacter cat("cat", "Who does that!!");
    SongCharacter dog("dog", "Woah, crazy right ?!");
    SongCharacter horse("horse", "She has crossed the line indeed!");
    std::vector<SongCharacter> songCharacters = {fly, cat, dog, horse};
    Song fancyRyme("There was an old lady who swallowed a ","She's dead, of course!", songCharacters);
    
    vector<string> expectedSongLyrics = {"There was an old lady who swallowed a fly", 
                                        "I don't know why she swallowed a fly- perhaps she'll die!",
                                        "There was an old lady who swallowed a cat",
                                        "Who does that!!",
                                        "She swallowed the cat to catch the fly",
                                        "I don't know why she swallowed a fly- perhaps she'll die!",
                                        "There was an old lady who swallowed a dog",
                                        "Woah, crazy right ?!",
                                        "She swallowed the dog to catch the cat",
                                        "She swallowed the cat to catch the fly",
                                        "I don't know why she swallowed a fly- perhaps she'll die!",
                                        "There was an old lady who swallowed a horse",
                                        "She has crossed the line indeed!",
                                        "She's dead, of course!"};

    //Act
    vector<string> actualSongLyrics = fancyRyme.recite();

    //Assert
    ASSERT_EQ(expectedSongLyrics, actualSongLyrics);
}

TEST(SongRecitalTests, TestSongRecitalWithRandomLyrics) //bad weather secario
{
    // Arrange
    SongCharacter randomCharacter1("ax%", "9999999999999999999999999999999999999999999!");
    SongCharacter randomCharacter2(" ", "       !       ");
    SongCharacter randomCharacter3("0", "Woah&= ........         ?!");
    std::vector<SongCharacter> songCharacters = {randomCharacter1, randomCharacter2, randomCharacter3};
    Song fancyRyme("","   /t ", songCharacters);
    
    vector<string> expectedSongLyrics = {"ax%", 
                                        "9999999999999999999999999999999999999999999!",
                                        " ",
                                        "       !       ",
                                        "She swallowed the   to catch the ax%",
                                        "9999999999999999999999999999999999999999999!",
                                        "0",
                                        "Woah&= ........         ?!",
                                        "   /t "};

    //Act
    vector<string> actualSongLyrics = fancyRyme.recite();

    //Assert
    ASSERT_EQ(expectedSongLyrics, actualSongLyrics);
}
