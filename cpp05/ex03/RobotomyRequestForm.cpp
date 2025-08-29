#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>   // For rand()
#include <ctime>     // For time()

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) 
{
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeAction(Bureaucrat const & executor) const {
    (void)executor;

    std::cout << "* Drilling noises *\n";
    if (std::rand() % 2)  // 50% success
        std::cout << target << " has been robotomized successfully!\n";
    else
        std::cout << "Robotomy failed on " << target << "!\n";
}
