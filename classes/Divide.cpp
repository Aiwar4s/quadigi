#include "Divide.h"

Divide::Divide(INode* l, INode* r) : left(l), right(r) {}

void Divide::print(){
    std::cout << "(";
    left->print();
    std::cout << " / ";
    right->print();
    std::cout << ")";
}

double Divide::calc(){
    return left->calc() / right->calc();
}
