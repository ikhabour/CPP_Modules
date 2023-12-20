#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap() : ClapTrap()
{
    this->HP = FragTrap::HP;
    this->EP = ScavTrap::EP;
    this->AD = FragTrap::AD;
}

DiamondTrap::DiamondTrap(const std::string& Name) : ClapTrap((Name + "_clap_name").c_str())
{
    this->HP = FragTrap::HP;
    this->EP = ScavTrap::EP;
    this->AD = FragTrap::AD;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
{
    std::cout<<"DiamondTrap Copy Constructor called"<<std::endl;
    *this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->EP = other.EP;
        this->HP = other.HP;
        this->AD = other.AD;
        std::cout<<"DiamondTrap Copy assignment operator called"<<std::endl;
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout<<"DiamondTrap Destructor called"<<std::endl;
}

void    DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI()
{
    std::cout<<"Name : "<<this->name<<std::endl;
    std::cout<<"ClapTrap Name : "<<ClapTrap::name<<std::endl;
}