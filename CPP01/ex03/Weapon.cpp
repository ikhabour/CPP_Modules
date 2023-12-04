#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    Weapon::type = type;
}

const std::string& Weapon::getType()
{
    return (type);
}

void    Weapon::setType( std::string type )
{
    Weapon::type = type;
}
