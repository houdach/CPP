#include "Fixed.hpp"
#include <iostream>
#include <cmath>

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
    return this->FixedPointNum;
}

void Fixed::setRawBits(int const raw) {
    this->FixedPointNum = raw;
}

Fixed::Fixed(const int val)
{
    this->FixedPointNum = val << FractionalBitsNum ;
     std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num)
{
    this->FixedPointNum = roundf(num * (1 << FractionalBitsNum));
     std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat( void ) const
{
    return(FixedPointNum / (float) (1 << FractionalBitsNum));
}

int Fixed::toInt( void ) const
{
    return(FixedPointNum / (1 << FractionalBitsNum));
}


std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();  
    return out;  
}