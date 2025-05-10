#include "Fixed.hpp"
#include <iostream>

const int Fixed::num2 = 8;

Fixed::Fixed() {
    this->num1 = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    this->num1 = other.getRawBits(); // <-- Important
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->num1 = other.getRawBits(); // <-- Important
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->num1;
}

void Fixed::setRawBits(int const raw) {
    this->num1 = raw;
}
