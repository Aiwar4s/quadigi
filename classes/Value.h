#pragma once
#include "../interfaces/INode.h"
#include <iostream>

class Value : public INode {
    double value;
    
    public:
        Value(std::string value);
        void print() override;
        double calc() override;
};
