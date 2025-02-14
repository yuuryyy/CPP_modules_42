#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap &operator=(const ScavTrap &other  );
        ScavTrap( const ScavTrap &other );
        ScavTrap( std::string name );
        ScavTrap( void );
        ~ScavTrap();

        void guardGate( void );
        void attack( std::string const &target );

};

#endif
