#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
class Fixed
{
    private:
    int num1;
    static const int num2;

    public:
    Fixed();
    Fixed(const Fixed &other);
    Fixed (const float num);
    Fixed(const int val);
    ~Fixed();
    bool &operator=(const Fixed &other);
    bool operator>(const Fixed &other);
    bool operator<(const Fixed &other);
    bool operator>=(const Fixed &other);
    bool operator<=(const Fixed &other);
    bool operator==(const Fixed &other);
    bool operator!=(const Fixed &other);
    //
    Fixed operator+(const Fixed &other);
    Fixed operator-(const Fixed &other);
    Fixed operator*(const Fixed &other);
    Fixed operator/(const Fixed &other);
    //
    Fixed &operator++(); 
    Fixed operator++(int); 
    Fixed &operator--(); 
    Fixed operator--(int);
    //

    int getRawBits( void ) const;
    void setRawBits( int const raw );
    Fixed(const int val);
    Fixed (const float num);
    float toFloat( void ) const;
    int toInt( void ) const;
    static Fixed &min(Fixed &a, Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

};
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
#endif