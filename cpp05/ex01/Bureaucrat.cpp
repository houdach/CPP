 #include "Bureaucrat.hpp"
 #include <exception>
 #include "Form.hpp"

Bureaucrat::Bureaucrat(): name("Default"), grade(150) 
{
    std::cout<<"default constructor has been called"<<std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name)
{
    if(grade < 1 )
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : name(other.name), grade(other.grade)
{
    std::cout << "Copy constructor called for " << name << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other) 
    {
        this->grade = other.grade;
    }
    std::cout << "Copy assignment operator called for " << this->name << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "destructor called "  << std::endl;
}

const std::string& Bureaucrat::getName() const
{
    return(name);
}

int Bureaucrat::getGrade() const
{
    return(grade);
}

void Bureaucrat::incrementGrade()
{
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "BureaucratException : Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "BureaucratException:Grade too low!";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
    out<<b.getName()<<", bureaucrat grade "<<b.getGrade()<<std::endl;
    return out;
}

void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << name << " couldn’t sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

