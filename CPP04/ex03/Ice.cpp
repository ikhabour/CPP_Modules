#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& other) : AMateria(other)
{
    *this = other;
}

Ice& Ice::operator=(const Ice& other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

Ice::~Ice() {}

std::string const & Ice::getType() const
{
    return this->type;
}

AMateria* Ice::clone() const
{
    return (new Ice());
}

void    Ice::use(ICharacter& target)
{
    std::cout<<"Ice: \'* shoots an ice bolt at "<<target.getName()<<" *\'"<<std::endl;
}