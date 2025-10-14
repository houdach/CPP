#include "RPN.hpp"
#include <sstream>
#include <cstdlib> 


RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN &other) : stack(other.stack) {}
RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        stack = other.stack;
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
            throw std::runtime_error("Error: division by zero");
        }
        return a / b;
    }
    return 0; 
}

bool RPN::evaluate(const std::string &expression, int &result)
{
    stack = std::stack<int>();

    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (isNumber(token))
        {
            stack.push(atoi(token.c_str()));
        }
        else if (isOperator(token))
        {
            if (stack.size() < 2)
            {
                std::cerr << "Error" << std::endl;
                return false;
            }
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            try {
                int res = applyOperator(token, a, b);
                stack.push(res);
            } 
            catch (const std::exception& e) 
            {
                std::cerr << e.what() << std::endl;
                return false;
            }
        }
        else
        {
            std::cerr << "Error" << std::endl;
            return false;
        }
    }

    if (stack.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        return false;
    }

    result = stack.top();
    return true;
}
