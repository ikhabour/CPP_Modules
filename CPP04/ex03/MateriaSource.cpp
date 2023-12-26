#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        this->materias[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    *this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->materias[i])
                delete this->materias[i];
            this->materias[i] = other.materias[i]->clone();
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->materias[i])
            delete this->materias[i];
    }
}

void    MateriaSource::learnMateria(AMateria *m)
{
    if (!m)
        return ;
    int i = 0;
    while (this->materias[i] && i < 4)
        i++;
    if (i < 4)
        this->materias[i] = m->clone();
    else
        std::cout<<"No space left to learn the materia"<<std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->materias[i]->getType() == type)
            return this->materias[i]->clone();
    }
    std::cout<<"Unknown type"<<std::endl;
    return NULL;
}