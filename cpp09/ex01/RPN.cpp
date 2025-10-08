#include "RPN.hpp"
#include <sstream>
#include <cstdlib> 


RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN &other) : _stack(other._stack) {}
RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        _stack = other._stack;
    return *this;
}


bool RPN::isOperator(const std::string &token) const
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}


bool RPN::isNumber(const std::string &token) const
{
    return token.size() == 1 && token[0] >= '0' && token[0] <= '9';
}


int RPN::applyOperator(const std::string &op, int a, int b) const
{
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/")
    {
        if (b == 0)
        {
            std::cerr << "Error: division by zero" << std::endl;
            return 0;
        }
        return a / b;
    }
    return 0; 
}

bool RPN::evaluate(const std::string &expression, int &result)
{
    _stack = std::stack<int>();

    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (isNumber(token))
        {
            _stack.push(atoi(token.c_str()));
        }
        else if (isOperator(token))
        {
            if (_stack.size() < 2)
            {
                std::cerr << "Error" << std::endl;
                return false;
            }
            int b = _stack.top(); _stack.pop();
            int a = _stack.top(); _stack.pop();
            int res = applyOperator(token, a, b);
            _stack.push(res);
        }
        else
        {
            std::cerr << "Error" << std::endl;
            return false;
        }
    }

    if (_stack.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        return false;
    }

    result = _stack.top();
    return true;
}
