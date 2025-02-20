#pragma once
#include "../interfaces/INode.h"
#include <iostream>

class Multiply : public INode {
    INode *left, *right;
    
    public:
        Multiply(INode* l, INode* r);
        void print() override;
        double calc() override;
};
