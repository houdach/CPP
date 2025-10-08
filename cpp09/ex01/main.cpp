#include "RPN.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./RPN \"expression\"" << std::endl;
        return 1;
    }

    std::string expr = argv[1];
    RPN rpn;
    int result;

    if (rpn.evaluate(expr, result))
        std::cout << result << std::endl;

    return 0;
}
