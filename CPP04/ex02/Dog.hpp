#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>

#include "AbstractAnimal.hpp"
#include "Brain.hpp"

class Dog : public AbstractAnimal
{
    public:
            Dog( void );
            Dog( const Dog &dog );

            Dog &operator=( const Dog &dog );

            void makeSound( void ) const;

            ~Dog( void );

    private:
            Brain   *_brain;

};

#endif
