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

static AForm* createShrubbery(const std::string& t) {
    return new ShrubberyCreationForm(t);
}
static AForm* createRobotomy(const std::string& t) {
    return new RobotomyRequestForm(t);
}
static AForm* createPresidential(const std::string& t) {
    return new PresidentialPardonForm(t);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    struct FormEntry {
        const char* name;
        AForm* (*create)(const std::string&);
    };

    static FormEntry forms[] = {
        { "shrubbery creation",   &createShrubbery },
        { "robotomy request",     &createRobotomy },
        { "presidential pardon",  &createPresidential }
    };

    const size_t n = sizeof(forms) / sizeof(forms[0]);
    for (size_t i = 0; i < n; ++i) {
        if (formName == forms[i].name) {
            std::cout << "Intern creates " << forms[i].name << std::endl;
            return forms[i].create(target);
        }
    }

    std::cerr << "Intern couldn't find the form named \"" << formName << "\"." << std::endl;
    return NULL; 
}