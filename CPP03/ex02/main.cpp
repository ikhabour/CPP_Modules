#include <iostream>
#include "FragTrap.hpp"


int main()
{
    FragTrap frag("bob");
    FragTrap trap;
    FragTrap trap1(frag);

    trap = trap1;
    frag.highFiveGuys();
}