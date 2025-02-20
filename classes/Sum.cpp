#include "Sum.h"

Sum::Sum(INode* l, INode* r) : left(l), right(r) {}

void Sum::print(){
    std::cout << "(";
    left->print();
    std::cout << " + ";
    right->print();
    std::cout << ")";
}

double Sum::calc(){
    return left->calc() + right->calc();
}
