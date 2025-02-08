#include "ScavTrap.hpp"

int main( void )
{
    ScavTrap Scavtrap("booo");

    Scavtrap.attack("fooo");
    Scavtrap.takeDamage(5);
    Scavtrap.takeDamage(5);
    Scavtrap.takeDamage(5);
    Scavtrap.beRepaired(5);
    return 0;
}
