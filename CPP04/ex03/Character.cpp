#include "Character.hpp"


Character::Character() : ICharacter()
{
    for (int i = 0; i < 4; i++)
    {
        this->slots[i] = 0;
        this->save[i] = 0;
    }
    free_index = 0;
}


Character::Character(std::string name)
{
    this->name = name;
    free_index = 0;
    for (int i = 0; i < 4; i++)
    {
        this->slots[i] = 0;
        this->save[i] = 0;
    }
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
        for (int i = 0; i < free_index; i++)
        {
            if (this->save[i])
                delete this->save[i];
        }
        this->free_index = other.free_index;
        for (int i = 0; i < other.free_index; i++)
        {
            this->slots[i] = other.slots[i]->clone();
            this->save[i] = this->slots[i];
        }
        for (int i = free_index; i < 4; i++)
        {
            this->slots[i] = 0;
            this->save[i] = 0;
        }
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
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
    if (!m)
    {
        std::cout<<"Invalid materia"<<std::endl;
        return ;
    }
    if (free_index >= 4)
    {
        std::cout<<"Cant equip : no space left"<<std::endl;
        return ;
    }
    this->slots[free_index] = m->clone();
    delete this->save[free_index];
    this->save[free_index] = this->slots[free_index];
    free_index++;
    std::cout<<"Character "<<this->getName()<<" Equipped Materia type "<<m->getType()<<" on slot "<<free_index - 1<<std::endl;
}

void    Character::unequip(int idx)
{
    if (idx < 0 || idx >= free_index)
    {
        std::cout<<"Character "<<this->getName()<<" Cant unequip the materia"<<std::endl;
        return ;
    }
    for (int i = idx; i < 3; i++)
        this->slots[i] = this->slots[i + 1];
    this->slots[3] = 0;
    free_index--;
    std::cout<<"Character "<<this->getName()<<" unequipped Materia type "<<save[free_index + 1]->getType()<<" from slot "<<idx<<std::endl;
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


