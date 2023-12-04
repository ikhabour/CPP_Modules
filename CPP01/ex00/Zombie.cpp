#include "Zombie.hpp"


Zombie::Zombie( std::string name )
{
    Zombie::name = name;
}

void    Zombie::announce( void )
{
    std::cout<<name<<":  BraiiiiiiinnnzzzZ..."<<std::endl;
}

Zombie::~Zombie()
{
    std::cout<<"Zombie "<<Zombie::name<<" has been destroyed"<<std::endl;
}