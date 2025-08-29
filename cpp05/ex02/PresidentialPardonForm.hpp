#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
private:
    std::string target;

public:
    PresidentialPardonForm(const std::string& target);
    ~PresidentialPardonForm();

protected:
    void executeAction(Bureaucrat const & executor) const ;
};

#endif
