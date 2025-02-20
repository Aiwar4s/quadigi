#include "Value.h"

Value::Value(std::string val) : value(std::stod(val)) {}

void Value::print(){
    std::cout << value;
}

double Value::calc(){
    return value;
}
