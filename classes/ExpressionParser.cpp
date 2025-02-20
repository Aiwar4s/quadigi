#include "ExpressionParser.h"
#include "Value.h"
#include "Sum.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Divide.h"
#include "VariableFill.h"
#include <sstream>
#include <stack>

std::vector<ExpressionParser::Token> ExpressionParser::tokenize(std::string expression){
    std::vector<Token> tokens;
    std::stringstream ss(expression);
    std::string temp;

    for (int i = 0; i < expression.size(); i++){
        char ch = expression[i];
        if (ch == ' '){
            continue;
        }
        if (isdigit(ch) || ch == '.' || (ch == '-' && (i == 0 || expression[i - 1] == '('))){
            temp += ch;
        } else {
            if (!temp.empty()){
                tokens.push_back({TokenType::Number, temp});
                temp.clear();
            }
            if(ch == '(' || ch == ')'){
                tokens.push_back({TokenType::Bracket, std::string(1, ch)});
            } else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
                tokens.push_back({TokenType::Operator, std::string(1, ch)});
            } else if(isalpha(ch)){
                if(!tokens.empty() && tokens.back().type == TokenType::Variable){
                    tokens.back().value += ch;
                } else{
                    tokens.push_back({TokenType::Variable, std::string(1, ch)});
                }
            } else{
                throw std::invalid_argument("Invalid expression");
            }
        }
    }

    if(!temp.empty()){
        tokens.push_back({TokenType::Number, temp});
    }

    return tokens;
}

int ExpressionParser::precedence(std::string op){
    if(op == "+" || op == "-"){
        return 1;
    } else if(op == "*" || op == "/"){
        return 2;
    } else{
        return 0;
    }
}

INode* getOperator(std::string op, INode* left, INode* right){
    if(op == "+"){
        return new Sum(left, right);
    } else if(op == "-"){
        return new Subtract(left, right);
    } else if(op == "*"){
        return new Multiply(left, right);
    } else{
        return new Divide(left, right);
    }
}

INode* ExpressionParser::parse(std::string expression){
    std::vector<Token> tokens = tokenize(expression);
    std::stack<INode*> values;
    std::stack<std::string> operators;
    VariableFill vf;

    for(Token token : tokens){
        if(token.type == TokenType::Variable){
            token = {TokenType::Number, vf.fillVariable(token.value)};
        }
        
        if(token.type == TokenType::Number){
            values.push(new Value(token.value));
        } else if(token.type == TokenType::Operator){
            while(!operators.empty() && precedence(operators.top()) >= precedence(token.value)){
                INode* right = values.top(); values.pop();
                INode* left = values.top(); values.pop();
                std::string op = operators.top(); operators.pop();
                values.push(getOperator(op, left, right));
            }
            operators.push(token.value);
        } else if(token.type == TokenType::Bracket){
            if(token.value == "("){
                operators.push(token.value);
            } else{
                while(!operators.empty() && operators.top() != "("){
                    INode* right = values.top(); values.pop();
                    INode* left = values.top(); values.pop();
                    std::string op = operators.top(); operators.pop();
                    values.push(getOperator(op, left, right));
                }
                operators.pop();
            }
        }
    }

    while(!operators.empty()){
        INode* right = values.top(); values.pop();
        INode* left = values.top(); values.pop();
        std::string op = operators.top(); operators.pop();
        values.push(getOperator(op, left, right));
    }

    return values.top();
}