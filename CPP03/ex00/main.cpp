#include "ClapTrap.hpp"

int main( void )
{
    ClapTrap claptrap("booo");
    ClapTrap claptrap2("fooo");
    ClapTrap claptrap3 = claptrap;

    claptrap.attack("fooo");
    claptrap.takeDamage(5);
    claptrap.takeDamage(5);
    claptrap.takeDamage(5);
    claptrap.beRepaired(5);
    return 0;
}
