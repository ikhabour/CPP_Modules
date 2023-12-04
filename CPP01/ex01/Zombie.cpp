#include "Zombie.hpp"

Zombie::Zombie()
{

}

void    Zombie::announce( void )
{
    std::cout<<name<<":  BraiiiiiiinnnzzzZ..."<<std::endl;
}

Zombie::~Zombie()
{
    std::cout<<"Zombie "<<Zombie::name<<" has been destroyed"<<std::endl;
}

void    Zombie::setname(std::string name)
{
    Zombie::name = name;
}