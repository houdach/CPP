#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal constructed\n";
}

Animal::Animal(const Animal& other) : type(other.type)
{
    std::cout << "Animal copy constructed\n";
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other)
        type = other.type;
    std::cout << "Animal assigned\n";
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructed\n";
}

std::string Animal::getType() const
{
    return type;
}

