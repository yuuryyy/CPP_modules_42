#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:

        Ice( void );
        Ice( const Ice &Other );
        Ice& operator=( const Ice &Other );
        ~Ice( void );

        AMateria* clone( void ) const;
        // virtual void use( ICharacter& target );
};




#endif