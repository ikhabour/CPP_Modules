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
    std::cout<<"ClapTrap Copy constructor called"<<std::endl;
    name = other.name;
    AD = other.AD;
    EP = other.EP;
    HP = other.HP;
}

const ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->HP = other.HP;
        this->AD = other.AD;
        this->EP = other.EP;
        std::cout<<"ClapTrap Copy assignment operator called"<<std::endl;
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout<<"ClapTrap Destructor called"<<std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (EP == 0 || HP == 0)
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
    if (HP == 0)
    {
        std::cout<<"ClapTrap "<<name<<" is already dead"<<std::endl;
        return ;
    }
    if ((int)HP - amount <= 0)
        HP = 0;
    else
        HP -= amount;
    std::cout<<"ClapTrap "<<name<<" lost "<<amount<<" hit points!"<<std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (HP == 0)
    {
        std::cout<<"Cant be repaired , no HP left"<<std::endl;
        return ;
    }
    if (EP == 0)
    {
        std::cout<<"Cant be repaired, no EP left"<<std::endl;
        return ;
    }
    EP--;
    HP += amount;
    std::cout<<"ClapTrap gained "<<amount<<" hit points!"<<std::endl;
}

int ClapTrap::get_AD() const
{
    return AD;
}

int ClapTrap::get_EP() const
{
    return EP;
}

int ClapTrap::get_HP() const
{
    return HP;
}

void    ClapTrap::setname(std::string name)
{
    this->name = name;
}

void    ClapTrap::set_AD(int atk)
{
    this->AD = atk;
}

void    ClapTrap::set_EP(int energy)
{
    this->EP = energy;
}

void    ClapTrap::set_HP(int hit)
{
    this->HP = hit;
}

std::string ClapTrap::getname() const
{
    return this->name;
}