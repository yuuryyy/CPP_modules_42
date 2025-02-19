#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    public:

        Cat( void );
        Cat( const Cat &cat );

        Cat &operator=( const Cat &cat );

        void makeSound( void ) const;

         ~Cat( void );

    private:
             Brain   *_brain;

};

#endif
