#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
class Fixed
{
    private:
    int FixedPointNum;
    static const int FractionalBitsNum;

    public:
    Fixed();
    Fixed(const int val);
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    Fixed (const float num);
    float toFloat( void ) const;
    int toInt( void ) const;
    ~Fixed();
};
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
#endif