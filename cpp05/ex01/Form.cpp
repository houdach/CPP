#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
    : name("default"), isSigned(false), gradeTosign(150), gradeToexecute(150)
{
    std::cout << "Default constructor called\n";
}

Form::Form(const std::string& name, int gradeTosign, int gradeToexecute)
    : name(name), isSigned(false), gradeTosign(gradeTosign), gradeToexecute(gradeToexecute)
{
    if (gradeTosign < 1 || gradeToexecute < 1)
        throw GradeTooHighException();
    if (gradeTosign > 150 || gradeToexecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
    : name(other.name), isSigned(other.isSigned),
      gradeTosign(other.gradeTosign), gradeToexecute(other.gradeToexecute)
{
    std::cout << "Copy constructor called\n";
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    std::cout << "Copy assignment operator called for " << this->name << std::endl;
    return *this;
}

Form::~Form()
{
    std::cout << "destructor called\n";
}

std::string Form::getName() const 
{ 
    return name; 
}

bool Form::getSigned() const 
{ 
    return isSigned; 
}

int Form::getGradeTosign() const 
{ 
    return gradeTosign;
}

int Form::getGradeToexecute() const
{ 
    return gradeToexecute; 
}

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > gradeTosign)
        throw GradeTooLowException();
    isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() 
{
    return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() 
{
    return "Grade too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form: " << form.getName()
       << ", signed: " << (form.getSigned() ? "yes" : "no")
       << ", grade required to sign: " << form.getGradeTosign()
       << ", grade required to execute: " << form.getGradeToexecute();
    return os;
}
