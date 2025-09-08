#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>

class ScalarConverter
{
    private:
        std::string input;
    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(std::string input);
        ScalarConverter (const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        void convert(std::string input);

};
#endif