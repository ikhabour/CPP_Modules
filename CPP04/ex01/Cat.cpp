#include "Cat.hpp"


Cat::Cat() : Animal()
{
    std::cout<<"Cat default constructor called"<<std::endl;
    this->type = "Cat";
    brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout<<"Cat copy constructor called"<<std::endl;
    *this = other;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        this->type = other.type;
        std::cout<<"Cat copy assignment operator called"<<std::endl;
    }
    return *this;
}

Cat::~Cat()
{
    std::cout<<"Cat destructor called"<<std::endl;
    delete this->brain;
}

void    Cat::makeSound() const
{
    std::cout<<"MEOW MEOW"<<std::endl;
}