#include "Hangman.h"


Hangman::Hangman(std::string newWord)
  :secretWord(newWord), MAX_MISSES_ALLOWED(7)
{
  missedMarkers = new char[MAX_MISSES_ALLOWED];
  initializeWords();
}


Hangman::~Hangman()
{

}

bool Hangman::guessCharacter(char c)
{
  return true;
}

bool Hangman::isGameOver()
{
  return false;
}

bool Hangman::isFound()
{
  return false;
}

void Hangman::initializeWords()
{
  //initialize missedMarkers
  for(int i=0; i<MAX_MISSES_ALLOWED; i++)
  {
    missedMarkers[i] = '0';
  }
  for(int i=0; i<secretWord.length(); i++)
  {
    if(secretWord[i] != ' ')
    {
      disguisedWord[i] = '?';
    }
    else
    {
      disguisedWord[i] = ' ';
    }
  }

}


std::string Hangman::getDisguisedWord()
{
  return disguisedWord;
}

int Hangman::getGuessCount()
{
  return guessCount;
}
int Hangman::getMissesCount()
{
  return missesCount;
}
std::string Hangman::getMissedMarker()
{
  return missedMarkers;
}
