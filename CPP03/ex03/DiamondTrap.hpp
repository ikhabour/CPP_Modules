#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string name;
    public:
        DiamondTrap();
        DiamondTrap(const std::string& Name);
        DiamondTrap(const DiamondTrap& other);
        DiamondTrap& operator=(const DiamondTrap& other);
        ~DiamondTrap();
        void    attack(const std::string& target);
        void whoAmI();

};





#endif