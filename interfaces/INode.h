#pragma once
#include <string>

class INode {
    public:
        virtual void print() = 0;
        virtual double calc() = 0;
        virtual ~INode() {}
};