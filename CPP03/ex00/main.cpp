#include <iostream>
#include "ClapTrap.hpp"


int main()
{
    ClapTrap clap("trap");
    ClapTrap trap;
    ClapTrap clap1(clap);

    trap = clap;

    std::cout<<"Health : "<<clap.get_HP()<<std::endl;
    std::cout<<"Energy : "<<clap.get_EP()<<std::endl;
    
    clap.attack("clap");
    clap.takeDamage(3);
    std::cout<<"Health : "<<clap.get_HP()<<std::endl;
    std::cout<<"Energy : "<<clap.get_EP()<<std::endl;
    clap.beRepaired(1);
    std::cout<<"Health : "<<clap.get_HP()<<std::endl;
    std::cout<<"Energy : "<<clap.get_EP()<<std::endl;
}