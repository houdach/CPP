#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(nullptr));
    
    Bureaucrat bob("Bob", 50);
    Bureaucrat alice("Alice", 1);
    Bureaucrat john("John", 150);
    Intern huda;

    AForm* shrubbery = huda.makeForm("shrubbery creation", "home");
    AForm* robotomy  = huda.makeForm("robotomy request", "Bender");
    AForm* pardon    = huda.makeForm("presidential pardon", "Marvin");
    AForm* unknown   = huda.makeForm("coffee form", "Kitchen");

    try {
        bob.signForm(*shrubbery);
        bob.executeForm(*shrubbery);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        john.signForm(*robotomy); 
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        alice.signForm(*robotomy);
        alice.executeForm(*robotomy);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        bob.signForm(*pardon);  
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        alice.signForm(*pardon);
        bob.executeForm(*pardon); 
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        alice.executeForm(*pardon);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    
    try
    {
        AForm *robotomy1 = huda.makeForm("shrubbery creation", "home");
        alice.executeForm(*robotomy1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    delete shrubbery;
    delete robotomy;
    delete pardon;
    delete unknown;

    return 0;
}
