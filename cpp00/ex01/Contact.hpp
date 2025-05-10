#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>
#include <iostream>
class Contact
{
    private :
    std::string First_name;
    std::string Last_name;
    std::string Nickname;
    std::string Phone_number;
    std::string Darkest_secret;

    public:
    bool setContact();
    void displaySummary(int index) const;
    void displayFull() const;
};

#endif