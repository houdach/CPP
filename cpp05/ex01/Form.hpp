#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
    const std::string name;
    bool isSigned;
    const int gradeTosign;
    const int gradeToexecute;

public:
    Form();
    Form(const std::string& name, int gradeTosign, int gradeToexecute);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

   
    std::string getName() const;
    bool getSigned() const;
    int getGradeTosign() const;
    int getGradeToexecute() const;

    void beSigned(const Bureaucrat& b); 

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif
