#include "Bureaucrat.hpp"

int main() 
{
    try {
        Bureaucrat b1("Alice", 42);
        std::cout << b1 << std::endl;

        b1.incrementGrade();
        std::cout << "After increment: " << b1 << std::endl;

        b1.decrementGrade();
        std::cout << "After decrement: " << b1 << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "--------------------------" << std::endl;


    try {
        Bureaucrat b2("Bob", 151);
        std::cout << b2 << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught while creating Bob: " << e.what() << std::endl;
    }

    std::cout << "--------------------------" << std::endl;


    try {
        Bureaucrat b3("Charlie", 0);
        std::cout << b3 << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught while creating Charlie: " << e.what() << std::endl;
    }

    std::cout << "--------------------------" << std::endl;


    try {
        Bureaucrat b4("Diana", 1);
        std::cout << b4 << std::endl;
        b4.incrementGrade();  
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught while incrementing Diana: " << e.what() << std::endl;
    }

    std::cout << "--------------------------" << std::endl;


    try {
        Bureaucrat b5("Eve", 150);
        std::cout << b5 << std::endl;
        b5.decrementGrade();  
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught while decrementing Eve: " << e.what() << std::endl;
    }

    return 0;
}
