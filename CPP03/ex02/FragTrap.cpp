#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout<<"FragTrap Default constructor called"<<std::endl;
    this->set_AD(30);
    this->set_HP(100);
    this->set_EP(100);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout<<"FragTrap Parameterized constructor called"<<std::endl;
    this->set_AD(30);
    this->set_HP(100);
    this->set_EP(100);   
}

FragTrap::FragTrap(const FragTrap& other)
{
    std::cout<<"FragTrap Copy constructor called"<<std::endl;
    this->setname(other.getname());
    this->set_AD(other.get_AD());
    this->set_HP(other.get_HP());
    this->set_EP(other.get_EP());
}

const FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
    {
        this->setname(other.getname());
        this->set_AD(other.get_AD());
        this->set_HP(other.get_HP());
        this->set_EP(other.get_EP());
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
    if (this->get_EP() <= 0)
    {
        std::cout<<"FragTrap "<<this->getname()<<" is out of energy"<<std::endl;
        return ;
    }
    this->set_EP(this->get_EP() - 1);
    std::cout<<"FragTrap "<<this->getname()<<"Highfived everyone"<<std::endl;
}