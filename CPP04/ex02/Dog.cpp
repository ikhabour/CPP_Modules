#include "Dog.hpp"
#include <stdio.h>

Dog::Dog() : Animal()
{
    std::cout<<"Dog default constructor called"<<std::endl;
    this->type = "Dog";
    brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other), brain(NULL)
{
    std::cout<<"Dog copy constructor called"<<std::endl;
    *this = other;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        if (this->brain)
		    delete this->brain;
		this->type = other.type;
		this->brain = new Brain(*(other.brain));
        std::cout<<"Dog copy assignment operator called"<<std::endl;
    }
    return *this;
}

Dog::~Dog()
{
    std::cout<<"Dog destructor called"<<std::endl;
    delete this->brain;
}

void    Dog::makeSound() const
{
    std::cout<<"WOOF WOOF"<<std::endl;
}

std::string    Dog::getType() const
{
    return this->type;
}
