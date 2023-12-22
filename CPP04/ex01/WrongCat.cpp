#include "WrongCat.hpp"


WrongCat::WrongCat() : WrongAnimal()
{
    std::cout<<"WrongCat default constructor called"<<std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout<<"WrongCat copy constructor called"<<std::endl;
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
    {
        this->type = other.type;
        std::cout<<"WrongCat copy assignment operator called"<<std::endl;
    }
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout<<"WrongCat destructor called"<<std::endl;
}

void    WrongCat::makeSound() const
{
    std::cout<<"Wrong Meow"<<std::endl;
}