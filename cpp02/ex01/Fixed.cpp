#include "Fixed.hpp"
#include <iostream>
#include <cmath>

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
    return this->num1;
}

void Fixed::setRawBits(int const raw) {
    this->num1 = raw;
}

Fixed::Fixed(const int val)
{
    this->num1 = val << num2 ;
     std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num)
{
    this->num1 = roundf(num * (1 << num2));
     std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat( void ) const
{
    return(num1 / (float) (1 << num2));
}

int Fixed::toInt( void ) const
{
    return(num1 / (1 << num2));
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();  
    return out;  
}