#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& other) : AMateria(other)
{
    *this = other;
}

Cure& Cure::operator=(const Cure& other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

Cure::~Cure() {}

std::string const & Cure::getType() const
{
    return this->type;
}

AMateria* Cure::clone() const
{
    return (new Cure());
}

void Cure::use(ICharacter& target)
{
    std::cout<<"Cure: \'* heals "<<target.getName()<<"\'s wounds *\'"<<std::endl;
}