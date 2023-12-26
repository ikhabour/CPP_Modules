#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"




int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp = NULL;
    // std::cout<<me->getName()<<std::endl;


    std::cout<<tmp->getType()<<std::endl;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    // std::cout<<bob->getName()<<std::endl;
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src; 
    return 0;
}
