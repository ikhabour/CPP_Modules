#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    weapon = NULL;
    this->name = name;
}

void    HumanB::attack()
{
    if (this->weapon)
        std::cout<<name<<" attacks with their "<<weapon->getType()<<std::endl;
    else
        std::cout<<name<<" doesnt have a weapon."<<std::endl;
}

void    HumanB::setWeapon(Weapon &type)
{
    HumanB::weapon = &type;
}