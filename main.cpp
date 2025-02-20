#include <iostream>
#include "interfaces/INode.h"
#include "classes/ExpressionParser.h"

int main(int, char**){
    std::string expression;
    ExpressionParser parser;

    while(true){
        std::cout << "Enter an expression (e to exit): ";
        std::getline(std::cin, expression);
        if(expression == "e"){
            break;
        }
        try
        {
            INode* root = parser.parse(expression);
            root->print();
            std::cout << " = " << root->calc() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}
