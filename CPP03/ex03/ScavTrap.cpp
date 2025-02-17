#include "ScavTrap.hpp"

ScavTrap::
ScavTrap( void ) : ClapTrap()
{
    std::cout << "ScavTrap default constructor called." << std::endl;
    this->_hitpoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::
ScavTrap( const std::string &name ) : ClapTrap(name)
{
    std::cout << "ScavTrap " << name << " constructor called." << std::endl;
    this->_hitpoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::
ScavTrap( const ScavTrap &other ) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = other;
}

ScavTrap& 
ScavTrap::operator=( const ScavTrap &other )
{
    std::cout << "ScavTrap assignation operator called." << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitpoints = other._hitpoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }

    return *this;
}


void 
ScavTrap::guardGate( void )
{
    std::cout << "ScavTrap " << this->_name << " has entered in Gate keeper mode." << std::endl;
}

void 
ScavTrap::attack( std::string const &target )
{
    if (this->_energyPoints == 0 || this->_hitpoints == 0)
    {
        std::cout << "ScavTrap " << this->_name << " can't attack ." << std::endl;
        return;
    }
    std::cout << "ScavTrap " << this->_name << " attacks " << target;
    std::cout << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints--;
}

ScavTrap::
~ScavTrap()
{
    std::cout << "ScavTrap destructor called." << std::endl;
}