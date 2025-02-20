#pragma once
#include "../interfaces/INode.h"
#include <iostream>

class Sum : public INode {
    INode *left, *right;
    
    public:
        Sum(INode* l, INode* r);
        void print() override;
        double calc() override;
};
