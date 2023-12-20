#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP



#include "ClapTrap.hpp"


class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& other);
        const FragTrap& operator=(const FragTrap& other);
        ~FragTrap();    
        void    highFiveGuys();
};







#endif