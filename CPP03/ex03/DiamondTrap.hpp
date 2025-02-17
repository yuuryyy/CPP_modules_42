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
        DiamondTrap( const std::string &name );
        DiamondTrap( const DiamondTrap &other );
    
        DiamondTrap &operator=( const DiamondTrap &other) ;

        void whoAmI( void );
        void attack( const std::string &target );
        void Setter( const std::string &name );

        ~DiamondTrap( void );
};


#endif