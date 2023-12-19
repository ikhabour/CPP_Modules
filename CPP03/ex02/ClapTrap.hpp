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
        int get_HP() const;
        int get_EP() const;
        int get_AD() const;
        std::string getname() const;
        void    setname(std::string name);
        void    set_HP(int hit);
        void    set_AD(int atk);
        void    set_EP(int energy);
        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
};



#endif