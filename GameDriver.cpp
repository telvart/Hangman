#include "GameDriver.h"

GameDriver::GameDriver()
{

}

GameDriver::~GameDriver()
{
  delete h;
}



void GameDriver::run(std::string newWord)
{
    h = new Hangman(newWord);
    std::cout<<h->getDisguisedWord();
    std::cout<<"Hello";
}
