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
    public:
    string introLine;
    vector<string> lyrics;
    string concludingLine;
};
class SongBuilder
{
    Song song;
    vector<SongCharacter> characters;
    
    public:
    SongBuilder()
    {
        song.introLine = "There was an old lady who swallowed a";
        song.concludingLine = "She's dead, of course!";
    }
    
    SongBuilder addIntroductoryPiece(string introLine = "")
    {
        if (!introLine.empty())
            song.introLine = introLine;
        
        return *this;
    }
    SongBuilder buildStoryWithCharacters(vector<SongCharacter> characters)
    {
        this->characters = characters;
        for (int currentCharacter =0; currentCharacter <= characters.size()-1; currentCharacter++)
        {
             addStoryFor(currentCharacter)
            ->addRecap(currentCharacter);
        }
        return *this;
    }
    
    SongBuilder addConcludingPiece(string concludingLine = "")
    {
        if (!concludingLine.empty())
            song.concludingLine = concludingLine;
            
        song.lyrics.push_back(song.concludingLine);
        return *this;
    }
    
    vector<string> recite()
    {
        return song.lyrics;
    }
    
    private:
    SongBuilder* addStoryFor(int currentCharacter)
    {
        song.lyrics.push_back(song.introLine + " " + characters[currentCharacter].name);
        song.lyrics.push_back(characters[currentCharacter].reaction);
        return this;
    }
    
    void addRecap(int currentCharacter)
    {
        if (currentCharacter == 0 || currentCharacter == characters.size()-1)
            return;
        
        for(auto i = currentCharacter; i>0; i--)
        {
            song.lyrics.push_back("She swallowed the "+ characters[i].name + " to catch the " + characters[i-1].name);
        }
        song.lyrics.push_back(characters[0].reaction);
    }
};

int main()
{
    SongCharacter fly("fly", "I don't know why she swallowed a fly- perhaps she'll die!");
    SongCharacter cat("cat", "Who does that!!");
    SongCharacter dog("dog", "Woah, crazy right ?!");
    SongCharacter horse("horse", "She has crossed the line indeed!");
    std::vector<SongCharacter> songCharacters = {fly, cat, dog, horse};
    
    SongBuilder songNarrator;
    
    auto song = songNarrator
     .addIntroductoryPiece()
     .buildStoryWithCharacters(songCharacters)
     .addConcludingPiece()
     .recite();
             
    int i=0;                                    
    for(auto& lyrics : song)
    {
        std::cout << lyrics << std::endl;
    }
}
