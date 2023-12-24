#include "Cat.hpp"


Cat::Cat() : Animal()
{
    std::cout<<"Cat default constructor called"<<std::endl;
    this->type = "Cat";
    brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other), brain(NULL)
{
    std::cout<<"Cat copy constructor called"<<std::endl;
    *this = other;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        if (this->brain)
            delete this->brain;
        this->type = other.type;
        this->brain = new Brain(*(other.brain));
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

std::string    Cat::getType() const
{
    return this->type;
}
