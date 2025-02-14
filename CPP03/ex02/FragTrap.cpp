#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap ()
{
    std::cout << "FragTrap default constructor called." << std::endl;
    _name = "FragTrap";
    _hitpoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap( const std::string& Name ) : ClapTrap( Name )
{
    std::cout
}