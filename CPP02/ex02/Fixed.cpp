#include "Fixed.hpp"



Fixed::Fixed()
{
    // std::cout<<"Default Constructor called"<<std::endl;
    this->value = 0;
}

Fixed::Fixed(const Fixed& other)
{
    // std::cout<<"Copy Constructor Called"<<std::endl;
    if (this != &other)
        *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    // std::cout<<"Copy assignment operator called"<<std::endl;
    if (&other != this)
        this->value = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    // std::cout<<"Destructor Called"<<std::endl;
}

int Fixed::getRawBits( void ) const
{
    // std::cout<<"getRawBits member function called"<<std::endl;
    return (this->value);
}

void Fixed::setRawBits(const int raw)
{
    this->value = raw;
}

Fixed::Fixed(const int number)
{
    // std::cout<<"Int constructor called"<<std::endl;
    this->setRawBits(number << this->bits);
}
Fixed::Fixed(const float number)
{
    // std::cout<<"Float constructor called"<<std::endl;
    int scalingfactor = 1 << this->bits;
    this->setRawBits(roundf(number * scalingfactor));
}

int Fixed::toInt( void ) const
{
    float Intvalue = this->value >> this->bits;
    return (int)roundf(Intvalue);
}

float Fixed::toFloat( void ) const
{
    int scalingfactor = 1 << this->bits;
    return ((float)this->value / scalingfactor);
}

std::ostream&    operator<<(std::ostream &os, const Fixed& obj)
{
    float floatingpoint;
    int scalingfactor = 1 << 8;
    floatingpoint = obj.getRawBits();
    floatingpoint /= scalingfactor;
    os<<floatingpoint;
    return os;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return this->toFloat() != other.toFloat();
}

bool Fixed::operator==(const Fixed& other) const 
{
    return this->toFloat() == other.toFloat();
}

bool Fixed::operator<(const Fixed& other) const
{
    return this->toFloat() < other.toFloat();
}

bool Fixed::operator<=(const Fixed& other) const
{
    return this->toFloat() < other.toFloat();
}

bool Fixed::operator>(const Fixed& other) const
{
    return this->toFloat() > other.toFloat();
}

bool Fixed::operator>=(const Fixed& other) const
{
    return this->toFloat() >= other.toFloat();
}

Fixed& Fixed::operator++()
{
    value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    value++;
    return temp;
}

Fixed& Fixed::operator--()
{
    value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    value--;
    return temp;
}

Fixed Fixed::operator+(const Fixed& other)
{
    Fixed result;
    result = Fixed(this->toFloat() + other.toFloat());
    return result;
}

Fixed Fixed::operator-(const Fixed& other)
{
    Fixed result;
    result = Fixed(this->toFloat() - other.toFloat());
    return result;
}

Fixed Fixed::operator*(const Fixed& other)
{
    Fixed result;
    result = Fixed(this->toFloat() * other.toFloat());
    return result;
}

Fixed Fixed::operator/(const Fixed& other)
{
    Fixed result;
    result = Fixed(this->toFloat() / other.toFloat());
    return result;
}

Fixed& Fixed::min(Fixed& num, Fixed& num2)
{
    if (num < num2)
        return num;
    return num2;
}

const Fixed& Fixed::min(const Fixed& num, const Fixed& num2) 
{
    if (num < num2)
        return num;
    return num2;
}

Fixed& Fixed::max(Fixed& num, Fixed& num2)
{
    if (num > num2)
        return num;
    return num2;
}

const Fixed& Fixed::max(const Fixed& num, const Fixed& num2)
{
    if (num > num2)
        return num;
    return num2;
}