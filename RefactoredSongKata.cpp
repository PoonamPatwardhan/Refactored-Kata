#include<iostream>
#include<string>
#include<vector>

using namespace std;
class SongCharacter
{
    public:
        string name;
        string reaction;
        
    SongCharacter(string name, string reaction)
    {
     this->name = name;
     this->reaction =reaction;
    }
};
class Song
{
    private:
    string startingLyrics;
    string endingLyrics;
    std::vector<SongCharacter> characters;
    vector<string> recitation;
    
    public:
    Song(std::string startingLyrics,std::string endingLyrics, std::vector<SongCharacter> characters)
    {
       this->startingLyrics = startingLyrics;
       this->endingLyrics = endingLyrics;
       this->characters = characters;
    }
    
    vector<string> recite()
    {
        int currentCharacter = 0;        
        do
        {
            verse(currentCharacter);
            chorus(currentCharacter);
            currentCharacter++;
        }while (currentCharacter <= characters.size()-1);
        endLyrics();
        return recitation;
    }

    private:
    void verse(int currentCharacter)
    {
        recitation.push_back(startingLyrics + characters[currentCharacter].name);
        reactionLine(currentCharacter);
    }
    
    void chorus(int currentCharacter)
    {
        if (currentCharacter == 0 || currentCharacter == characters.size()-1)
            return;
        
        for(auto i = currentCharacter; i>0; i--)
        {
            recitation.push_back("She swallowed the "+ characters[i].name + " to catch the " + characters[i-1].name);
        }
        recitation.push_back(characters[0].reaction);    
    }
    
    void reactionLine(int currentCharacter)
    {
        recitation.push_back(characters[currentCharacter].reaction);
    }
    
    void endLyrics()
    {
        recitation.push_back(endingLyrics);
    }
};

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();    
}

