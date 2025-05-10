 #include "Contact.hpp"
#include <iomanip>
 bool Contact::setContact()
    {
        std::cout<<"Enter first name :"<<std::endl;
        std::getline(std::cin, First_name);
        if (First_name.empty())
            return(false);
        std::cout<<"Enter last name :"<<std::endl;
       std::getline(std::cin, Last_name);
        if (Last_name.empty())
            return(false);
        std::cout<<"Enter Nickname :"<<std::endl;
       std::getline(std::cin, Nickname);
        if (Nickname.empty())
            return(false);
        std::cout<<"Enter Phone number :"<<std::endl;
       std::getline(std::cin, Phone_number);
        if (Phone_number.empty())
            return(false);
        std::cout<<"Enter Darkest secret :"<<std::endl;
        std::getline(std::cin, Darkest_secret);
        if (Darkest_secret.empty())
            return(false);
        return (true);
    }
    void Contact::displaySummary(int index) const
    {
        std::cout << "|" << std::setw(10) << index << "|";
        if (First_name.length() > 10)
            std::cout << First_name.substr(0, 9) + ".";
        else
            std::cout << std::setw(10) << First_name;

        std::cout << "|";

        if (Last_name.length() > 10)
            std::cout << Last_name.substr(0, 9) + ".";
        else
            std::cout << std::setw(10) << Last_name;

        std::cout << "|";

        if (Nickname.length() > 10)
            std::cout << Nickname.substr(0, 9) + ".";
        else
            std::cout << std::setw(10) << Nickname;

        std::cout << "|" << std::endl;
    }
    void Contact::displayFull() const
    {
       std::cout<<"First name : "<<First_name<<std::endl;
       std::cout<<"Last name : "<<Last_name<<std::endl;
       std::cout<<"Nickname : "<<Nickname<<std::endl;
       std::cout<<"Phone number : "<<Phone_number<<std::endl;
       std::cout<<"Darkest secret: "<<Darkest_secret<<std::endl;
    }