#include <iostream>
#include "DiamondTrap.hpp"


int main()
{
    DiamondTrap a("bob");
    DiamondTrap b;
    
    b = a;

    
    a.attack("someone");
    a.whoAmI();
}