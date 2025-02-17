#include "FragTrap.hpp"

FragTrap::
FragTrap( void ) : ClapTrap ()
{
    std::cout << "FragTrap default constructor called." << std::endl;
    _name = "FragTrap";
    _hitpoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::
FragTrap( const std::string& Name ) : ClapTrap( Name )
{
    std::cout << "FragTrap " << Name << " constructor called." << std::endl;
    _name = Name;
    _hitpoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::
FragTrap( const FragTrap& Other ) : ClapTrap( Other )
{
    std::cout << "FragTrap copy constructor called." << std::endl;
    *this = Other;
}

FragTrap& 
FragTrap::operator =( const FragTrap &Other )
{
    std::cout << "FragTrap assignation operator called." << std::endl;
    if (this != &Other)
    {
        _name = Other._name;
        _hitpoints = Other._hitpoints;
        _energyPoints = Other._energyPoints;
        _attackDamage = Other._attackDamage;
    }

    return *this;
}

void FragTrap::
highFiveGuys( void )
{
    if (_energyPoints == 0 || _hitpoints == 0)
    {
        std::cout << "FragTrap " << _name << " can't high five guys." << std::endl;
        return;
    }
    std::cout << "FragTrap " << _name << " says: High five, guys!" << std::endl;
}

FragTrap::~FragTrap( void )
{
    std::cout << "FragTrap destructor called." << std::endl;
}