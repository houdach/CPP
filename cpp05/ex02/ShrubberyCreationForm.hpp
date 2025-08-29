#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {
private:
    std::string target;

public:
    ShrubberyCreationForm(const std::string& target);
    ~ShrubberyCreationForm();

protected:
    void executeAction(Bureaucrat const & executor) const ;
};

#endif
