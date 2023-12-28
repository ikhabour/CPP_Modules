#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource
{
    private:
        AMateria* materias[4];
        int free_index;
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& other);
        MateriaSource& operator=(const MateriaSource& other);
        ~MateriaSource();
        void learnMateria(AMateria *m);
        AMateria* createMateria(std::string const & type);
};




#endif