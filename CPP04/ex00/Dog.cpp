#include "Dog.hpp"


Dog::Dog() : Animal()
{
    std::cout<<"Dog default constructor called"<<std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout<<"Dog copy constructor called"<<std::endl;
    *this = other;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        this->type = other.type;
        std::cout<<"Dog copy assignment operator called"<<std::endl;
    }
    return *this;
}

Dog::~Dog()
{
    std::cout<<"Dog destructor called"<<std::endl;
}

void    Dog::makeSound() const
{
    std::cout<<"WOOF WOOF"<<std::endl;
}
