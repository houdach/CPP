#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main() {
    PhoneBook phonebook;
    std::string command;

    std::cout << "📞 Welcome to MyContacts! 📞\n";
    std::cout << "-----------------------------------------\n";
    std::cout << "Type one of the following commands:\n\n";
    std::cout << "👉 ADD    - Save a new contact\n";
    std::cout << "👉 SEARCH - Display your saved contacts\n";
    std::cout << "👉 EXIT   - Close the phonebook\n\n";

    while (true) {
        std::cout << "Your command: ";
        std::getline(std::cin, command);

        if (std::cin.eof()) {
            std::cout << "\nEOF detected. Exiting the phonebook.\n";
            break;
        }

        if (command == "ADD") {
            phonebook.addContact();
        } else if (command == "SEARCH") {
            phonebook.searchContacts();
        } else if (command == "EXIT") {
            std::cout << "Goodbye! Your contacts are gone forever 👋\n";
            break;
        } else {
            std::cout << "Unknown command. Please type ADD, SEARCH, or EXIT.\n";
        }
    }
    return 0;
}
