#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name("ClapTrap"), _hitpoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string Name ) : _name(Name), _hitpoints(10), _energyPoints(10), _attackDamage( 0)
{
    std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap & Other )
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = Other;
}
ClapTrap & ClapTrap::operator=( const ClapTrap & Other )
{
    std::cout << "ClapTrap assignation operator called" << std::endl;
    if (this != &Other)
    {
        this->_name = Other._name;
        this->_hitpoints = Other._hitpoints;
        this->_energyPoints = Other._energyPoints;
        this->_attackDamage = Other._attackDamage;
    }

    return *this;
}

ClapTrap::~ClapTrap( void )
{
    std::cout << "ClapTrap destructor called" << std::endl;

}

void ClapTrap::attack(std::string const & target)
{
    if (this->_energyPoints == 0 || this->_hitpoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " can't attack due to running out of energy/hit points" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints--;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " can't repair due to running out of energy/hit points" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->_name << " is being repaired for " << amount << " points!" << std::endl;
    this->_hitpoints += amount;
    this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitpoints < amount)
    {
        this->_hitpoints = 0;
        this->_energyPoints = 0;
        this->_attackDamage = 0;
        std::cout << "ClapTrap " << this->_name << " died!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
    this->_hitpoints -= amount;
}
