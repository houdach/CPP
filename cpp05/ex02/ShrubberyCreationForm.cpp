#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction(Bureaucrat const & executor) const {
    (void)executor; // unused but required by interface

    std::ofstream file(target + "_shrubbery");
    if (!file.is_open()) {
        std::cerr << "Error: could not open file " << target + "_shrubbery" << std::endl;
        return;
    }

    file << "       🌲\n";
    file << "      🌲🌲\n";
    file << "     🌲🌲🌲\n";
    file << "    🌲🌲🌲🌲\n";
    file << "      |||\n";
    file << "      |||\n";

    file.close();
}
