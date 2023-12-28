#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"




int main()
{
    {
		MateriaSource *src = new MateriaSource();
		AMateria *ice = new Ice();
		AMateria *cure = new Cure();
		src->learnMateria(ice);
		src->learnMateria(cure);
		IMateriaSource *clone = new MateriaSource(*src);
		AMateria *tmp = clone->createMateria("nothing");
		delete tmp;
		tmp = clone->createMateria("cure");
		ICharacter *me = new Character("me");
		ICharacter *bob = new Character("bob");
		me->equip(tmp);
        delete tmp;
		me->use(0, *bob);
		// delete tmp; 
		delete me;
		delete bob;
		delete src;
		delete clone;
		delete cure;
		delete ice;
	}
	return 0;
}
