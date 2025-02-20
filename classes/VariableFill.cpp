#include "VariableFill.h"
#include <iostream>

bool isNumber(std::string str){
    for (char ch : str){
        if (!isdigit(ch) && ch != '.'){
            return false;
        }
    }
    return true;
}

std::string VariableFill::fillVariable(std::string variable){
    std::string value;
    if(variables.find(variable) != variables.end()){
        return variables[variable];
    }

    while (true)
    {
        std::cout << "Enter the value of " << variable << ": ";
        std::getline(std::cin, value);
        if(isNumber(value)){
            break;
        } else{
            std::cout << "Invalid input" << std::endl;
        }
    }
    
    variables[variable] = value;
    return value;
}