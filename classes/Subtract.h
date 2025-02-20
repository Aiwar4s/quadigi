#pragma once
#include "../interfaces/INode.h"
#include <iostream>

class Subtract : public INode {
    INode *left, *right;
    
    public:
        Subtract(INode* l, INode* r);
        void print() override;
        double calc() override;
};
