#pragma once
#include "../interfaces/INode.h"
#include <iostream>

class Divide : public INode {
    INode *left, *right;
    
    public:
        Divide(INode* l, INode* r);
        void print() override;
        double calc() override;
};
