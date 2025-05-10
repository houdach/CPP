#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp" 
#include <iostream>
using namespace std;
class  PhoneBook
{
    private:
    Contact contacts[8];
    int countcontacts;
    int index;

    public:
    PhoneBook();
    void addContact();
    void searchContacts();
};

#endif