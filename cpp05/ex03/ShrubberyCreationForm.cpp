#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), target("default_target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction(Bureaucrat const & executor) const {
    (void)executor; 
    std::ofstream file(target + "_shrubbery");
    if (!file.is_open()) {
        std::cerr << "Error: could not open file " << target + "_shrubbery" << std::endl;
        return;
    }

    file << "       ^\n";
    file << "      ^^^\n";
    file << "     ^^^^^\n";
    file << "    ^^^^^^^\n";
    file << "      |||\n";
    file << "      |||\n";

    file.close();
}
