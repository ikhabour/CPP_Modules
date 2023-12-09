#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    private:
        std::string name;
        int HP;
        int EP;
        int AD;
    public:
        ClapTrap();
        ClapTrap( std::string name );
        ClapTrap(const ClapTrap& other);
        const ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();
        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
};



#endif