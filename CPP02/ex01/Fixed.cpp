#include "Fixed.hpp"



Fixed::Fixed()
{
    std::cout<<"Default Constructor called"<<std::endl;
    this->value = 0;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout<<"Copy Constructor Called"<<std::endl;
    this->setRawBits(other.getRawBits());
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout<<"Copy assignment operator called"<<std::endl;
    if (&other != this)
        this->value = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout<<"Destructor Called"<<std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout<<"getRawBits member function called"<<std::endl;
    return (this->value);
}

void Fixed::setRawBits(const int raw)
{
    this->value = raw;
}

Fixed::Fixed(const int number)
{
    this->setRawBits(number << this->bits);
}

Fixed::Fixed(const float number)
{
    int scalingfactor = 1 << this->bits;
    this->setRawBits(roundf(number * scalingfactor));
}

int Fixed::toInt( void ) const
{
    this->value << this->bits;
    roundf(this->value);
    return this->value;
}

float Fixed::toFloat( void ) const
{
    int scalingfactor = 1 << this->bits;
    return (this->value / scalingfactor);
}