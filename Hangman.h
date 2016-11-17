#ifndef HANGMAN_H
#define HANGMAN_H
#include <string>
class Hangman
{
  public:
    Hangman(std::string newWord);
    ~Hangman();
    bool guessCharacter(char c);
    bool guessWord(std::string word);
    bool areWordGuessesAllowed();
    bool isGameOver();
    bool isFound();
    std::string getDisguisedWord();
    int getGuessCount();
    int getMissesCount();
    std::string getMissedMarker();

  private:
    const std::string secretWord;
    std::string disguisedWord;
    int disguisedWordSize;
    int guessCount;
    int missesCount;
    const int MAX_MISSES_ALLOWED;
    char* missedMarkers;

    void initializeWords();

    bool wordGuessed;
};

#endif
