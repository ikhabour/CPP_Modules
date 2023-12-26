#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice& other);
        Ice& operator=(const Ice& other);
        ~Ice();
        std::string const & getType() const;
        AMateria* clone() const;
        void use(ICharacter& target);
};




#endif