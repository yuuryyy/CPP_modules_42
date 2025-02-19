#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include <iostream>

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:

        WrongCat( void );
        WrongCat( const WrongCat &wroong );

        WrongCat &operator=( const WrongCat &wroong );

        void makeSound( void ) const;

         ~WrongCat( void );
};

#endif
