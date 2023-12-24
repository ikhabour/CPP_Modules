#ifndef AMATERIA_HPP
# define AMATERIA_HPP


#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string type;

    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(const AMateria& other);
        AMateria& operator=(const AMateria& other);
        ~AMateria();
        virtual std::string const & getType() const = 0; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};






#endif