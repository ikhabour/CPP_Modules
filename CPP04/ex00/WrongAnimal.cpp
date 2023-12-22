#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout<<"WrongAnimal default constructor called"<<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    std::cout<<"WrongAnimal copy constructor called"<<std::endl;
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
    {
        this->type = other.type;
        std::cout<<"WrongAnimal copy assignment operator called"<<std::endl;
    }
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout<<"WrongAnimal destructor called"<<std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}

void    WrongAnimal::makeSound() const
{
    std::cout<<"WrongAnimal Sound"<<std::endl;
}