#include <iostream>
#include <cstring>
void Print(const char* text){
    std::cout << text << std::endl;
}
void PrintError(const char* text){
    std::cerr << text << std::endl;
}
void PrintDebug(const char* text){
    std::cout << text << std::endl;
}