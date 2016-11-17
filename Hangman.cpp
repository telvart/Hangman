#include "Hangman.h"


Hangman::Hangman(std::string newWord)
  :secretWord(newWord), MAX_MISSES_ALLOWED(7)
{
  //missedMarkers = new char[strlen(newWord)];
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
