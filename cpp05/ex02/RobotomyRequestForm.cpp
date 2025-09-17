#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>   
#include <ctime>   

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), target("default_target") 
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) 
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target) 
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other); 
        target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeAction(Bureaucrat const & executor) const {
    (void)executor;
    std::cout << "* Drilling noises *\n";
    if (std::rand() % 2) 
        std::cout << target << " has been robotomized successfully!\n";
    else
        std::cout << "Robotomy failed on " << target << "!\n";
}
