#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
    FragTrap fragTrap("FragTrap");
    FragTrap fragTrap2(fragTrap);
    FragTrap fragTrap3 = fragTrap;

    fragTrap.attack("target");
    fragTrap.takeDamage(10);
    fragTrap.beRepaired(5);
    fragTrap.highFiveGuys();

    fragTrap2.attack("target");
    fragTrap2.takeDamage(10);

    fragTrap3.attack("target");
    fragTrap3.takeDamage(10);
    return 0;
}
