#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    private:

        std::string  _name;
        unsigned int _hitpoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;

    public:

        ClapTrap( void );
        ClapTrap( const std::string &Name );
        ClapTrap( const ClapTrap& Other );

        ClapTrap& operator=( const ClapTrap& Other );

        void attack( const std::string& target );
        void takeDamage( unsigned int amount );
        void beRepaired( unsigned int amount );
        
        ~ClapTrap( void );
};

#endif
