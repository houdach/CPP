#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
    : name("default"), isSigned(false), signGrade(150), execGrade(150)
{
    std::cout << "Default constructor called\n";
}

Form::Form(const std::string& name, int signGrade, int execGrade)
    : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
    : name(other.name), isSigned(other.isSigned),
      signGrade(other.signGrade), execGrade(other.execGrade)
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

const std::string& Form::getName() const 
{ 
    return name; 
}

bool Form::getSigned() const 
{ 
    return isSigned; 
}

int Form::getsignGrade() const 
{ 
    return (signGrade);
}

int Form::getGradeToexecute() const
{ 
    return (execGrade); 
}

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > signGrade)
        throw GradeTooLowException();
    isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() 
{
    return "Form : Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() 
{
    return "Form : Grade too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form: " << form.getName()
       << ", signed: " << (form.getSigned() ? "yes" : "no")
       << ", grade required to sign: " << form.getsignGrade()
       << ", grade required to execute: " << form.getGradeToexecute();
    return os;
}
