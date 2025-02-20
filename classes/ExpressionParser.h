#pragma once
#include "../interfaces/INode.h"
#include <vector>

class ExpressionParser {
    public:
        INode* parse(std::string expression);

    private:
        enum class TokenType { Number, Operator, Bracket, Variable };
        struct Token {
            TokenType type;
            std::string value;
        };

        std::vector<Token> tokenize(std::string expression);
        int precedence(std::string op);
};