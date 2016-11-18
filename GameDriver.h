#ifndef GAMEDRIVER_H
#define GAMEDRIVER_H
#include <iostream>
#include "Hangman.h"
class GameDriver
{
public:
  GameDriver();
  ~GameDriver();
  void run(std::string newWord);

private:
  Hangman* h;
};

#endif

//
