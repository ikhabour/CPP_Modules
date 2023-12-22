#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout<<"FragTrap Default constructor called"<<std::endl;
    this->AD = 30;
    this->HP = 100;
    this->EP = 100;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout<<"FragTrap Parameterized constructor called"<<std::endl;
    this->AD = 30;
    this->HP = 100;
    this->EP = 100;   
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout<<"FragTrap Copy constructor called"<<std::endl;
    *this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
    {
        this->name = other.name;
        ClapTrap::operator=(other);
        std::cout<<"FragTrap Copy assignment operator called"<<std::endl;
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout<<"FragTrap Destructor called"<<std::endl;
}

void    FragTrap::highFiveGuys()
{
    if (this->EP <= 0)
    {
        std::cout<<"FragTrap "<<this->name<<" is out of energy"<<std::endl;
        return ;
    }
    EP--;
    std::cout<<"FragTrap "<<this->name<<"Highfived everyone"<<std::endl;
}