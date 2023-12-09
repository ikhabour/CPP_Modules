#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout<<"ScavTrap Default constructor called"<<std::endl;
    this->set_AD(20);
    this->set_EP(50);
    this->set_HP(100);
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    std::cout<<"ScavTrap Parameterized constructor called"<<std::endl;
    this->set_AD(20);
    this->set_EP(50);
    this->set_HP(100);
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
    std::cout<<"ScavTrap Copy constructor called"<<std::endl;
    this->setname(other.getname());
    this->set_AD(other.get_AD());
    this->set_HP(other.get_HP());
    this->set_EP(other.get_EP());
}

const ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        this->setname(other.getname());
        this->set_AD(other.get_AD());
        this->set_HP(other.get_HP());
        this->set_EP(other.get_EP());
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
    std::cout<<"ScavTrap "<<this->getname()<<"is now in Gate keeper mode!"<<std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
    if (!this->get_HP() || !this->get_EP())
    {
        std::cout<<"ScavTrap cant attack"<<std::endl;
        return ;
    }
    this->set_EP(this->get_EP() - 1);
    std::cout<<"ScavTrap "<<this->getname()<<" attacks "<<target<<" causing "<<this->get_AD()<<" points of damage!"<<std::endl;
}