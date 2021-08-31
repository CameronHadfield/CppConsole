#include <iostream>
#include <vector>

void PrintTable(std::vector<std::vector<std::string>> col, bool headers=true){
    if(col.size() == 0){
        return;
    }
    if(headers){
        for(std::string x: col.at(0)){ // the vector that is first
            std::cout << x << "\t";
        }
        std::cout << std::endl << "=========================================" << std::endl;
    }
    if(col.size() == 1){
        return;
    }
    for(long unsigned int a = 1; a < col.size(); ++a){
        for(std::string x: col.at(a)){
            std::cout << x << "\t";
        }
        std::cout << std::endl;
    }

}