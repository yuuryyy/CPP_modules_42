#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"


class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string _name;

    public:
        DiamondTrap( void);
        DiamondTrap( std::string name );
        DiamondTrap( const DiamondTrap &other );
        DiamondTrap &operator=( const DiamondTrap &other) ;
        ~DiamondTrap( void );

        
        void whoAmI( void );
        void attack( std::string const & target );
};


#endif