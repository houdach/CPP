#include <iostream>
#include "Fixed.hpp"

int main( void ) {
Fixed a;
std::cout << "Raw fixed-point value of a: " << a.getRawBits() << std::endl;
Fixed const b(10);
std::cout << "Raw fixed-point value of b: " << b.getRawBits() << std::endl;
Fixed const c(42.42f);
std::cout << "Raw fixed-point value of c: " << c.getRawBits() << std::endl;
Fixed const d(b);
std::cout << "Raw fixed-point value of d: " << d.getRawBits() << std::endl;
a = Fixed(1234.4321f);
std::cout << "Raw fixed-point value of a after assignment: " << a.getRawBits() << std::endl;

std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
return 0;
}