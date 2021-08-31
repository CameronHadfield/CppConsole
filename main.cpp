#include <cstdlib>
#include <cstring>
#include <vector>
#include "main.h"
#include "logging.h"
#include "formattedprint.h"
#include "carddeck.h"

int main(){
    Print("Welcome, to the console suite. Type 'exit' to exit.");
    while(InputHandler()){}
    return 0;
}

// Helpers
bool InputHandler(){
    // Take input
    std::string strinput;
    std::cout << ">> ";
    std::cin >> strinput;

    const char* input = strinput.c_str();
    //------------------------
    if(StringEqual(input, "exit") || StringEqual(input, "q")){
        Print("Exiting...");
        return false;
    }
    else if(StringEqual(input, "rand")){
        Print("Generating a random number for you now (0-100)");
        float random = rand() % 100000 / 1000;
        std::cout << random << std::endl;
    }
    else if(StringEqual(input, "about")){
        Print("+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+");
        Print("|This program was created by Cameron Hadfield|");
        Print("|       On the 27th of August, 2021          |");
        Print("|   While his girlfriend napped on him       |");
        Print("+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+");
    }
    else if(StringEqual(input, "guess")){
        Print("Let's play a guessing game!");
        Print("Guess what number I am thinking of, from 1 to 10");
        int random = rand() % 10 + 1;
        int guess;
        std::cin >> guess;
        if(guess == random){
            Print("Wow!! You must be smarter than me.");
        }
        else{
            Print("I win this time >:)");
        }
        std::cout << "You guessed " << guess << " and I was thinking of " << random << std::endl;
    }
    else if(StringEqual(input, "card")){
        Print("Getting a random card from the deck");
        Card c = CardDeck::RandomCard();
        std::cout << c.ToString() << std::endl;
    }
    else if(StringEqual(input, "help")){
        Print("Fetching a list of commands for you now!");
        std::vector<std::vector<std::string>> commands = {{"cmd", "desc"},
        { "help", "Print this table" },
        { "rand", "Generate a random number (0-100 inclusive)" },
        { "about", "Gives some info about the program" },
        { "exit", "Quit the program" }
        };
        PrintTable(commands);
    }
    
    else{
        Print("Don't know that command yet");
    }

    return true;
}

bool StringEqual(const char* in, const char* target){

    return (strcmp(in, target) == 0);
}
