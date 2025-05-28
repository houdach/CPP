#include "Fixed.hpp"
#include <iostream>

const int Fixed::FractionalBitsNum = 8;

Fixed::Fixed() {
    this->FixedPointNum = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    this->FixedPointNum = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->FixedPointNum = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->FixedPointNum;
}

void Fixed::setRawBits(int const raw) {
    this->FixedPointNum = raw;
}
