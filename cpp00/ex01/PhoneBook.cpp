#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    countcontacts = 0;
    index = 0;
}
void PhoneBook::addContact()
{
        if (contacts[index].setContact())
        {
            if (countcontacts < 8)
                countcontacts++;
            index = ( index  + 1) % 8;
        }else
        {
            std::cout<<"all the fields must be filled"<<endl;
        }
}
void PhoneBook::searchContacts()
{
    int i = 0;
    if (countcontacts == 0) {
        std::cout << "No contacts to display." << std::endl;
        return;
    }
    while (i < countcontacts) 
    {
        contacts[i].displaySummary(i);
        i++;
    }
    std::cout << "Enter the index of the contact to view: ";
    
    std::string input;
    std::getline(std::cin, input);

    if (input.length() == 1 && std::isdigit(input[0])) {
        int index = input[0] - '0';

        if (index >= 0 && index < countcontacts) {
            contacts[index].displayFull();
        } else {
            std::cout << "Invalid index. Please enter a number between 0 and "
                      << (countcontacts - 1) << "." << std::endl;
        }
    } else {
        std::cout << "Invalid input. Please enter a digit between 0 and "
                  << (countcontacts - 1) << "." << std::endl;
    }
}