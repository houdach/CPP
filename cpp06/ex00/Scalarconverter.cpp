#include "Scalarconverter.hpp"
#include <cstdlib>
#include <cmath>
#include <limits>
#include <iostream>
#include <iomanip>
#include <cctype>

void ScalarConverter::convert(std::string& input) {
    char c;
    int i;
    float f;
    double d;
    // int precision = 1;

    // Handle pseudo-literals first
    if (input == "nan" || input == "nanf") {
        std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
        return;
    }
    if (input == "+inf" || input == "+inff") {
        std::cout << "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n";
        return;
    }
    if (input == "-inf" || input == "-inff") {
        std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n";
        return;
    }

    try {
        // Single non-digit character
        if (input.size() == 1 && !std::isdigit(input[0])) {
            c = input[0];
            i = static_cast<int>(c);
            f = static_cast<float>(c);
            d = static_cast<double>(c);
        } else {
            // Remove trailing 'f' for float literals
            if (input.back() == 'f') input.pop_back();

            // Validate input: digits, optional sign, at most one dot
            size_t start = (input[0] == '+' || input[0] == '-') ? 1 : 0;
            int dotCount = 0;
            for (size_t j = start; j < input.size(); j++) {
                if (input[j] == '.') dotCount++;
                else if (!std::isdigit(input[j])) throw std::invalid_argument("invalid literal");
            }
            if (dotCount > 1) throw std::invalid_argument("invalid literal");

            // // Determine precision for float/double output
            // size_t dotPos = input.find('.');
            // if (dotPos != std::string::npos) {
            //     precision = input.size() - dotPos - 1;
            //     if (precision > 6) precision = 6; // Limit float precision
            // }

            // Convert to double first
            d = std::stod(input);
            f = static_cast<float>(d);
            i = static_cast<int>(d);
            c = static_cast<char>(i);
        }

        // Char output
        if (d > std::numeric_limits<char>::max() || d < std::numeric_limits<char>::min())
            std::cout << "char: impossible\n";
        else if (std::isprint(c))
            std::cout << "char: '" << c << "'\n";
        else
            std::cout << "char: Non displayable\n";

        // Int output
        if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
            std::cout << "int: impossible\n";
        else
            std::cout << "int: " << i << "\n";

        // Float output
       // Float output
std::cout << std::fixed << std::setprecision(1);
if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max() || std::isnan(f) )
    std::cout << "float: impossible\n";
else
    std::cout << "float: " << f << "f\n";

        // Double output
        if (std::isinf(d))
            std::cout << "double: impossible\n";
        else
            std::cout << "double: " << d << "\n";
    }
    catch (...) {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
    }
}
