#include "Character.hpp"


Character::Character() : ICharacter()
{
    for (int i = 0; i < 4; i++)
        this->slots[i] = 0;
}


Character::Character(std::string name)
{
    this->name = name;
    for (int i = 0; i < 4; i++)
        this->slots[i] = 0;
}

Character::Character(const Character& other)
{
    *this = other;
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        this->name = other.name;
        for (int i = 0; i < 4; i++)
        {
            if (slots[i])
                delete slots[i];
            if (save[i])
                delete save[i];
            slots[i] = other.slots[i]->clone();
            save[i] = other.save[i]->clone();
        }
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->slots[i])
            delete this->slots[i];
        if (this->save[i])
            delete this->save[i];
    }
}

std::string const & Character::getName() const
{
    return this->name;
}

void    Character::equip(AMateria *m)
{
    int i = 0;
    if (!m)
    {
        std::cout<<"Invalid materia"<<std::endl;
        return ;
    }
    while (this->slots[i] != 0 && i < 4)
        i++;
    if (i < 4)
        this->slots[i] = m;
    std::cout<<"Character "<<this->getName()<<" Equipped Materia type "<<m->getType()<<" on slot "<<i<<std::endl;
}

void    Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 || !this->slots[idx])
    {
        std::cout<<"Character "<<this->getName()<<" Cant unequip the materia"<<std::endl;
        return ;
    }
    int i = 0;
    while (save[i])
        i++;
    if (i < 4)
        save[i] = slots[idx];
    slots[idx] = 0;
    std::cout<<"Character "<<this->getName()<<" unequipped Materia type "<<save[i]->getType()<<" from slot "<<idx<<std::endl;
}

void    Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4)
    {
        std::cout<<"Index out of range"<<std::endl;
        return ;
    }
    this->slots[idx]->use(target);
}


