#include "Subtract.h"

Subtract::Subtract(INode* l, INode* r) : left(l), right(r) {}

void Subtract::print(){
    std::cout << "(";
    left->print();
    std::cout << " - ";
    right->print();
    std::cout << ")";
}

double Subtract::calc(){
    return left->calc() - right->calc();
}
