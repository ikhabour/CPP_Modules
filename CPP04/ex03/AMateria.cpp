#include "AMateria.hpp"

AMateria::AMateria()
{
    this->type = "default";
}

AMateria::AMateria(std::string const & type)
{
    this->type = type;
}

AMateria::AMateria(const AMateria& other)
{
    *this = other;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other)
        this->type = other.type;
    return *this;
}

AMateria::~AMateria() {}

void    AMateria::use(ICharacter& target)
{
    (void)target;
    std::cout<<"AMateria cant do anything."<<std::endl;
}
