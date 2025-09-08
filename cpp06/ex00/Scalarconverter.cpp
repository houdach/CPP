#include "Scalarconverter.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void)other; 
    std::cout << "Copy constructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other; 
    std::cout << "Assignment operator called" << std::endl;
    return *this;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "Destructor called" << std::endl;
}

void ScalarConverter::convert(std::string input) {
    if (input == "nan" || input == "nanf") {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: nanf\n";
        std::cout << "double: nan\n";
        return;
    }
    if (input == "+inf" || input == "+inff") {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: +inff\n";
        std::cout << "double: +inf\n";
        return;
    }
    if (input == "-inf" || input == "-inff") {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: -inff\n";
        std::cout << "double: -inf\n";
        return;
    }

    int i;
    float f;
    double d;
    char c;

    try {
        if (input.size() == 1 && !std::isdigit(input[0])) {
            c = input[0];
            i = static_cast<int>(c);
            f = static_cast<float>(c);
            d = static_cast<double>(c);
        } else {
            i = std::stoi(input);
            f = std::stof(input);
            d = std::stod(input);
            c = static_cast<char>(i);
        }

        if (c < 32 || c > 126)
            std::cout << "char: Non displayable\n";
        else
            std::cout << "char: '" << c << "'\n";

        std::cout << "int: " << i << std::endl;

        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
    }
}
