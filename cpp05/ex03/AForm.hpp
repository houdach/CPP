#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
    const std::string name;
    bool isSigned;
    const int gradeTosign;
    const int gradeToexecute;

public:
    AForm();
    AForm(const std::string& name, int gradeTosign, int gradeToexecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    std::string getName() const;
    bool getSigned() const;
    int getGradeTosign() const;
    int getGradeToexecute() const;

    void beSigned(const Bureaucrat& b);

    void execute(Bureaucrat const & executor) const;

protected:
    virtual void executeAction(Bureaucrat const & executor) const = 0;

public:
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    class NotSignedException : public std::exception {
    public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif
