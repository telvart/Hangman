#include "Hangman.h"
#include <iostream>

Hangman::Hangman(std::string newWord)
  :secretWord(newWord), MAX_MISSES_ALLOWED(7)
{
  missedMarkers = new char[MAX_MISSES_ALLOWED];
  disguisedWord = secretWord;
  guessCount = 0;
  missesCount = 0;
  wordGuessed = false;
  initializeWords();
}

Hangman::~Hangman()
{
  delete[] missedMarkers;
}


bool Hangman::guessCharacter(char c)
{
  guessCount++;
  for(int i=0; i<secretWord.length(); i++)
  {
    if(secretWord[i] == c)
    {
      updateDisguisedWord(c);
      return true;
    }
  }

  updateMissedMarkers();
  missesCount++;
  return false;
}

bool Hangman::guessWord(std::string word)
{
  guessCount++;
  wordGuessed = true;
  if(secretWord == word)
  {
    disguisedWord = word;
    return true;
  }
  return false;
}

bool Hangman::areWordGuessesAllowed()
{
  return !wordGuessed;
}

void Hangman::updateDisguisedWord(char c)
{
  for(int i=0; i<disguisedWord.length(); i++)
  {
    if(secretWord[i] == c)
    {
      disguisedWord[i] = c;
    }
  }
}

void Hangman::updateMissedMarkers()
{
  missedMarkers[missesCount] = 'X';
}

bool Hangman::isGameOver()
{

  if(missesCount == MAX_MISSES_ALLOWED || isFound())
  {
    return true;
  }
  return false;
}

bool Hangman::isFound()
{

  for(int i=0; i<disguisedWord.length(); i++)
  {
    if(disguisedWord[i] == '?')
    {
      return false;
    }
  }
  return true;
}

void Hangman::initializeWords()
{
  //initialize missedMarkers
  for(int i=0; i<MAX_MISSES_ALLOWED; i++)
  {
    missedMarkers[i] = '0';
  }
  //initialize secretWord
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
