#include "GameDriver.h"


void GameDriver::run(std::string newWord)
{
    std::string guess;
    char goAgain = 'X';
    std::string currentWord = newWord;
    bool correctGuess;

    std::cout<<"Welcome to the Hangman Game!\n"
             <<"----------------------------\n\n";

    do
    {
      h = new Hangman(currentWord);
      do
      {

        std::cout<<"Guess this: "<<h->getDisguisedWord()<<"\n";
        std::cout<<"Guesses so far: "<<h->getGuessCount()<<"\n";
        std::cout<<"Missed: "<<h->getMissedMarker()<<"\n";
        std::cout<<"Enter a guess: ";
        std::getline(std::cin, guess);

        if(guess.length() == 1)
        {
          correctGuess = h->guessCharacter(guess[0]);
        }
        else if(guess.length()>1 && guess.length() < currentWord.length())
        {
          std::cout<<"You tried to guess a word but it wasn't the correct length, try again\n\n";
          continue;
        }
        else
        {
          if(h->areWordGuessesAllowed())
          {
            if(h->guessWord(guess))
            {
              break;
            }
          }
          else
          {
            std::cout<<"You've already guessed a word! You cant do that\n\n";
            continue;
          }
        }




        if(correctGuess)
        {
          std::cout<<guess<<" is in the secret word!\n\n";
        }
        else
        {
          std::cout<<guess<<" is not in the secred word. Death draws closer\n\n";
        }
      }
      while(!h->isGameOver());

      std::cout<<"Game Over!\n\n";

      if(h->isFound())
      {
        std::cout<<"Congratulations! You guessed the secret word: "<<currentWord<<" in "<<h->getGuessCount()<<" guesses!\n";
      }

      else
      {
        std::cout<<"You died. Next time, guess as if your life depended on it.\n";
      }

      delete h;
      std::cout<<"Do you want to play again?(y/n)\n";
      std::cin>>goAgain;

      if(goAgain == 'y')
      {
        std::cout<<"Enter a new secret word:\n";
        std::getline(std::cin, currentWord);
      }

    }while(goAgain != 'n');
}


//h->getGuessCount()     *(h).getGuessCount();
