#include "ClapTrap.hpp"


ClapTrap::ClapTrap() : HP(10), EP(10), AD(0)
{
    std::cout<<"ClapTrap Default constructor called"<<std::endl;
}


ClapTrap::ClapTrap(std::string name) : HP(10), EP(10), AD(0)
{
    std::cout<<"ClapTrap Parameterized constructor called"<<std::endl;
    this->name = name;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout<<"Copy constructor called"<<std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout<<"Copy assignment operator called"<<std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->HP = other.HP;
        this->AD = other.AD;
        this->EP = other.EP;
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout<<"Destructor called"<<std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (EP <= 0 || HP <= 0)
    {
        std::cout<<"ClapTrap cant Attack"<<std::endl;
        return ;
    }
    EP--;
    std::cout<<"ClapTrap "<<name
    <<" attacks "<<target<<" causing "<<AD<<" points of damage!"<<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (HP <= 0)
    {
        std::cout<<"ClapTrap "<<name<<" is already dead"<<std::endl;
        return ;
    }
    if ((int)(HP - amount) <= 0)
        HP = 0;
    else
        HP -= amount;
    std::cout<<"ClapTrap "<<name<<" lost "<<amount<<" hit points!"<<std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (HP <= 0)
    {
        std::cout<<"Cant be repaired , no HP left"<<std::endl;
        return ;
    }
    if (EP <= 0)
    {
        std::cout<<"Cant be repaired, no EP left"<<std::endl;
        return ;
    }
    EP--;
    HP += amount;
    std::cout<<"ClapTrap gained "<<amount<<" hit points!"<<std::endl;
}

int ClapTrap::get_AD()
{
    return AD;
}

int ClapTrap::get_EP()
{
    return EP;
}

int ClapTrap::get_HP()
{
    return HP;
}