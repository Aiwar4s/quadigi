#include "Multiply.h"

Multiply::Multiply(INode* l, INode* r) : left(l), right(r) {}

void Multiply::print(){
    std::cout << "(";
    left->print();
    std::cout << " * ";
    right->print();
    std::cout << ")";
}

double Multiply::calc(){
    return left->calc() * right->calc();
}
