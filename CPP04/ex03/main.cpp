# include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    std::string sep(50, '-');

    std::cout << sep << std::endl;
    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->createMateria("spice");

    std::cout << sep << std::endl;

    ICharacter* me = new Character("MOI");
    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    AMateria *tmp2 = src->createMateria("cure");
    me->equip(tmp2);

    std::cout << sep << std::endl;

    ICharacter* bob = new Character("BOB");

    me->use(0, *bob);
    me->use(1, *bob);

    me->unequip(0);

    std::cout << sep << std::endl;

    delete bob;
    delete tmp;
    delete me;
    delete src;
    return 0;
}