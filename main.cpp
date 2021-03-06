#include <iostream>
#include <string>
#include "GameDriver.h"


std::string getInitialWord(int argc, char* argv[])
{
  std::string initialWord;
  for(int i=1; i<argc; i++)
  {
    if(i != argc-1)
    {
      initialWord = initialWord + argv[i] + " ";
    }
    else
    {
      initialWord = initialWord + argv[i];
    }
  }
  return initialWord;
}


int main(int argc, char* argv[])
{
  if(argc<2)
  {
    std::cout<<"Invalid number of arguments. Minimum of two required\n";
    return 0;
  }


  GameDriver* driver = new GameDriver();
  for(int i=0; i<100; i++)
  {
    std::cout<<"\n";
  }
  driver->run(getInitialWord(argc, argv));
  std::cout<<"Thanks for playing!\n";

  delete driver;

  return 0;

}
