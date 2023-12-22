#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout<<"ScavTrap Default constructor called"<<std::endl;
    this->AD = 20;
    this->EP = 50;
    this->HP = 100;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    std::cout<<"ScavTrap Parameterized constructor called"<<std::endl;
    this->AD = 20;
    this->EP = 50;
    this->HP = 100;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
    std::cout<<"ScavTrap Copy constructor called"<<std::endl;
    *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->AD = other.AD;
        this->HP = other.HP;
        this->EP = other.EP;
        std::cout<<"ScavTrap Copy assignment operator called"<<std::endl;
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout<<"ScavTrap Destructor called"<<std::endl;
}

void    ScavTrap::guardGate()
{
    std::cout<<"ScavTrap "<<this->name<<" is now in Gate keeper mode!"<<std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
    if (this->HP <= 0 || this->EP <= 0)
    {
        std::cout<<"ScavTrap cant attack"<<std::endl;
        return ;
    }
    EP--;
    std::cout<<"ScavTrap "<<this->name<<" attacks "<<target<<" causing "<<this->AD<<" points of damage!"<<std::endl;
}