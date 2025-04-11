#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
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
