#include <iostream>
#include "ClapTrap.hpp"


int main()
{
    ClapTrap clap("trap");
    ClapTrap trap;
    ClapTrap clap1(clap);

    trap = clap;

    clap.attack("clap");
    clap.takeDamage(3);
    clap.beRepaired(1);
}