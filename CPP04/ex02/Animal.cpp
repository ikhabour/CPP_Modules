#include "Animal.hpp"

Animal::Animal()
{
    std::cout<<"Animal default constructor called"<<std::endl;
    this->type = "";
}

Animal::Animal(const Animal& other)
{
    std::cout<<"Animal copy constructor called"<<std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
    {
        this->type = other.type;
        std::cout<<"Animal copy assignment operator called"<<std::endl;
    }
    return *this;
}

Animal::~Animal()
{
    std::cout<<"Animal destructor called"<<std::endl;
}