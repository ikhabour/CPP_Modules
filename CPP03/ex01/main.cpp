#include <iostream>
#include "ScavTrap.hpp"


int main()
{
    ScavTrap scav("bob");
    ScavTrap trap1;
    ScavTrap trap(scav);

    trap1 = trap;

    scav.attack("someone");
    scav.takeDamage(2);
    scav.beRepaired(3);
    scav.guardGate();
}