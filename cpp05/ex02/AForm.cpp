#include "AForm.hpp"

AForm::AForm()
    : name("DefaultForm"), isSigned(false), gradeTosign(150), gradeToexecute(150) {}

AForm::AForm(const std::string& name, int gradeTosign, int gradeToexecute)
    : name(name), isSigned(false), gradeTosign(gradeTosign), gradeToexecute(gradeToexecute) {
    if (gradeTosign < 1 || gradeToexecute < 1)
        throw GradeTooHighException();
    if (gradeTosign > 150 || gradeToexecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : name(other.name),
      isSigned(other.isSigned),
      gradeTosign(other.gradeTosign),
      gradeToexecute(other.gradeToexecute) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const {
    return name;
}

bool AForm::getSigned() const {
    return isSigned;
}

int AForm::getGradeTosign() const {
    return gradeTosign;
}

int AForm::getGradeToexecute() const {
    return gradeToexecute;
}

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > gradeTosign)
        throw GradeTooLowException();
    isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const {
    if (!isSigned)
        throw NotSignedException();
    if (executor.getGrade() > gradeToexecute)
        throw GradeTooLowException();
    executeAction(executor);
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "AFormException: Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AFormException: Grade too low";
}

const char* AForm::NotSignedException::what() const throw() {
    return "AFormException: Form is not signed";
}

std::ostream& operator<<(std::ostream& out, const AForm& f) {
    out << "Form \"" << f.getName() << "\", signed: " << std::boolalpha << f.getSigned()
        << ", grade to sign: " << f.getGradeTosign()
        << ", grade to execute: " << f.getGradeToexecute();
    return out;
}
