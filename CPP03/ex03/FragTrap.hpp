#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP


#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:

        FragTrap( void );
        FragTrap ( const FragTrap& Other );
        FragTrap ( const std::string& Name );
        FragTrap &operator =( const FragTrap &Other);
        ~FragTrap ( void );

        void highFiveGuys( void );
};



#endif