#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <string>

Intern::Intern() {}

Intern::Intern(const Intern& other) { (void)other; }

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    
    struct FormEntry {
        std::string name;
        AForm* (*create)(const std::string& target);
    };

    static FormEntry forms[] = {
        {"shrubbery creation", [](const std::string& t) -> AForm* { return new ShrubberyCreationForm(t); }},
        {"robotomy request",   [](const std::string& t) -> AForm* { return new RobotomyRequestForm(t); }},
        {"presidential pardon",[](const std::string& t) -> AForm* { return new PresidentialPardonForm(t); }}
    };

    for (size_t i = 0; i < sizeof(forms)/sizeof(FormEntry); i++) {
        if (formName == forms[i].name) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].create(target);
        }
    }

    std::cout << "Intern couldn't find the form named \"" << formName << "\"." << std::endl;
    return nullptr;
}
