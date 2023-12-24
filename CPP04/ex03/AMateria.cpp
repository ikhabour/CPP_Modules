#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout<<"AMateria default constructor called"<<std::endl;
    this->type = "";
}

AMateria::AMateria(std::string const & type)
{
    std::cout<<"AMateria Parameterized constructor called"<<std::endl;
    this->type = type;
}

AMateria::AMateria(const AMateria& other)
{
    std::cout<<"AMateria copy constructor called"<<std::endl;
    *this = other;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other)
    {
        this->type = other.type;
        std::cout<<"AMateria copy assignment operator called"<<std::endl;
    }
    return *this;
}

AMateria::~AMateria()
{
    std::cout<<"AMateria destructor called"<<std::endl;
}
