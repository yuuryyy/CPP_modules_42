#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    private:
        std::string _name;
        unsigned int _hitpoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;


    public:

        ClapTrap( const ClapTrap & Other );
        ClapTrap( std::string Name );
        ClapTrap & operator=( const ClapTrap & Other );
        ClapTrap( void );
        ~ClapTrap( void );

        void attack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif
