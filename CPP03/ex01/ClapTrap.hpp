#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    protected:

        std::string  _name;
        unsigned int _hitpoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;

    public:

        ClapTrap( void );
        ClapTrap( const std::string &Name );
        ClapTrap( const ClapTrap& Other );

        ClapTrap& operator=( const ClapTrap& Other );

        void takeDamage( unsigned int amount );
        void beRepaired( unsigned int amount );
        
        virtual void attack( const std::string& target );
        
        virtual ~ClapTrap( void );
};

#endif
