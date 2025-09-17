#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 40);
        Bureaucrat bob("Bob", 100);

        Form taxForm("Tax Form", 50, 30);
        Form vacationForm("Vacation Form", 120, 100);

        std::cout << alice << std::endl;
        std::cout << bob << std::endl;
        std::cout << taxForm << std::endl;
        std::cout << vacationForm << std::endl;

        alice.signForm(taxForm);       
        bob.signForm(taxForm);         
        bob.signForm(vacationForm);   

        std::cout << taxForm << std::endl;
        std::cout << vacationForm << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
