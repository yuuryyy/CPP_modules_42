#include "DiamondTrap.hpp"

DiamondTrap::
DiamondTrap( void ) : ClapTrap(), ScavTrap(), FragTrap()
{
    std::cout << "DiamondTrap default constructor called." << std::endl;
    Setter("DiamondTrap");
}

DiamondTrap::
DiamondTrap( const std::string &name ) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
    std::cout << "DiamondTrap " << name << " constructor called." << std::endl;
    Setter(name);
}

DiamondTrap::
DiamondTrap( const DiamondTrap &other ) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
    std::cout << "DiamondTrap copy constructor called." << std::endl;
    *this = other;
}

DiamondTrap& 
DiamondTrap::operator=( const DiamondTrap &other )
{
    std::cout << "DiamondTrap assignation operator called." << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitpoints = other._hitpoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
        ClapTrap::_name = other._name + "_clap_name";
    }

    return *this;
}

void
DiamondTrap::Setter( const std::string &name )
{
    ClapTrap::_name = name + "_clap_name";

    this->_name = name;
    this->_hitpoints = FragTrap::_hitpoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
}

void DiamondTrap::whoAmI( void )
{
    std::cout << "DiamondTrap name is " << this->_name << " and ClapTrap name is " << ClapTrap::_name << std::endl;
}

void DiamondTrap::attack( std::string const &target )
{
    FragTrap::attack(target);
}

DiamondTrap::
~DiamondTrap( void )
{
    std::cout << "DiamondTrap destructor called." << std::endl;
}
