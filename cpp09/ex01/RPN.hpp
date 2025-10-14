#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class RPN
{
private:
    std::stack<int> stack;

    bool isOperator(const std::string &token) const;
    bool isNumber(const std::string &token) const;
    int applyOperator(const std::string &op, int a, int b) const;

public:
    RPN();
    ~RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);

    bool evaluate(const std::string &expression, int &result);
};

#endif
