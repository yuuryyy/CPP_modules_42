#pragma once
#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
    public:

        Cure( void );
        Cure( const Cure &Other );
        Cure& operator=( const Cure &Other );
        ~Cure( void );

        AMateria* clone( void ) const; 
        void use( ICharacter& target );
};




#endif