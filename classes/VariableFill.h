#pragma once
#include <string>
#include <map>

class VariableFill{
    std::map<std::string, std::string> variables;
    
    public:
        std::string fillVariable(std::string variable);
};
