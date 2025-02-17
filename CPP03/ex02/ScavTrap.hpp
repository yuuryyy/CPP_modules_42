#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:

        ScavTrap( void );
        ScavTrap( const ScavTrap &other );
        ScavTrap( const std::string& name );

        ScavTrap &operator=( const ScavTrap &other );

        void guardGate( void );
        void attack( const std::string &target );

        ~ScavTrap();
};

#endif
