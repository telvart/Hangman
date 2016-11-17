hangman: main.o Hangman.o GameDriver.o
	g++ -g -Wall -std=c++11 -o hangman main.o Hangman.o GameDriver.o
main.o: main.cpp GameDriver.h
	g++ -g -Wall -std=c++11 -c main.cpp
Hangman.o: Hangman.cpp Hangman.h
	g++ -g -Wall -std=c++11 -c Hangman.cpp
GameDriver.o: GameDriver.cpp GameDriver.h Hangman.h
	g++ -g -Wall -std=c++11 -c GameDriver.cpp
clean:
	rm *.o hangman
