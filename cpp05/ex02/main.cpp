#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
     std::srand(std::time(nullptr));

    Bureaucrat bob("Bob", 50);
    Bureaucrat alice("Alice", 1);
    Bureaucrat john("John", 150);

    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Marvin");

    try {
        bob.signForm(shrubbery);
        bob.executeForm(shrubbery);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        john.signForm(robotomy);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        alice.signForm(robotomy);
        alice.executeForm(robotomy);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        bob.signForm(pardon);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        alice.signForm(pardon);
        bob.executeForm(pardon); 
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        alice.executeForm(pardon);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
    ShrubberyCreationForm tmp("garden");
    alice.executeForm(tmp); 
    } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
}
    return 0;
}
