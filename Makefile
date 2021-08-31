PHONY: main

main: main.cpp
	g++ main.cpp logging.h formattedprint.h carddeck.h -g -o main -Wall
