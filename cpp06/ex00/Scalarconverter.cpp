#include "Scalarconverter.hpp"

 ScalarConverter::ScalarConverter()
{
    std::cout << "Default constructor called"<<std::endl;
}
 ScalarConverter::ScalarConverter(std::string input)
{
    this->input = input;
    std::cout << "constructor called"<<std::endl;
}
ScalarConverter::~ScalarConverter()
{
        std::cout << "destructor called"<<std::endl;
}
ScalarConverter:: ScalarConverter (const ScalarConverter &other)
{
    this->input = other.input;
        std::cout << "Copy constructor called"<<std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    if (this != &other)  
        this->input = other.input;
    std::cout << "Assignment operator called" << std::endl;
    return *this;
}

void ScalarConverter::convert(std::string input)
{
    int i = std::stoi(input);
    float f = std::stof(input);
    double d = std::stod(input);

    std::cout << "char: " << static_cast<char>(i) << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}
