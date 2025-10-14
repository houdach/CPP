#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./btc input.txt" << std::endl;
        return 1;
    }

    std::string inputFile = argv[1];
    BitcoinExchange btc;
    
    btc.processInput(inputFile);

    return 0;
}
